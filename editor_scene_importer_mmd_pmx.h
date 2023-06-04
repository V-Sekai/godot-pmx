/**************************************************************************/
/*  editor_scene_importer_mmd_pmx.h                                       */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef EDITOR_SCENE_IMPORTER_MMD_PMX_H
#define EDITOR_SCENE_IMPORTER_MMD_PMX_H

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
	void add_vertex(Ref<SurfaceTool> surface, mmd_pmx_t::vertex_t *vertex) const;
	bool is_valid_index(mmd_pmx_t::sized_index_t *index) const;
	String convert_string(const std::string &s, uint8_t encoding) const;
	virtual Node *import_mmd_pmx_scene(const String &p_path, uint32_t p_flags, float p_bake_fps, Ref<PMXMMDState> r_state = Ref<PMXMMDState>());
	String find_file_case_insensitive_recursive(const String &target, const String &path);

public:
	virtual uint32_t get_import_flags() const override;
	virtual void get_extensions(List<String> *r_extensions) const override;
	virtual Node *import_scene(const String &p_path, uint32_t p_flags, const HashMap<StringName, Variant> &p_options,
			List<String> *r_missing_deps = nullptr,
			Error *r_err = nullptr) override;
};

class PMXMMDState : public Resource {
	GDCLASS(PMXMMDState, Resource);
};

#endif // EDITOR_SCENE_IMPORTER_MMD_PMX_H
