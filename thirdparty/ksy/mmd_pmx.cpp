// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "mmd_pmx.h"
#include "kaitai/exceptions.h"

mmd_pmx_t::mmd_pmx_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_header = nullptr;
    m_vertices = nullptr;
    m_faces = nullptr;
    m_textures = nullptr;
    m_materials = nullptr;
    m_bones = nullptr;
    m_morphs = nullptr;
    m_frames = nullptr;
    m_rigid_bodies = nullptr;
    m_joints = nullptr;
    _read();
}

void mmd_pmx_t::_read() {
    m_header = std::unique_ptr<header_t>(new header_t(m__io, this, m__root));
    m_vertex_count = m__io->read_u4le();
    int l_vertices = vertex_count();
    m_vertices = std::unique_ptr<std::vector<std::unique_ptr<vertex_t>>>(new std::vector<std::unique_ptr<vertex_t>>());
    m_vertices->reserve(l_vertices);
    for (int i = 0; i < l_vertices; i++) {
        m_vertices->push_back(std::move(std::unique_ptr<vertex_t>(new vertex_t(m__io, this, m__root))));
    }
    m_face_vertex_count = m__io->read_u4le();
    int l_faces = (face_vertex_count() / 3);
    m_faces = std::unique_ptr<std::vector<std::unique_ptr<face_t>>>(new std::vector<std::unique_ptr<face_t>>());
    m_faces->reserve(l_faces);
    for (int i = 0; i < l_faces; i++) {
        m_faces->push_back(std::move(std::unique_ptr<face_t>(new face_t(m__io, this, m__root))));
    }
    m_texture_count = m__io->read_u4le();
    int l_textures = texture_count();
    m_textures = std::unique_ptr<std::vector<std::unique_ptr<texture_t>>>(new std::vector<std::unique_ptr<texture_t>>());
    m_textures->reserve(l_textures);
    for (int i = 0; i < l_textures; i++) {
        m_textures->push_back(std::move(std::unique_ptr<texture_t>(new texture_t(m__io, this, m__root))));
    }
    m_material_count = m__io->read_u4le();
    int l_materials = material_count();
    m_materials = std::unique_ptr<std::vector<std::unique_ptr<material_t>>>(new std::vector<std::unique_ptr<material_t>>());
    m_materials->reserve(l_materials);
    for (int i = 0; i < l_materials; i++) {
        m_materials->push_back(std::move(std::unique_ptr<material_t>(new material_t(m__io, this, m__root))));
    }
    m_bone_count = m__io->read_u4le();
    int l_bones = bone_count();
    m_bones = std::unique_ptr<std::vector<std::unique_ptr<bone_t>>>(new std::vector<std::unique_ptr<bone_t>>());
    m_bones->reserve(l_bones);
    for (int i = 0; i < l_bones; i++) {
        m_bones->push_back(std::move(std::unique_ptr<bone_t>(new bone_t(m__io, this, m__root))));
    }
    m_morph_count = m__io->read_u4le();
    int l_morphs = morph_count();
    m_morphs = std::unique_ptr<std::vector<std::unique_ptr<morph_t>>>(new std::vector<std::unique_ptr<morph_t>>());
    m_morphs->reserve(l_morphs);
    for (int i = 0; i < l_morphs; i++) {
        m_morphs->push_back(std::move(std::unique_ptr<morph_t>(new morph_t(m__io, this, m__root))));
    }
    m_frame_count = m__io->read_u4le();
    int l_frames = frame_count();
    m_frames = std::unique_ptr<std::vector<std::unique_ptr<frame_t>>>(new std::vector<std::unique_ptr<frame_t>>());
    m_frames->reserve(l_frames);
    for (int i = 0; i < l_frames; i++) {
        m_frames->push_back(std::move(std::unique_ptr<frame_t>(new frame_t(m__io, this, m__root))));
    }
    m_rigid_body_count = m__io->read_u4le();
    int l_rigid_bodies = rigid_body_count();
    m_rigid_bodies = std::unique_ptr<std::vector<std::unique_ptr<rigid_body_t>>>(new std::vector<std::unique_ptr<rigid_body_t>>());
    m_rigid_bodies->reserve(l_rigid_bodies);
    for (int i = 0; i < l_rigid_bodies; i++) {
        m_rigid_bodies->push_back(std::move(std::unique_ptr<rigid_body_t>(new rigid_body_t(m__io, this, m__root))));
    }
    m_joint_count = m__io->read_u4le();
    int l_joints = joint_count();
    m_joints = std::unique_ptr<std::vector<std::unique_ptr<joint_t>>>(new std::vector<std::unique_ptr<joint_t>>());
    m_joints->reserve(l_joints);
    for (int i = 0; i < l_joints; i++) {
        m_joints->push_back(std::move(std::unique_ptr<joint_t>(new joint_t(m__io, this, m__root))));
    }
}

mmd_pmx_t::~mmd_pmx_t() {
    _clean_up();
}

void mmd_pmx_t::_clean_up() {
}

mmd_pmx_t::bone_ik_link_t::bone_ik_link_t(kaitai::kstream* p__io, mmd_pmx_t::bone_ik_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_index = nullptr;
    m_lower_limitation_angle = nullptr;
    m_upper_limitation_angle = nullptr;
    _read();
}

void mmd_pmx_t::bone_ik_link_t::_read() {
    m_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root));
    m_angle_limitation = m__io->read_u1();
    n_lower_limitation_angle = true;
    if (angle_limitation() == 1) {
        n_lower_limitation_angle = false;
        m_lower_limitation_angle = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    }
    n_upper_limitation_angle = true;
    if (angle_limitation() == 1) {
        n_upper_limitation_angle = false;
        m_upper_limitation_angle = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    }
}

mmd_pmx_t::bone_ik_link_t::~bone_ik_link_t() {
    _clean_up();
}

void mmd_pmx_t::bone_ik_link_t::_clean_up() {
    if (!n_lower_limitation_angle) {
    }
    if (!n_upper_limitation_angle) {
    }
}

mmd_pmx_t::vec4_t::vec4_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmx_t::vec4_t::_read() {
    m_x = m__io->read_f4le();
    m_y = m__io->read_f4le();
    m_z = m__io->read_f4le();
    m_w = m__io->read_f4le();
}

mmd_pmx_t::vec4_t::~vec4_t() {
    _clean_up();
}

void mmd_pmx_t::vec4_t::_clean_up() {
}

mmd_pmx_t::bdef1_weights_t::bdef1_weights_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_bone_index = nullptr;
    _read();
}

void mmd_pmx_t::bdef1_weights_t::_read() {
    m_bone_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root));
}

mmd_pmx_t::bdef1_weights_t::~bdef1_weights_t() {
    _clean_up();
}

void mmd_pmx_t::bdef1_weights_t::_clean_up() {
}

mmd_pmx_t::vertex_t::vertex_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_position = nullptr;
    m_normal = nullptr;
    m_uv = nullptr;
    m_additional_uvs = nullptr;
    _read();
}

void mmd_pmx_t::vertex_t::_read() {
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_normal = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_uv = std::unique_ptr<vec2_t>(new vec2_t(m__io, this, m__root));
    int l_additional_uvs = _root()->header()->additional_uv_count();
    m_additional_uvs = std::unique_ptr<std::vector<std::unique_ptr<vec4_t>>>(new std::vector<std::unique_ptr<vec4_t>>());
    m_additional_uvs->reserve(l_additional_uvs);
    for (int i = 0; i < l_additional_uvs; i++) {
        m_additional_uvs->push_back(std::move(std::unique_ptr<vec4_t>(new vec4_t(m__io, this, m__root))));
    }
    m_type = static_cast<mmd_pmx_t::bone_type_t>(m__io->read_u1());
    n_skin_weights = true;
    switch (type()) {
    case mmd_pmx_t::BONE_TYPE_BDEF4: {
        n_skin_weights = false;
        m_skin_weights = std::unique_ptr<bdef4_weights_t>(new bdef4_weights_t(m__io, this, m__root));
        break;
    }
    case mmd_pmx_t::BONE_TYPE_BDEF1: {
        n_skin_weights = false;
        m_skin_weights = std::unique_ptr<bdef1_weights_t>(new bdef1_weights_t(m__io, this, m__root));
        break;
    }
    case mmd_pmx_t::BONE_TYPE_BDEF2: {
        n_skin_weights = false;
        m_skin_weights = std::unique_ptr<bdef2_weights_t>(new bdef2_weights_t(m__io, this, m__root));
        break;
    }
    case mmd_pmx_t::BONE_TYPE_QDEF: {
        n_skin_weights = false;
        m_skin_weights = std::unique_ptr<qdef_weights_t>(new qdef_weights_t(m__io, this, m__root));
        break;
    }
    case mmd_pmx_t::BONE_TYPE_SDEF: {
        n_skin_weights = false;
        m_skin_weights = std::unique_ptr<sdef_weights_t>(new sdef_weights_t(m__io, this, m__root));
        break;
    }
    }
    m_edge_ratio = m__io->read_f4le();
}

mmd_pmx_t::vertex_t::~vertex_t() {
    _clean_up();
}

void mmd_pmx_t::vertex_t::_clean_up() {
    if (!n_skin_weights) {
    }
}

mmd_pmx_t::material_morph_element_t::material_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_index = nullptr;
    m_diffuse = nullptr;
    m_specular = nullptr;
    m_ambient = nullptr;
    m_edge_color = nullptr;
    m_texture_color = nullptr;
    m_sphere_texture_color = nullptr;
    m_toon_color = nullptr;
    _read();
}

void mmd_pmx_t::material_morph_element_t::_read() {
    m_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->material_index_size(), m__io, this, m__root));
    m_type = m__io->read_u1();
    m_diffuse = std::unique_ptr<color4_t>(new color4_t(m__io, this, m__root));
    m_specular = std::unique_ptr<color3_t>(new color3_t(m__io, this, m__root));
    m_shininess = m__io->read_f4le();
    m_ambient = std::unique_ptr<color3_t>(new color3_t(m__io, this, m__root));
    m_edge_color = std::unique_ptr<color4_t>(new color4_t(m__io, this, m__root));
    m_edge_size = m__io->read_f4le();
    m_texture_color = std::unique_ptr<color4_t>(new color4_t(m__io, this, m__root));
    m_sphere_texture_color = std::unique_ptr<color4_t>(new color4_t(m__io, this, m__root));
    m_toon_color = std::unique_ptr<color4_t>(new color4_t(m__io, this, m__root));
}

mmd_pmx_t::material_morph_element_t::~material_morph_element_t() {
    _clean_up();
}

void mmd_pmx_t::material_morph_element_t::_clean_up() {
}

mmd_pmx_t::bone_morph_element_t::bone_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_index = nullptr;
    m_position = nullptr;
    m_rotation = nullptr;
    _read();
}

void mmd_pmx_t::bone_morph_element_t::_read() {
    m_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root));
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_rotation = std::unique_ptr<vec4_t>(new vec4_t(m__io, this, m__root));
}

mmd_pmx_t::bone_morph_element_t::~bone_morph_element_t() {
    _clean_up();
}

void mmd_pmx_t::bone_morph_element_t::_clean_up() {
}

mmd_pmx_t::color4_t::color4_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmx_t::color4_t::_read() {
    m_r = m__io->read_f4le();
    m_g = m__io->read_f4le();
    m_b = m__io->read_f4le();
    m_a = m__io->read_f4le();
}

mmd_pmx_t::color4_t::~color4_t() {
    _clean_up();
}

void mmd_pmx_t::color4_t::_clean_up() {
}

mmd_pmx_t::bone_grant_t::bone_grant_t(kaitai::kstream* p__io, mmd_pmx_t::bone_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_parent_index = nullptr;
    f_local = false;
    f_affect_rotation = false;
    f_affect_position = false;
    _read();
}

void mmd_pmx_t::bone_grant_t::_read() {
    m_parent_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root));
    m_ratio = m__io->read_f4le();
}

mmd_pmx_t::bone_grant_t::~bone_grant_t() {
    _clean_up();
}

void mmd_pmx_t::bone_grant_t::_clean_up() {
}

bool mmd_pmx_t::bone_grant_t::local() {
    if (f_local)
        return m_local;
    m_local = _parent()->add_local_deform();
    f_local = true;
    return m_local;
}

bool mmd_pmx_t::bone_grant_t::affect_rotation() {
    if (f_affect_rotation)
        return m_affect_rotation;
    m_affect_rotation = _parent()->inherit_rotation();
    f_affect_rotation = true;
    return m_affect_rotation;
}

bool mmd_pmx_t::bone_grant_t::affect_position() {
    if (f_affect_position)
        return m_affect_position;
    m_affect_position = _parent()->inherit_translation();
    f_affect_position = true;
    return m_affect_position;
}

mmd_pmx_t::vertex_morph_element_t::vertex_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_index = nullptr;
    m_position = nullptr;
    _read();
}

void mmd_pmx_t::vertex_morph_element_t::_read() {
    m_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->vertex_index_size(), m__io, this, m__root));
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
}

mmd_pmx_t::vertex_morph_element_t::~vertex_morph_element_t() {
    _clean_up();
}

void mmd_pmx_t::vertex_morph_element_t::_clean_up() {
}

mmd_pmx_t::sdef_weights_t::sdef_weights_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_bone_indices = nullptr;
    m_c = nullptr;
    m_r0 = nullptr;
    m_r1 = nullptr;
    f_weights = false;
    _read();
}

void mmd_pmx_t::sdef_weights_t::_read() {
    int l_bone_indices = 2;
    m_bone_indices = std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>>(new std::vector<std::unique_ptr<sized_index_t>>());
    m_bone_indices->reserve(l_bone_indices);
    for (int i = 0; i < l_bone_indices; i++) {
        m_bone_indices->push_back(std::move(std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root))));
    }
    m_weight1 = m__io->read_f4le();
    m_c = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_r0 = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_r1 = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
}

mmd_pmx_t::sdef_weights_t::~sdef_weights_t() {
    _clean_up();
}

void mmd_pmx_t::sdef_weights_t::_clean_up() {
}

std::vector<double>* mmd_pmx_t::sdef_weights_t::weights() {
    if (f_weights)
        return m_weights.get();
    m_weights = std::unique_ptr<std::vector<double>>(new std::vector<double>{weight1(), (1.0 - weight1())});
    f_weights = true;
    return m_weights.get();
}

mmd_pmx_t::group_morph_element_t::group_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_index = nullptr;
    _read();
}

void mmd_pmx_t::group_morph_element_t::_read() {
    m_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->morph_index_size(), m__io, this, m__root));
    m_ratio = m__io->read_f4le();
}

mmd_pmx_t::group_morph_element_t::~group_morph_element_t() {
    _clean_up();
}

void mmd_pmx_t::group_morph_element_t::_clean_up() {
}

mmd_pmx_t::joint_t::joint_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name = nullptr;
    m_english_name = nullptr;
    m_rigid_body_indices = nullptr;
    m_position = nullptr;
    m_rotation = nullptr;
    m_position_constraint_lower = nullptr;
    m_position_constraint_upper = nullptr;
    m_rotation_constraint_lower = nullptr;
    m_rotation_constraint_upper = nullptr;
    m_spring_position = nullptr;
    m_spring_rotation = nullptr;
    _read();
}

void mmd_pmx_t::joint_t::_read() {
    m_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_english_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_type = static_cast<mmd_pmx_t::joint_type_t>(m__io->read_u1());
    int l_rigid_body_indices = 2;
    m_rigid_body_indices = std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>>(new std::vector<std::unique_ptr<sized_index_t>>());
    m_rigid_body_indices->reserve(l_rigid_body_indices);
    for (int i = 0; i < l_rigid_body_indices; i++) {
        m_rigid_body_indices->push_back(std::move(std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->rigid_body_index_size(), m__io, this, m__root))));
    }
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_rotation = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_position_constraint_lower = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_position_constraint_upper = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_rotation_constraint_lower = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_rotation_constraint_upper = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_spring_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_spring_rotation = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
}

mmd_pmx_t::joint_t::~joint_t() {
    _clean_up();
}

void mmd_pmx_t::joint_t::_clean_up() {
}

mmd_pmx_t::bone_t::bone_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name = nullptr;
    m_english_name = nullptr;
    m_position = nullptr;
    m_parent_index = nullptr;
    m_connect_index = nullptr;
    m_offset_position = nullptr;
    m_grant = nullptr;
    m_fixed_axis = nullptr;
    m_local_x_vector = nullptr;
    m_local_z_vector = nullptr;
    m_ik = nullptr;
    _read();
}

void mmd_pmx_t::bone_t::_read() {
    m_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_english_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_parent_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root));
    m_transformation_class = m__io->read_u4le();
    m_indexed_tail_position = m__io->read_bits_int_le(1);
    m_rotatable = m__io->read_bits_int_le(1);
    m_translatable = m__io->read_bits_int_le(1);
    m_visible = m__io->read_bits_int_le(1);
    m_enabled = m__io->read_bits_int_le(1);
    m_has_ik = m__io->read_bits_int_le(1);
    m_unknown6 = m__io->read_bits_int_le(1);
    m_add_local_deform = m__io->read_bits_int_le(1);
    m_inherit_rotation = m__io->read_bits_int_le(1);
    m_inherit_translation = m__io->read_bits_int_le(1);
    m_has_fixed_axis = m__io->read_bits_int_le(1);
    m_has_local_axes = m__io->read_bits_int_le(1);
    m_physics_after_deform = m__io->read_bits_int_le(1);
    m_external_parent_deform = m__io->read_bits_int_le(1);
    m_reserved = m__io->read_bits_int_le(2);
    m__io->align_to_byte();
    n_connect_index = true;
    if (indexed_tail_position()) {
        n_connect_index = false;
        m_connect_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root));
    }
    n_offset_position = true;
    if (!(indexed_tail_position())) {
        n_offset_position = false;
        m_offset_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    }
    n_grant = true;
    if ( ((inherit_rotation()) || (inherit_translation())) ) {
        n_grant = false;
        m_grant = std::unique_ptr<bone_grant_t>(new bone_grant_t(m__io, this, m__root));
    }
    n_fixed_axis = true;
    if (has_fixed_axis()) {
        n_fixed_axis = false;
        m_fixed_axis = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    }
    n_local_x_vector = true;
    if (has_local_axes()) {
        n_local_x_vector = false;
        m_local_x_vector = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    }
    n_local_z_vector = true;
    if (has_local_axes()) {
        n_local_z_vector = false;
        m_local_z_vector = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    }
    n_key = true;
    if (external_parent_deform()) {
        n_key = false;
        m_key = m__io->read_u4le();
    }
    n_ik = true;
    if (has_ik()) {
        n_ik = false;
        m_ik = std::unique_ptr<bone_ik_t>(new bone_ik_t(m__io, this, m__root));
    }
}

mmd_pmx_t::bone_t::~bone_t() {
    _clean_up();
}

void mmd_pmx_t::bone_t::_clean_up() {
    if (!n_connect_index) {
    }
    if (!n_offset_position) {
    }
    if (!n_grant) {
    }
    if (!n_fixed_axis) {
    }
    if (!n_local_x_vector) {
    }
    if (!n_local_z_vector) {
    }
    if (!n_key) {
    }
    if (!n_ik) {
    }
}

mmd_pmx_t::frame_t::frame_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name = nullptr;
    m_english_name = nullptr;
    m_elements = nullptr;
    _read();
}

void mmd_pmx_t::frame_t::_read() {
    m_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_english_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_type = m__io->read_u1();
    m_element_count = m__io->read_u4le();
    int l_elements = element_count();
    m_elements = std::unique_ptr<std::vector<std::unique_ptr<frame_element_t>>>(new std::vector<std::unique_ptr<frame_element_t>>());
    m_elements->reserve(l_elements);
    for (int i = 0; i < l_elements; i++) {
        m_elements->push_back(std::move(std::unique_ptr<frame_element_t>(new frame_element_t(m__io, this, m__root))));
    }
}

mmd_pmx_t::frame_t::~frame_t() {
    _clean_up();
}

void mmd_pmx_t::frame_t::_clean_up() {
}

mmd_pmx_t::qdef_weights_t::qdef_weights_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_bone_indices = nullptr;
    m_weights = nullptr;
    _read();
}

void mmd_pmx_t::qdef_weights_t::_read() {
    int l_bone_indices = 4;
    m_bone_indices = std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>>(new std::vector<std::unique_ptr<sized_index_t>>());
    m_bone_indices->reserve(l_bone_indices);
    for (int i = 0; i < l_bone_indices; i++) {
        m_bone_indices->push_back(std::move(std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root))));
    }
    int l_weights = 4;
    m_weights = std::unique_ptr<std::vector<float>>(new std::vector<float>());
    m_weights->reserve(l_weights);
    for (int i = 0; i < l_weights; i++) {
        m_weights->push_back(std::move(m__io->read_f4le()));
    }
}

mmd_pmx_t::qdef_weights_t::~qdef_weights_t() {
    _clean_up();
}

void mmd_pmx_t::qdef_weights_t::_clean_up() {
}

mmd_pmx_t::face_t::face_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_indices = nullptr;
    _read();
}

void mmd_pmx_t::face_t::_read() {
    int l_indices = 3;
    m_indices = std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>>(new std::vector<std::unique_ptr<sized_index_t>>());
    m_indices->reserve(l_indices);
    for (int i = 0; i < l_indices; i++) {
        m_indices->push_back(std::move(std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->vertex_index_size(), m__io, this, m__root))));
    }
}

mmd_pmx_t::face_t::~face_t() {
    _clean_up();
}

void mmd_pmx_t::face_t::_clean_up() {
}

mmd_pmx_t::color3_t::color3_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmx_t::color3_t::_read() {
    m_r = m__io->read_f4le();
    m_g = m__io->read_f4le();
    m_b = m__io->read_f4le();
}

mmd_pmx_t::color3_t::~color3_t() {
    _clean_up();
}

void mmd_pmx_t::color3_t::_clean_up() {
}

mmd_pmx_t::morph_t::morph_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name = nullptr;
    m_english_name = nullptr;
    m_elements = nullptr;
    _read();
}

void mmd_pmx_t::morph_t::_read() {
    m_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_english_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_panel = m__io->read_u1();
    m_type = static_cast<mmd_pmx_t::morph_type_t>(m__io->read_u1());
    m_element_count = m__io->read_u4le();
    int l_elements = element_count();
    m_elements = std::unique_ptr<std::vector<std::unique_ptr<kaitai::kstruct>>>(new std::vector<std::unique_ptr<kaitai::kstruct>>());
    m_elements->reserve(l_elements);
    for (int i = 0; i < l_elements; i++) {
        switch (type()) {
        case mmd_pmx_t::MORPH_TYPE_ADDITIONAL_UV4: {
            m_elements->push_back(std::move(std::unique_ptr<uv_morph_element_t>(new uv_morph_element_t(m__io, this, m__root))));
            break;
        }
        case mmd_pmx_t::MORPH_TYPE_ADDITIONAL_UV1: {
            m_elements->push_back(std::move(std::unique_ptr<uv_morph_element_t>(new uv_morph_element_t(m__io, this, m__root))));
            break;
        }
        case mmd_pmx_t::MORPH_TYPE_VERTEX: {
            m_elements->push_back(std::move(std::unique_ptr<vertex_morph_element_t>(new vertex_morph_element_t(m__io, this, m__root))));
            break;
        }
        case mmd_pmx_t::MORPH_TYPE_MATERIAL: {
            m_elements->push_back(std::move(std::unique_ptr<material_morph_element_t>(new material_morph_element_t(m__io, this, m__root))));
            break;
        }
        case mmd_pmx_t::MORPH_TYPE_FLIP: {
            m_elements->push_back(std::move(std::unique_ptr<group_morph_element_t>(new group_morph_element_t(m__io, this, m__root))));
            break;
        }
        case mmd_pmx_t::MORPH_TYPE_ADDITIONAL_UV3: {
            m_elements->push_back(std::move(std::unique_ptr<uv_morph_element_t>(new uv_morph_element_t(m__io, this, m__root))));
            break;
        }
        case mmd_pmx_t::MORPH_TYPE_ADDITIONAL_UV2: {
            m_elements->push_back(std::move(std::unique_ptr<uv_morph_element_t>(new uv_morph_element_t(m__io, this, m__root))));
            break;
        }
        case mmd_pmx_t::MORPH_TYPE_UV: {
            m_elements->push_back(std::move(std::unique_ptr<uv_morph_element_t>(new uv_morph_element_t(m__io, this, m__root))));
            break;
        }
        case mmd_pmx_t::MORPH_TYPE_GROUP: {
            m_elements->push_back(std::move(std::unique_ptr<group_morph_element_t>(new group_morph_element_t(m__io, this, m__root))));
            break;
        }
        case mmd_pmx_t::MORPH_TYPE_IMPULSE: {
            m_elements->push_back(std::move(std::unique_ptr<impulse_morph_element_t>(new impulse_morph_element_t(m__io, this, m__root))));
            break;
        }
        case mmd_pmx_t::MORPH_TYPE_BONE: {
            m_elements->push_back(std::move(std::unique_ptr<bone_morph_element_t>(new bone_morph_element_t(m__io, this, m__root))));
            break;
        }
        }
    }
}

mmd_pmx_t::morph_t::~morph_t() {
    _clean_up();
}

void mmd_pmx_t::morph_t::_clean_up() {
}

mmd_pmx_t::vec2_t::vec2_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmx_t::vec2_t::_read() {
    m_x = m__io->read_f4le();
    m_y = m__io->read_f4le();
}

mmd_pmx_t::vec2_t::~vec2_t() {
    _clean_up();
}

void mmd_pmx_t::vec2_t::_clean_up() {
}

mmd_pmx_t::frame_element_t::frame_element_t(kaitai::kstream* p__io, mmd_pmx_t::frame_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmx_t::frame_element_t::_read() {
    m_target = m__io->read_u1();
    switch (target()) {
    case 0: {
        m_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root));
        break;
    }
    default: {
        m_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->morph_index_size(), m__io, this, m__root));
        break;
    }
    }
}

mmd_pmx_t::frame_element_t::~frame_element_t() {
    _clean_up();
}

void mmd_pmx_t::frame_element_t::_clean_up() {
}

mmd_pmx_t::impulse_morph_element_t::impulse_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_rigid_body_index = nullptr;
    m_translational_velocity = nullptr;
    m_angular_velocity = nullptr;
    _read();
}

void mmd_pmx_t::impulse_morph_element_t::_read() {
    m_rigid_body_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->rigid_body_index_size(), m__io, this, m__root));
    m_local = m__io->read_u1();
    m_translational_velocity = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_angular_velocity = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
}

mmd_pmx_t::impulse_morph_element_t::~impulse_morph_element_t() {
    _clean_up();
}

void mmd_pmx_t::impulse_morph_element_t::_clean_up() {
}

mmd_pmx_t::bone_ik_t::bone_ik_t(kaitai::kstream* p__io, mmd_pmx_t::bone_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_effector = nullptr;
    m_links = nullptr;
    _read();
}

void mmd_pmx_t::bone_ik_t::_read() {
    m_effector = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root));
    m_iteration = m__io->read_u4le();
    m_max_angle = m__io->read_f4le();
    m_link_count = m__io->read_u4le();
    int l_links = link_count();
    m_links = std::unique_ptr<std::vector<std::unique_ptr<bone_ik_link_t>>>(new std::vector<std::unique_ptr<bone_ik_link_t>>());
    m_links->reserve(l_links);
    for (int i = 0; i < l_links; i++) {
        m_links->push_back(std::move(std::unique_ptr<bone_ik_link_t>(new bone_ik_link_t(m__io, this, m__root))));
    }
}

mmd_pmx_t::bone_ik_t::~bone_ik_t() {
    _clean_up();
}

void mmd_pmx_t::bone_ik_t::_clean_up() {
}

mmd_pmx_t::uv_morph_element_t::uv_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_index = nullptr;
    m_uv = nullptr;
    _read();
}

void mmd_pmx_t::uv_morph_element_t::_read() {
    m_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->vertex_index_size(), m__io, this, m__root));
    m_uv = std::unique_ptr<vec4_t>(new vec4_t(m__io, this, m__root));
}

mmd_pmx_t::uv_morph_element_t::~uv_morph_element_t() {
    _clean_up();
}

void mmd_pmx_t::uv_morph_element_t::_clean_up() {
}

mmd_pmx_t::bdef2_weights_t::bdef2_weights_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_bone_indices = nullptr;
    f_weights = false;
    _read();
}

void mmd_pmx_t::bdef2_weights_t::_read() {
    int l_bone_indices = 2;
    m_bone_indices = std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>>(new std::vector<std::unique_ptr<sized_index_t>>());
    m_bone_indices->reserve(l_bone_indices);
    for (int i = 0; i < l_bone_indices; i++) {
        m_bone_indices->push_back(std::move(std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root))));
    }
    m_weight1 = m__io->read_f4le();
}

mmd_pmx_t::bdef2_weights_t::~bdef2_weights_t() {
    _clean_up();
}

void mmd_pmx_t::bdef2_weights_t::_clean_up() {
}

std::vector<double>* mmd_pmx_t::bdef2_weights_t::weights() {
    if (f_weights)
        return m_weights.get();
    m_weights = std::unique_ptr<std::vector<double>>(new std::vector<double>{weight1(), (1.0 - weight1())});
    f_weights = true;
    return m_weights.get();
}

mmd_pmx_t::header_t::header_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_model_name = nullptr;
    m_english_model_name = nullptr;
    m_comment = nullptr;
    m_english_comment = nullptr;
    _read();
}

void mmd_pmx_t::header_t::_read() {
    m_magic = m__io->read_bytes(4);
    if (!(magic() == std::string("\x50\x4D\x58\x20", 4))) {
        return;
    }
    m_version = m__io->read_f4le();
    m_header_size = m__io->read_u1();
    m_encoding = m__io->read_u1();
    m_additional_uv_count = m__io->read_u1();
    m_vertex_index_size = m__io->read_u1();
    m_texture_index_size = m__io->read_u1();
    m_material_index_size = m__io->read_u1();
    m_bone_index_size = m__io->read_u1();
    m_morph_index_size = m__io->read_u1();
    m_rigid_body_index_size = m__io->read_u1();
    m_model_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_english_model_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_comment = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_english_comment = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
}

mmd_pmx_t::header_t::~header_t() {
    _clean_up();
}

void mmd_pmx_t::header_t::_clean_up() {
}

mmd_pmx_t::common_toon_index_t::common_toon_index_t(kaitai::kstream* p__io, mmd_pmx_t::material_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmx_t::common_toon_index_t::_read() {
    m_value = m__io->read_u1();
}

mmd_pmx_t::common_toon_index_t::~common_toon_index_t() {
    _clean_up();
}

void mmd_pmx_t::common_toon_index_t::_clean_up() {
}

mmd_pmx_t::material_t::material_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name = nullptr;
    m_english_name = nullptr;
    m_diffuse = nullptr;
    m_specular = nullptr;
    m_ambient = nullptr;
    m_edge_color = nullptr;
    m_texture_index = nullptr;
    m_sphere_texture_index = nullptr;
    m_comment = nullptr;
    _read();
}

void mmd_pmx_t::material_t::_read() {
    m_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_english_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_diffuse = std::unique_ptr<color4_t>(new color4_t(m__io, this, m__root));
    m_specular = std::unique_ptr<color3_t>(new color3_t(m__io, this, m__root));
    m_shininess = m__io->read_f4le();
    m_ambient = std::unique_ptr<color3_t>(new color3_t(m__io, this, m__root));
    m_no_cull = m__io->read_bits_int_le(1);
    m_ground_shadow = m__io->read_bits_int_le(1);
    m_cast_shadow = m__io->read_bits_int_le(1);
    m_receive_shadow = m__io->read_bits_int_le(1);
    m_outlined = m__io->read_bits_int_le(1);
    m_uses_vertex_color = m__io->read_bits_int_le(1);
    m_render_points = m__io->read_bits_int_le(1);
    m_render_lines = m__io->read_bits_int_le(1);
    m__io->align_to_byte();
    m_edge_color = std::unique_ptr<color4_t>(new color4_t(m__io, this, m__root));
    m_edge_size = m__io->read_f4le();
    m_texture_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->texture_index_size(), m__io, this, m__root));
    m_sphere_texture_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->texture_index_size(), m__io, this, m__root));
    m_sphere_op_mode = static_cast<mmd_pmx_t::sphere_op_mode_t>(m__io->read_u1());
    m_is_common_toon = m__io->read_u1();
    n_toon_index = true;
    switch (is_common_toon()) {
    case 0: {
        n_toon_index = false;
        m_toon_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->texture_index_size(), m__io, this, m__root));
        break;
    }
    case 1: {
        n_toon_index = false;
        m_toon_index = std::unique_ptr<common_toon_index_t>(new common_toon_index_t(m__io, this, m__root));
        break;
    }
    }
    m_comment = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_face_vertex_count = m__io->read_u4le();
}

mmd_pmx_t::material_t::~material_t() {
    _clean_up();
}

void mmd_pmx_t::material_t::_clean_up() {
    if (!n_toon_index) {
    }
}

mmd_pmx_t::vec3_t::vec3_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmx_t::vec3_t::_read() {
    m_x = m__io->read_f4le();
    m_y = m__io->read_f4le();
    m_z = m__io->read_f4le();
}

mmd_pmx_t::vec3_t::~vec3_t() {
    _clean_up();
}

void mmd_pmx_t::vec3_t::_clean_up() {
}

mmd_pmx_t::sized_index_t::sized_index_t(uint8_t p_size, kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_size = p_size;
    _read();
}

void mmd_pmx_t::sized_index_t::_read() {
    n_value = true;
    switch (size()) {
    case 1: {
        n_value = false;
        m_value = m__io->read_u1();
        break;
    }
    case 2: {
        n_value = false;
        m_value = m__io->read_u2le();
        break;
    }
    case 4: {
        n_value = false;
        m_value = m__io->read_u4le();
        break;
    }
    }
}

mmd_pmx_t::sized_index_t::~sized_index_t() {
    _clean_up();
}

void mmd_pmx_t::sized_index_t::_clean_up() {
    if (!n_value) {
    }
}

mmd_pmx_t::bdef4_weights_t::bdef4_weights_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_bone_indices = nullptr;
    m_weights = nullptr;
    _read();
}

void mmd_pmx_t::bdef4_weights_t::_read() {
    int l_bone_indices = 4;
    m_bone_indices = std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>>(new std::vector<std::unique_ptr<sized_index_t>>());
    m_bone_indices->reserve(l_bone_indices);
    for (int i = 0; i < l_bone_indices; i++) {
        m_bone_indices->push_back(std::move(std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root))));
    }
    int l_weights = 4;
    m_weights = std::unique_ptr<std::vector<float>>(new std::vector<float>());
    m_weights->reserve(l_weights);
    for (int i = 0; i < l_weights; i++) {
        m_weights->push_back(std::move(m__io->read_f4le()));
    }
}

mmd_pmx_t::bdef4_weights_t::~bdef4_weights_t() {
    _clean_up();
}

void mmd_pmx_t::bdef4_weights_t::_clean_up() {
}

mmd_pmx_t::rigid_body_t::rigid_body_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name = nullptr;
    m_english_name = nullptr;
    m_bone_index = nullptr;
    m_position = nullptr;
    m_rotation = nullptr;
    _read();
}

void mmd_pmx_t::rigid_body_t::_read() {
    m_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_english_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
    m_bone_index = std::unique_ptr<sized_index_t>(new sized_index_t(_root()->header()->bone_index_size(), m__io, this, m__root));
    m_group_index = m__io->read_u1();
    m_group_target = m__io->read_u2le();
    m_shape_type = m__io->read_u1();
    m_width = m__io->read_f4le();
    m_height = m__io->read_f4le();
    m_depth = m__io->read_f4le();
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_rotation = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_weight = m__io->read_f4le();
    m_position_damping = m__io->read_f4le();
    m_rotation_damping = m__io->read_f4le();
    m_restitution = m__io->read_f4le();
    m_friction = m__io->read_f4le();
    m_type = m__io->read_u1();
}

mmd_pmx_t::rigid_body_t::~rigid_body_t() {
    _clean_up();
}

void mmd_pmx_t::rigid_body_t::_clean_up() {
}

mmd_pmx_t::texture_t::texture_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name = nullptr;
    _read();
}

void mmd_pmx_t::texture_t::_read() {
    m_name = std::unique_ptr<len_string_t>(new len_string_t(m__io, this, m__root));
}

mmd_pmx_t::texture_t::~texture_t() {
    _clean_up();
}

void mmd_pmx_t::texture_t::_clean_up() {
}

mmd_pmx_t::len_string_t::len_string_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_pmx_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmx_t::len_string_t::_read() {
    m_length = m__io->read_u4le();
    m_value = kaitai::kstream::bytes_to_str(m__io->read_bytes(length()), std::string("UTF-16LE"));
}

mmd_pmx_t::len_string_t::~len_string_t() {
    _clean_up();
}

void mmd_pmx_t::len_string_t::_clean_up() {
}
