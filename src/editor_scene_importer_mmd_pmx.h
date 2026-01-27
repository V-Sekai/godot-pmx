#pragma once

#include <godot_cpp/classes/editor_scene_format_importer.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/classes/surface_tool.hpp>

#include "thirdparty/ksy/mmd_pmx.h"

namespace godot {
class PMXMMDState;
class EditorSceneImporterMMDPMX : public EditorSceneFormatImporter {
	GDCLASS(EditorSceneImporterMMDPMX, EditorSceneFormatImporter);

	const real_t mmd_unit_conversion = 0.079f;
	void add_vertex(const Ref<SurfaceTool> &p_surface, mmd_pmx_t::vertex_t *r_vertex, int32_t p_unused_bone) const;
	bool is_valid_index(mmd_pmx_t::sized_index_t *p_index) const;

	Vector3 pmx_vec3_to_vector3d(const mmd_pmx_t::vec3_t *vector) const;

	static String convert_string(const std::string &p_string, uint8_t p_encoding);
	Node *import_mmd_pmx_scene(const String &p_path, uint32_t p_flags, float p_bake_fps, Ref<PMXMMDState> r_state);

	String find_file_case_insensitive_recursive(const String &p_target, const String &p_path);
	void translate_bones(Skeleton3D *p_skeleton);
	void set_bone_rest_and_parent(Skeleton3D *p_skeleton, int32_t p_bone_id, int32_t p_parent_id);

public:
	[[nodiscard]] PackedStringArray _get_extensions() const override;
	Node *_import_scene(const String &p_path, uint32_t p_flags, const Dictionary &p_options) override;

protected:
	static void _bind_methods();
};

class PMXMMDState : public Resource {
	GDCLASS(PMXMMDState, Resource);

protected:
	static void _bind_methods() {}
};

} //namespace godot