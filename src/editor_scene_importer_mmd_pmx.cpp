#include "editor_scene_importer_mmd_pmx.h"
#include <godot_cpp/classes/project_settings.hpp>

#include <godot_cpp/classes/animation_player.hpp>
#include <godot_cpp/classes/dir_access.hpp>
#include <godot_cpp/classes/importer_mesh.hpp>
#include <godot_cpp/classes/importer_mesh_instance3d.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/classes/skin.hpp>
#include <godot_cpp/classes/skin_reference.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>
#include <godot_cpp/classes/static_body3d.hpp>
#include <godot_cpp/classes/texture2d.hpp>

#include <fstream>

#include "thirdparty/ksy/mmd_pmx.h"

namespace godot {
PackedStringArray EditorSceneImporterMMDPMX::_get_extensions() const {
	auto extensions = PackedStringArray();
	extensions.push_back("pmx");
	return extensions;
}

Node *EditorSceneImporterMMDPMX::_import_scene(const String &p_path, uint32_t p_flags, const Dictionary &p_options) {
	Ref<PMXMMDState> state;
	state.instantiate();
	return import_mmd_pmx_scene(p_path, p_flags, static_cast<float>(p_options["animation/fps"]), state);
}

void EditorSceneImporterMMDPMX::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_extensions"), &EditorSceneImporterMMDPMX::_get_extensions);
}

bool EditorSceneImporterMMDPMX::is_valid_index(mmd_pmx_t::sized_index_t *p_index) const {
	ERR_FAIL_NULL_V(p_index, false);
	int64_t bone_index = p_index->value();
	switch (p_index->size()) {
		case 1:
			return bone_index < UINT8_MAX;
		case 2:
			return bone_index < UINT16_MAX;
		// Have to do SOMETHING even if it's not 4
		default:
			return bone_index < UINT32_MAX;
	}
}

Vector3 EditorSceneImporterMMDPMX::pmx_vec3_to_vector3d(const mmd_pmx_t::vec3_t *vector) const {
	return {
		vector->x() * mmd_unit_conversion,
		vector->y() * mmd_unit_conversion,
		vector->z() * mmd_unit_conversion * -1
	};
}

void EditorSceneImporterMMDPMX::add_vertex(
		const Ref<SurfaceTool> &p_surface,
		mmd_pmx_t::vertex_t *r_vertex,
		int32_t p_unused_bone) const {
	ERR_FAIL_COND(p_surface.is_null());
	ERR_FAIL_NULL(r_vertex);
	ERR_FAIL_NULL(r_vertex->normal());
	Vector3 normal = Vector3(r_vertex->normal()->x(),
			r_vertex->normal()->y(),
			r_vertex->normal()->z());
	p_surface->set_normal(normal);
	normal.z = -normal.z;
	ERR_FAIL_NULL(r_vertex->uv());
	Vector2 uv = Vector2(r_vertex->uv()->x(),
			r_vertex->uv()->y());
	p_surface->set_uv(uv);
	ERR_FAIL_NULL(r_vertex->position());
	Vector3 point = pmx_vec3_to_vector3d(r_vertex->position());
	PackedInt32Array bones;
	bones.push_back(p_unused_bone);
	bones.push_back(p_unused_bone);
	bones.push_back(p_unused_bone);
	bones.push_back(p_unused_bone);
	PackedFloat32Array weights;
	weights.push_back(0.0f);
	weights.push_back(0.0f);
	weights.push_back(0.0f);
	weights.push_back(0.0f);
	if (!r_vertex->_is_null_skin_weights()) {
		mmd_pmx_t::bone_type_t bone_type = r_vertex->type();
		switch (bone_type) {
			case mmd_pmx_t::BONE_TYPE_BDEF1: {
				auto *pmx_weights = (mmd_pmx_t::bdef1_weights_t *)r_vertex->skin_weights();
				ERR_FAIL_NULL(pmx_weights);
				if (is_valid_index(pmx_weights->bone_index())) {
					bones[0] = pmx_weights->bone_index()->value();
					weights[0] = 1.0f;
				}
			} break;
			case mmd_pmx_t::BONE_TYPE_BDEF2: {
				auto *pmx_weights = (mmd_pmx_t::bdef2_weights_t *)r_vertex->skin_weights();
				ERR_FAIL_NULL(pmx_weights);
				for (uint32_t count = 0; count < 2; count++) {
					if (is_valid_index(pmx_weights->bone_indices()->at(count).get())) {
						bones[count] = pmx_weights->bone_indices()->at(count)->value();
						weights[count] = pmx_weights->weights()->at(count);
					}
				}
			} break;
			case mmd_pmx_t::BONE_TYPE_BDEF4: {
				auto *pmx_weights = (mmd_pmx_t::bdef4_weights_t *)r_vertex->skin_weights();
				ERR_FAIL_NULL(pmx_weights);
				for (uint32_t count = 0; count < 4; count++) {
					if (is_valid_index(pmx_weights->bone_indices()->at(count).get())) {
						bones[count] = pmx_weights->bone_indices()->at(count)->value();
						weights[count] = pmx_weights->weights()->at(count);
					}
				}
			} break;
			case mmd_pmx_t::BONE_TYPE_SDEF: {
				// SDEF is similar to BDEF2 but with additional parameters for C, R0, and R1 which are not handled here.
				mmd_pmx_t::sdef_weights_t *pmx_weights = static_cast<mmd_pmx_t::sdef_weights_t *>(r_vertex->skin_weights());
				for (uint32_t count = 0; count < 2; count++) {
					if (is_valid_index(pmx_weights->bone_indices()->at(count).get())) {
						bones[count] = pmx_weights->bone_indices()->at(count)->value();
						weights[count] = pmx_weights->weights()->at(count);
					}
				}
			} break;
			case mmd_pmx_t::BONE_TYPE_QDEF: {
				// // QDEF handling could differ and may need special processing not shown here.
				// mmd_pmx_t::qdef_weights_t *pmx_weights = static_cast<mmd_pmx_t::qdef_weights_t *>(r_vertex->skin_weights());
				// for (uint32_t count = 0; count < 4; count++) {
				// 	if (is_valid_index(pmx_weights->bone_indices()->at(count).get())) {
				// 		bones.write[count] = pmx_weights->bone_indices()->at(count)->value();
				// 		weights.write[count] = pmx_weights->weights()->at(count);
				// 	}
				// }
			} break;
		}
		p_surface->set_bones(bones);
		real_t renorm = weights[0] + weights[1] + weights[2] + weights[3];
		if (renorm > CMP_EPSILON && abs(renorm - 1.0) > CMP_EPSILON) {
			for (int i = 0; i < 4; ++i) {
				weights[i] /= renorm;
			}
		}
		p_surface->set_weights(weights);
	}
	p_surface->add_vertex(point);
}

String EditorSceneImporterMMDPMX::convert_string(const std::string &p_string, uint8_t p_encoding) {
	if (!p_string.empty()) {
		auto d_string = PackedByteArray();
		size_t str_len = p_string.size();
		d_string.resize(str_len);
		const char *str_data = p_string.c_str();
		if (str_data != nullptr) {
			memcpy(d_string.ptrw(), str_data, str_len / 2 * sizeof(char16_t));
		}
		if (!p_encoding) {
			return d_string.get_string_from_utf16();
		}
		return d_string.get_string_from_utf8();
	}
	return "";
}

Node *EditorSceneImporterMMDPMX::import_mmd_pmx_scene(const String &p_path, uint32_t p_flags, float p_bake_fps,
		Ref<PMXMMDState> r_state) {
	if (r_state.is_null()) {
		r_state.instantiate();
	}
	std::ifstream ifs(
			ProjectSettings::get_singleton()->globalize_path(p_path).utf8().get_data(), std::ifstream::binary);
	kaitai::kstream ks(&ifs);
	mmd_pmx_t pmx = mmd_pmx_t(&ks);
	Node3D *root = memnew(Node3D);
	std::vector<std::unique_ptr<mmd_pmx_t::bone_t>> *bones = pmx.bones();

	Skeleton3D *skeleton = memnew(Skeleton3D);
	uint32_t bone_count = pmx.bone_count();
	for (uint32_t bone_i = 0; bone_i < bone_count; bone_i++) {
		String japanese_name = convert_string(
				bones->at(bone_i)->name()->value(), pmx.header()->encoding());
		int32_t bone = skeleton->get_bone_count();
		skeleton->add_bone(japanese_name);
		if (!bones->at(bone_i)->enabled()) {
			skeleton->set_bone_enabled(bone, false);
		}
	}

	for (uint32_t bone_i = 0; bone_i < bone_count; bone_i++) {
		Transform3D xform;
		real_t x = bones->at(bone_i)->position()->x() * mmd_unit_conversion;
		real_t y = bones->at(bone_i)->position()->y() * mmd_unit_conversion;
		real_t z = bones->at(bone_i)->position()->z() * mmd_unit_conversion;
		xform.origin = Vector3(x, y, z);

		int32_t parent_index = -1;
		if (is_valid_index(bones->at(bone_i)->parent_index())) {
			parent_index = bones->at(bone_i)->parent_index()->value();
			if (parent_index >= 0 && parent_index < int64_t(bone_count)) {
				real_t parent_x = bones->at(parent_index)->position()->x() * mmd_unit_conversion;
				real_t parent_y = bones->at(parent_index)->position()->y() * mmd_unit_conversion;
				real_t parent_z = bones->at(parent_index)->position()->z() * mmd_unit_conversion;
				xform.origin -= Vector3(parent_x, parent_y, parent_z);
			}
		}
		xform.origin.z = -xform.origin.z;
		skeleton->set_bone_rest(bone_i, xform);
		skeleton->set_bone_pose_position(bone_i, xform.origin);
		if (parent_index >= 0 && parent_index < int64_t(bone_count)) {
			skeleton->set_bone_parent(bone_i, parent_index);
		}
	}

	// Create a root bone at origin to serve as the skeleton root
	skeleton->add_bone("Root");
	int32_t root_bone_id = skeleton->find_bone("Root");

	String unused_bone_name = "UnusedBone";
	skeleton->add_bone(unused_bone_name);
	int32_t unused_bone_index = skeleton->find_bone(unused_bone_name);
	skeleton->set_bone_parent(unused_bone_index, root_bone_id);
	root->add_child(skeleton, true);
	skeleton->set_owner(root);

	std::vector<std::unique_ptr<mmd_pmx_t::material_t>> *materials = pmx.materials();
	Vector<Ref<Texture2D>> texture_cache;
	texture_cache.resize(pmx.texture_count());
	auto r_loader = ResourceLoader::get_singleton();
	for (uint32_t texture_cache_i = 0; texture_cache_i < pmx.texture_count(); texture_cache_i++) {
		std::string raw_texture_path = pmx.textures()->at(texture_cache_i)->name()->value();
		if (raw_texture_path.empty()) {
			continue;
		}
		String texture_path = convert_string(raw_texture_path, pmx.header()->encoding()).simplify_path();
		texture_path = p_path.get_base_dir() + "/" + texture_path;
		print_verbose(vformat("Found texture %s", texture_path));

		Ref<Texture2D> base_color_tex;
		String found_file = find_file_case_insensitive_recursive(texture_path.get_file(),
				texture_path.get_base_dir());
		if (!found_file.is_empty()) {
			base_color_tex = r_loader->load(found_file, "Texture2D");
		}

		ERR_CONTINUE_MSG(base_color_tex.is_null(), vformat("Can't load texture: %s", texture_path));
		texture_cache.write[texture_cache_i] = base_color_tex;
	}

	Vector<Ref<StandardMaterial3D>> material_cache;
	material_cache.resize(pmx.material_count());
	for (uint32_t material_cache_i = 0; material_cache_i < pmx.material_count(); material_cache_i++) {
		Ref<StandardMaterial3D> material;
		material.instantiate();
		int32_t texture_index = materials->at(material_cache_i)->texture_index()->value();
		if (is_valid_index(materials->at(material_cache_i)->texture_index()) && texture_index < texture_cache.size() && !texture_cache[texture_index].is_null()) {
			material->set_texture(StandardMaterial3D::TEXTURE_ALBEDO, texture_cache[texture_index]);
			material->set_transparency(StandardMaterial3D::TRANSPARENCY_ALPHA_DEPTH_PRE_PASS);
		}
		mmd_pmx_t::color4_t *diffuse = materials->at(material_cache_i)->diffuse();
		material->set_albedo(Color(diffuse->r(), diffuse->g(), diffuse->b(), diffuse->a()));
		String material_name = convert_string(materials->at(material_cache_i)->name()->value(),
				pmx.header()->encoding());
		material->set_name(material_name);
		material_cache.write[material_cache_i] = material;
	}

	uint32_t face_start = 0;
	std::vector<std::unique_ptr<mmd_pmx_t::vertex_t>> *vertices = pmx.vertices();

	if (vertices->size()) {
		Ref<ImporterMesh> mesh;
		mesh.instantiate();

		LocalVector<String> blend_shapes;
		for (uint32_t morph_i = 0; morph_i < pmx.morph_count(); ++morph_i) {
			String name = convert_string(pmx.morphs()->at(morph_i)->english_name()->value(),
					pmx.header()->encoding());
			blend_shapes.push_back(name);
			if (pmx.morphs()->at(morph_i)->type() == mmd_pmx_t::MORPH_TYPE_VERTEX) {
				mesh->add_blend_shape(name);
			}
		}
		mesh->set_blend_shape_mode(Mesh::BLEND_SHAPE_MODE_RELATIVE);

		for (uint32_t material_i = 0; material_i < pmx.material_count(); material_i++) {
			Ref<SurfaceTool> surface;
			surface.instantiate();
			surface->begin(Mesh::PRIMITIVE_TRIANGLES);
			std::vector<std::unique_ptr<mmd_pmx_t::face_t>> *faces = pmx.faces();

			if (!faces || !faces->size()) {
				continue;
			}

			uint32_t face_end = face_start + materials->at(material_i)->face_vertex_count() / 3;

			HashMap<uint32_t, Vector<uint32_t>> pmx_to_mesh_idx;

			for (uint32_t face_i = face_start; face_i < face_end; face_i++) {
				if (face_i >= faces->size() || !faces->at(face_i)) {
					continue;
				}

				for (int i = 0; i < 3; i++) {
					auto index_ptr = faces->at(face_i)->indices()->at(i).get();
					if (!is_valid_index(index_ptr)) {
						continue;
					}
					uint32_t index = index_ptr->value();
					if (index >= vertices->size()) {
						continue;
					}
					uint32_t current_index = (face_i - face_start) * 3 + i;
					surface->add_index(current_index);
					add_vertex(surface, vertices->at(index).get(), unused_bone_index);
					if (!pmx_to_mesh_idx.has(index)) {
						pmx_to_mesh_idx[index] = Vector<uint32_t>();
					}
					pmx_to_mesh_idx[index].append(current_index);
				}
			}

			Array mesh_array = surface->commit_to_arrays();
			Ref<Material> material = material_cache[material_i];
			String name;
			if (material.is_valid()) {
				name = material->get_name();
			}

			Array blend_shape_data;

			for (uint32_t bs_i = 0; bs_i < blend_shapes.size(); bs_i++) {
				Array bs_vertex_array;
				Array mesh_vertex_array = mesh_array[Mesh::ARRAY_VERTEX];
				bs_vertex_array.resize(mesh_vertex_array.size());
				auto morph = pmx.morphs()->at(bs_i).get();
				if (morph->type() == mmd_pmx_t::MORPH_TYPE_VERTEX) {
					for (uint32_t morph_vertex_idx = 0; morph_vertex_idx < morph->element_count(); ++morph_vertex_idx) {
						auto vertex_morph = dynamic_cast<mmd_pmx_t::vertex_morph_element_t *>(morph->elements()->at(morph_vertex_idx).get());
						if (!pmx_to_mesh_idx.has(vertex_morph->index()->value())) {
							continue;
						}
						auto vector = pmx_vec3_to_vector3d(vertex_morph->position());

						auto vertex_list = pmx_to_mesh_idx[vertex_morph->index()->value()];
						for (int i = 0; i < vertex_list.size(); ++i) {
							bs_vertex_array[vertex_list[i]] = vector;
						}
					}
					Array current_blend_shape;

					current_blend_shape.resize(Mesh::ARRAY_MAX);
					current_blend_shape[Mesh::ARRAY_VERTEX] = bs_vertex_array;
					current_blend_shape[Mesh::ARRAY_NORMAL] = mesh_array[Mesh::ARRAY_NORMAL];
					current_blend_shape[Mesh::ARRAY_TANGENT] = mesh_array[Mesh::ARRAY_TANGENT];

					blend_shape_data.push_back(current_blend_shape);
				}
			}
			mesh->add_surface(Mesh::PRIMITIVE_TRIANGLES, mesh_array, blend_shape_data, Dictionary(), material, name);
			face_start = face_end;
		}

		ImporterMeshInstance3D *mesh_3d = memnew(ImporterMeshInstance3D);
		skeleton->add_child(mesh_3d, true);
		mesh_3d->set_skin(skeleton->register_skin(skeleton->create_skin_from_rest_transforms())->get_skin());
		mesh_3d->set_mesh(mesh);
		mesh_3d->set_owner(root);
		mesh_3d->set_skeleton_path(mesh_3d->get_path_to(skeleton));
		mesh_3d->set_name("Mesh");
	}

	std::vector<std::unique_ptr<mmd_pmx_t::rigid_body_t>> *rigid_bodies = pmx.rigid_bodies();
	for (uint32_t rigid_bodies_i = 0; rigid_bodies_i < pmx.rigid_body_count(); rigid_bodies_i++) {
		StaticBody3D *static_body_3d = memnew(StaticBody3D);
		String rigid_name = convert_string(rigid_bodies->at(rigid_bodies_i)->name()->value(), pmx.header()->encoding());
		Transform3D xform;
		Basis basis;
		basis.set_euler(Vector3(
				rigid_bodies->at(rigid_bodies_i)->rotation()->x(),
				rigid_bodies->at(rigid_bodies_i)->rotation()->y(),
				-rigid_bodies->at(rigid_bodies_i)->rotation()->z()));
		xform.basis = basis;
		Vector3 point = Vector3(rigid_bodies->at(rigid_bodies_i)->position()->x() * mmd_unit_conversion,
				rigid_bodies->at(rigid_bodies_i)->position()->y() * mmd_unit_conversion,
				-rigid_bodies->at(rigid_bodies_i)->position()->z() * mmd_unit_conversion);
		xform.origin = point;
		static_body_3d->set_transform(xform);
		static_body_3d->set_name(rigid_name);
		root->add_child(static_body_3d, true);
		static_body_3d->set_owner(root);
	}
	return root;
}

String EditorSceneImporterMMDPMX::find_file_case_insensitive_recursive(
		const String &p_target, const String &p_path) {
	String new_path = p_path.simplify_path();
	auto dir = DirAccess::open(new_path);
	if (dir.is_null()) {
		print_error("Failed to open directory: " + new_path);
		return String();
	}

	String target_lower = p_target.to_lower();
	dir->list_dir_begin();
	String file_name = dir->get_next();
	while (!file_name.is_empty()) {
		if (dir->current_is_dir() && file_name != "." && file_name != "..") {
			// Recursively search in subdirectories.
			String sub_path = new_path + "/" + file_name;
			String found_file = find_file_case_insensitive_recursive(p_target, sub_path);
			if (!found_file.is_empty()) {
				dir->list_dir_end();
				return found_file;
			}
		} else if (file_name.to_lower() == target_lower) {
			// Found the file.
			dir->list_dir_end();
			return new_path + "/" + file_name;
		}

		file_name = dir->get_next();
	}

	// File not found.
	dir->list_dir_end();
	return String();
}

void EditorSceneImporterMMDPMX::set_bone_rest_and_parent(Skeleton3D *p_skeleton, int32_t p_bone_id,
		int32_t p_parent_id) {
	ERR_FAIL_NULL(p_skeleton);
	ERR_FAIL_COND(p_bone_id == -1);

	Transform3D bone_global_pose = p_skeleton->get_bone_global_pose(p_bone_id);
	Transform3D new_bone_rest_pose;

	if (p_parent_id != -1) {
		Transform3D parent_global_pose_inverse = p_skeleton->get_bone_global_pose(p_parent_id).affine_inverse();
		new_bone_rest_pose = parent_global_pose_inverse * bone_global_pose;
	} else {
		new_bone_rest_pose = bone_global_pose;
	}

	p_skeleton->set_bone_rest(p_bone_id, new_bone_rest_pose);

	if (p_parent_id != -1) {
		p_skeleton->set_bone_parent(p_bone_id, p_parent_id);
	}
}
} //namespace godot
