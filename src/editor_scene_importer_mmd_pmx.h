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

class Animation;

#ifdef TOOLS_ENABLED
class EditorSceneImporterMMDPMX : public EditorSceneImporter {
	GDCLASS(EditorSceneImporterMMDPMX, EditorSceneImporter);

public:
	virtual uint32_t get_import_flags() const override;
	virtual void get_extensions(List<String> *r_extensions) const override;
	virtual Node *import_scene(const String &p_path, uint32_t p_flags,
			int p_bake_fps,
			List<String> *r_missing_deps = nullptr,
			Error *r_err = nullptr) override;
	virtual Ref<Animation> import_animation(const String &p_path,
			uint32_t p_flags, int p_bake_fps) override;
};
#endif

class PMXMMDState : public Resource {
	GDCLASS(PMXMMDState, Resource);
	friend class PMXDocument;
	friend class PackedSceneMMDPMX;
};

class PackedSceneMMDPMX : public PackedScene {
	GDCLASS(PackedSceneMMDPMX, PackedScene);

protected:
	static void _bind_methods();

public:
	virtual void save_scene(Node *p_node, const String &p_path, const String &p_src_path,
			uint32_t p_flags, int p_bake_fps,
			List<String> *r_missing_deps, Error *r_err = nullptr);
	virtual Node *import_scene(const String &p_path, uint32_t p_flags,
			int p_bake_fps,
			List<String> *r_missing_deps,
			Error *r_err,
			Ref<PMXMMDState> r_state);
	virtual Node *import_mmd_pmx_scene(const String &p_path, uint32_t p_flags, float p_bake_fps, Ref<PMXMMDState> r_state = Ref<PMXMMDState>());
	virtual void pack_mmd_pmx(String p_path, int32_t p_flags = 0,
			real_t p_bake_fps = 1000.0f, Ref<PMXMMDState> r_state = Ref<PMXMMDState>());
};

#endif // EDITOR_SCENE_IMPORTER_MMD_PMX_H
