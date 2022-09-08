/*************************************************************************/
/*  editor_scene_importer_gltf.h                                         */
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

#ifndef EDITOR_SCENE_IMPORTER_MMX_PMX_H
#define EDITOR_SCENE_IMPORTER_MMX_PMX_H

#include "editor/import/resource_importer_scene.h"
#include "scene/main/node.h"
#include "scene/resources/packed_scene.h"
#include "scene/resources/surface_tool.h"

#include "thirdparty/ksy/mmd_pmx.h"

class Animation;
class PMXMMDState;

class EditorSceneImporterMMDPMX : public EditorSceneFormatImporter {
	GDCLASS(EditorSceneImporterMMDPMX, EditorSceneFormatImporter);

	const real_t mmd_unit_conversion = 0.079f;
	void add_vertex(Ref<SurfaceTool> surface, mmd_pmx_t::vertex_t *vertex) const {
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
	bool is_valid_index(mmd_pmx_t::sized_index_t *index) const;
	String convert_string(const std::string &s, uint8_t encoding) const;
	virtual Node *import_scene(const String &p_path, uint32_t p_flags, const HashMap<StringName, Variant> &p_options, int p_bake_fps, List<String> *r_missing_deps, Error *r_err, Ref<PMXMMDState> r_state);
	virtual Node *import_mmd_pmx_scene(const String &p_path, uint32_t p_flags, float p_bake_fps, Ref<PMXMMDState> r_state = Ref<PMXMMDState>());

public:
	virtual uint32_t get_import_flags() const override;
	virtual void get_extensions(List<String> *r_extensions) const override;
	virtual Node *import_scene(const String &p_path, uint32_t p_flags, const HashMap<StringName, Variant> &p_options,
			int p_bake_fps,
			List<String> *r_missing_deps = nullptr,
			Error *r_err = nullptr) override;
};

class PMXMMDState : public Resource {
	GDCLASS(PMXMMDState, Resource);
};

#endif // EDITOR_SCENE_IMPORTER_MMX_PMX_H
