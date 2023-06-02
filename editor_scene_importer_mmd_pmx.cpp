/*************************************************************************/
/*  editor_scene_importer_mmd_pmx.cpp                                       */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2021 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2021 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "editor_scene_importer_mmd_pmx.h"

#include "core/config/project_settings.h"
#include "core/core_bind.h"
#include "core/templates/local_vector.h"
#include "scene/3d/importer_mesh_instance_3d.h"
#include "scene/3d/mesh_instance_3d.h"
#include "scene/3d/node_3d.h"
#include "scene/3d/physics_body_3d.h"
#include "scene/3d/skeleton_3d.h"
#include "scene/animation/animation_player.h"
#include "scene/resources/animation.h"
#include "scene/resources/importer_mesh.h"
#include "scene/resources/surface_tool.h"

#include <cstdint>
#include <fstream>
#include <string>

#include "thirdparty/ksy/mmd_pmx.h"

uint32_t EditorSceneImporterMMDPMX::get_import_flags() const {
	return IMPORT_SCENE;
}

void EditorSceneImporterMMDPMX::get_extensions(List<String> *r_extensions) const {
	r_extensions->push_back("pmx");
}

Node *EditorSceneImporterMMDPMX::import_scene(const String &p_path, uint32_t p_flags, const HashMap<StringName, Variant> &p_options, List<String> *r_missing_deps, Error *r_err) {
	Ref<PMXMMDState> state;
	state.instantiate();
	return import_mmd_pmx_scene(p_path, p_flags, (float)p_options["animation/fps"], state);
}

bool EditorSceneImporterMMDPMX::is_valid_index(mmd_pmx_t::sized_index_t *index) const {
	ERR_FAIL_NULL_V(index, false);
	int64_t bone_index = index->value();
	switch (index->size()) {
		case 1:
			return bone_index < UINT8_MAX;
		case 2:
			return bone_index < UINT16_MAX;
		// Have to do SOMETHING even if it's not 4
		default:
			return bone_index < UINT32_MAX;
	}
}

void EditorSceneImporterMMDPMX::add_vertex(Ref<SurfaceTool> surface, mmd_pmx_t::vertex_t *vertex) const {
	ERR_FAIL_NULL(surface);
	ERR_FAIL_NULL(vertex);
	ERR_FAIL_NULL(vertex->normal());
	Vector3 normal = Vector3(vertex->normal()->x(),
			vertex->normal()->y(),
			vertex->normal()->z());
	surface->set_normal(normal);
	normal.z = -normal.z;
	ERR_FAIL_NULL(vertex->uv());
	Vector2 uv = Vector2(vertex->uv()->x(),
			vertex->uv()->y());
	surface->set_uv(uv);
	ERR_FAIL_NULL(vertex->position());
	Vector3 point = Vector3(vertex->position()->x() * mmd_unit_conversion,
			vertex->position()->y() * mmd_unit_conversion,
			vertex->position()->z() * mmd_unit_conversion);
	point.z = -point.z;
	PackedInt32Array bones;
	bones.push_back(0);
	bones.push_back(0);
	bones.push_back(0);
	bones.push_back(0);
	PackedFloat32Array weights;
	weights.push_back(0.0f);
	weights.push_back(0.0f);
	weights.push_back(0.0f);
	weights.push_back(0.0f);
	if (!vertex->_is_null_skin_weights()) {
		mmd_pmx_t::bone_type_t bone_type = vertex->type();
		switch (bone_type) {
			case mmd_pmx_t::BONE_TYPE_BDEF1: {
				mmd_pmx_t::bdef1_weights_t *pmx_weights = (mmd_pmx_t::bdef1_weights_t *)vertex->skin_weights();
				ERR_FAIL_NULL(pmx_weights);
				if (is_valid_index(pmx_weights->bone_index())) {
					bones.write[0] = pmx_weights->bone_index()->value();
					weights.write[0] = 1.0f;
				}
			} break;
			case mmd_pmx_t::BONE_TYPE_BDEF2: {
				mmd_pmx_t::bdef2_weights_t *pmx_weights = (mmd_pmx_t::bdef2_weights_t *)vertex->skin_weights();
				ERR_FAIL_NULL(pmx_weights);
				for (uint32_t count = 0; count < 2; count++) {
					if (is_valid_index(pmx_weights->bone_indices()->at(count).get())) {
						bones.write[count] = pmx_weights->bone_indices()->at(count)->value();
						weights.write[count] = pmx_weights->weights()->at(count);
					}
				}
			} break;
			case mmd_pmx_t::BONE_TYPE_BDEF4: {
				mmd_pmx_t::bdef4_weights_t *pmx_weights = (mmd_pmx_t::bdef4_weights_t *)vertex->skin_weights();
				ERR_FAIL_NULL(pmx_weights);
				for (uint32_t count = 0; count < RS::ARRAY_WEIGHTS_SIZE; count++) {
					if (is_valid_index(pmx_weights->bone_indices()->at(count).get())) {
						bones.write[count] = pmx_weights->bone_indices()->at(count)->value();
						weights.write[count] = pmx_weights->weights()->at(count);
					}
				}
			} break;
			case mmd_pmx_t::BONE_TYPE_SDEF: {
				// TODO implement 2021-09-10 fire
				mmd_pmx_t::sdef_weights_t *pmx_weights = (mmd_pmx_t::sdef_weights_t *)vertex->skin_weights();
				ERR_FAIL_NULL(pmx_weights);
				for (uint32_t count = 0; count < 2; count++) {
					if (is_valid_index(pmx_weights->bone_indices()->at(count).get())) {
						bones.write[count] = pmx_weights->bone_indices()->at(count)->value();
						weights.write[count] = pmx_weights->weights()->at(count);
					}
				}
			} break;
			case mmd_pmx_t::BONE_TYPE_QDEF:
			default: {
				// TODO implement 2021-09-10 fire
				mmd_pmx_t::qdef_weights_t *pmx_weights = (mmd_pmx_t::qdef_weights_t *)vertex->skin_weights();
				ERR_FAIL_NULL(pmx_weights);
				ERR_FAIL_NULL(pmx_weights->bone_indices());
				ERR_FAIL_NULL(pmx_weights->weights());
				for (uint32_t count = 0; count < RS::ARRAY_WEIGHTS_SIZE; count++) {
					if (is_valid_index(pmx_weights->bone_indices()->at(count).get())) {
						ERR_FAIL_NULL(pmx_weights->bone_indices()->at(count).get());
						bones.write[count] = pmx_weights->bone_indices()->at(count)->value();
						std::vector<float> *weight = pmx_weights->weights();
						ERR_FAIL_NULL(weight);
						weights.write[count] = weight->at(count);
					}
				}
			} break;
		}
		surface->set_bones(bones);
		real_t renorm = weights[0] + weights[1] + weights[2] + weights[3];
		if (renorm != 0.0 && renorm != 1.0) {
			weights.write[0] /= renorm;
			weights.write[1] /= renorm;
			weights.write[2] /= renorm;
			weights.write[3] /= renorm;
		}
		surface->set_weights(weights);
		surface->add_vertex(point);
	}
}

String EditorSceneImporterMMDPMX::convert_string(const std::string &s, uint8_t encoding) const {
	String output;
	if (encoding == 0) {
		Vector<char16_t> buf;
		buf.resize(s.length() / 2);
		memcpy(buf.ptrw(), s.c_str(), s.length() / 2 * sizeof(char16_t));
		output.parse_utf16(buf.ptr(), buf.size());
	} else {
		output.parse_utf8(s.data(), s.length());
	}
	return output;
}

Node *EditorSceneImporterMMDPMX::import_mmd_pmx_scene(const String &p_path, uint32_t p_flags, float p_bake_fps, Ref<PMXMMDState> r_state) {
	if (r_state == Ref<PMXMMDState>()) {
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
		String output_name = convert_string(
				bones->at(bone_i)->name()->value(), pmx.header()->encoding());
		int32_t bone = skeleton->get_bone_count();
		skeleton->add_bone(output_name);
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

		BoneId parent_index = -1;
		if (is_valid_index(bones->at(bone_i)->parent_index())) {
			parent_index = bones->at(bone_i)->parent_index()->value();
			real_t parent_x = bones->at(parent_index)->position()->x() * mmd_unit_conversion;
			real_t parent_y = bones->at(parent_index)->position()->y() * mmd_unit_conversion;
			real_t parent_z = bones->at(parent_index)->position()->z() * mmd_unit_conversion;
			xform.origin -= Vector3(parent_x, parent_y, parent_z);
		}
		xform.origin.z = -xform.origin.z;
		skeleton->set_bone_rest(bone_i, xform);
		skeleton->set_bone_pose_position(bone_i, xform.origin);
		skeleton->set_bone_parent(bone_i, parent_index);
	}

	root->add_child(skeleton, true);
	skeleton->set_owner(root);

	std::vector<std::unique_ptr<mmd_pmx_t::material_t>> *materials = pmx.materials();
	Vector<Ref<Texture2D>> texture_cache;
	texture_cache.resize(pmx.texture_count());

	for (uint32_t texture_cache_i = 0; texture_cache_i < pmx.texture_count(); texture_cache_i++) {
		std::string raw_texture_path = pmx.textures()->at(texture_cache_i)->name()->value();
		if (raw_texture_path.empty()) {
			continue;
		}
		String texture_path = convert_string(raw_texture_path, pmx.header()->encoding()).strip_escapes().strip_edges().simplify_path();
		texture_path = p_path.get_base_dir() + "/" + texture_path;
		print_verbose(vformat("Found texture %s", texture_path));

		Ref<Texture2D> base_color_tex = ResourceLoader::load(texture_path, "Texture2D");

		// If the texture is not found, try loading it with the lowercase path.
		if (base_color_tex.is_null()) {
			String lower_case_texture_path = texture_path.to_lower();
			base_color_tex = ResourceLoader::load(lower_case_texture_path, "Texture2D");
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
		}
		mmd_pmx_t::color4_t *diffuse = materials->at(material_cache_i)->diffuse();
		material->set_albedo(Color(diffuse->r(), diffuse->g(), diffuse->b(), diffuse->a()));
		String material_name = convert_string(materials->at(material_cache_i)->name()->value(), pmx.header()->encoding());
		material->set_name(material_name);
		material_cache.write[material_cache_i] = material;
	}

	uint32_t face_start = 0;
	std::vector<std::unique_ptr<mmd_pmx_t::vertex_t>> *vertices = pmx.vertices();
	if (vertices->size()) {
		Ref<ImporterMesh> mesh;
		mesh.instantiate();
		for (uint32_t material_i = 0; material_i < pmx.material_count(); material_i++) {
			Ref<SurfaceTool> surface;
			surface.instantiate();
			surface->begin(Mesh::PRIMITIVE_TRIANGLES);
			std::vector<std::unique_ptr<mmd_pmx_t::face_t>> *faces = pmx.faces();
			if (!faces || !faces->size()) {
				continue;
			}
			uint32_t face_end = face_start + materials->at(material_i)->face_vertex_count() / 3;

			// Add the vertices directly without indices
			for (uint32_t face_i = face_start; face_i < face_end; face_i++) {
				if (face_i >= faces->size() || !faces->at(face_i).get()) {
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
					add_vertex(surface, vertices->at(index).get());
				}
			}

			Array mesh_array = surface->commit_to_arrays();
			Ref<Material> material = material_cache[material_i];
			String name;
			if (material.is_valid()) {
				name = material->get_name();
			}

			Array blend_shape_data;

			// for (int morph_i = 0; morph_i < pmx.morph_count(); ++morph_i) {
			// 	Array mesh_array;
			// 	mesh_array.resize(ArrayMesh::ARRAY_MAX);
			// 	Vector<Vector3> blend_vertices;
			// 	Vector<Vector3> blend_normals;
			// 	Vector<Plane> blend_tangents;
			// 	for (const auto& vertex : pmx.morphs()->at(morph_i).get() vertices) {
			// 		blend_vertices.push_back(vertex.position);
			// 		blend_normals.push_back(vertex.normal);
			// 		blend_tangents.push_back(Plane(vertex.tangent));
			// 	}
			// 	mesh_array[Mesh::ARRAY_VERTEX] = blend_vertices;
			// 	mesh_array[Mesh::ARRAY_NORMAL] = blend_normals;
			// 	mesh_array[Mesh::ARRAY_TANGENT] = blend_tangents;
			// }

			mesh->add_surface(Mesh::PRIMITIVE_TRIANGLES, mesh_array, blend_shape_data, Dictionary(), material, name);
			face_start = face_end;
			ImporterMeshInstance3D *mesh_3d = memnew(ImporterMeshInstance3D);
			skeleton->add_child(mesh_3d, true);
			mesh_3d->set_skin(skeleton->register_skin(skeleton->create_skin_from_rest_transforms())->get_skin());
			mesh_3d->set_mesh(mesh);
			mesh_3d->set_owner(root);
			mesh_3d->set_skeleton_path(mesh_3d->get_path_to(skeleton));
			mesh_3d->set_name(name);
		}

		LocalVector<String> blend_shapes;
		for (int morph_i = 0; morph_i < pmx.morph_count(); ++morph_i) {
			String name = convert_string(
					pmx.morphs()->at(morph_i).get()->english_name()->value(), pmx.header()->encoding());
			blend_shapes.push_back(name);
		}
		for (const String &blend_shape : blend_shapes) {
			mesh->add_blend_shape(blend_shape);
		}
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
