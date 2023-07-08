// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "mmd_pmd.h"
#include "kaitai/exceptions.h"

mmd_pmd_t::mmd_pmd_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_header = nullptr;
    m_vertices = nullptr;
    m_faces = nullptr;
    m_materials = nullptr;
    m_bones = nullptr;
    m_iks = nullptr;
    m_morphs = nullptr;
    m_morph_frames = nullptr;
    m_bone_frame_names = nullptr;
    m_bone_frames = nullptr;
    m_english_header = nullptr;
    m_english_bone_names = nullptr;
    m_english_morph_names = nullptr;
    m_english_bone_frame_names = nullptr;
    m_toon_textures = nullptr;
    m_rigid_bodies = nullptr;
    m_constraints = nullptr;
    _read();
}

void mmd_pmd_t::_read() {
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
    m_material_count = m__io->read_u4le();
    int l_materials = material_count();
    m_materials = std::unique_ptr<std::vector<std::unique_ptr<material_t>>>(new std::vector<std::unique_ptr<material_t>>());
    m_materials->reserve(l_materials);
    for (int i = 0; i < l_materials; i++) {
        m_materials->push_back(std::move(std::unique_ptr<material_t>(new material_t(m__io, this, m__root))));
    }
    m_bone_count = m__io->read_u2le();
    int l_bones = bone_count();
    m_bones = std::unique_ptr<std::vector<std::unique_ptr<bone_t>>>(new std::vector<std::unique_ptr<bone_t>>());
    m_bones->reserve(l_bones);
    for (int i = 0; i < l_bones; i++) {
        m_bones->push_back(std::move(std::unique_ptr<bone_t>(new bone_t(m__io, this, m__root))));
    }
    m_ik_count = m__io->read_u2le();
    int l_iks = ik_count();
    m_iks = std::unique_ptr<std::vector<std::unique_ptr<ik_t>>>(new std::vector<std::unique_ptr<ik_t>>());
    m_iks->reserve(l_iks);
    for (int i = 0; i < l_iks; i++) {
        m_iks->push_back(std::move(std::unique_ptr<ik_t>(new ik_t(m__io, this, m__root))));
    }
    m_morph_count = m__io->read_u2le();
    int l_morphs = morph_count();
    m_morphs = std::unique_ptr<std::vector<std::unique_ptr<morph_t>>>(new std::vector<std::unique_ptr<morph_t>>());
    m_morphs->reserve(l_morphs);
    for (int i = 0; i < l_morphs; i++) {
        m_morphs->push_back(std::move(std::unique_ptr<morph_t>(new morph_t(m__io, this, m__root))));
    }
    m_morph_frame_count = m__io->read_u1();
    int l_morph_frames = morph_frame_count();
    m_morph_frames = std::unique_ptr<std::vector<std::unique_ptr<morph_frame_t>>>(new std::vector<std::unique_ptr<morph_frame_t>>());
    m_morph_frames->reserve(l_morph_frames);
    for (int i = 0; i < l_morph_frames; i++) {
        m_morph_frames->push_back(std::move(std::unique_ptr<morph_frame_t>(new morph_frame_t(m__io, this, m__root))));
    }
    m_bone_frame_name_count = m__io->read_u1();
    int l_bone_frame_names = bone_frame_name_count();
    m_bone_frame_names = std::unique_ptr<std::vector<std::unique_ptr<bone_frame_name_t>>>(new std::vector<std::unique_ptr<bone_frame_name_t>>());
    m_bone_frame_names->reserve(l_bone_frame_names);
    for (int i = 0; i < l_bone_frame_names; i++) {
        m_bone_frame_names->push_back(std::move(std::unique_ptr<bone_frame_name_t>(new bone_frame_name_t(m__io, this, m__root))));
    }
    m_bone_frame_count = m__io->read_u4le();
    int l_bone_frames = bone_frame_count();
    m_bone_frames = std::unique_ptr<std::vector<std::unique_ptr<bone_frame_t>>>(new std::vector<std::unique_ptr<bone_frame_t>>());
    m_bone_frames->reserve(l_bone_frames);
    for (int i = 0; i < l_bone_frames; i++) {
        m_bone_frames->push_back(std::move(std::unique_ptr<bone_frame_t>(new bone_frame_t(m__io, this, m__root))));
    }
    m_english_header = std::unique_ptr<english_header_t>(new english_header_t(m__io, this, m__root));
    n_english_bone_names = true;
    if (english_header()->compatibility() > 0) {
        n_english_bone_names = false;
        int l_english_bone_names = bone_count();
        m_english_bone_names = std::unique_ptr<std::vector<std::unique_ptr<english_bone_name_t>>>(new std::vector<std::unique_ptr<english_bone_name_t>>());
        m_english_bone_names->reserve(l_english_bone_names);
        for (int i = 0; i < l_english_bone_names; i++) {
            m_english_bone_names->push_back(std::move(std::unique_ptr<english_bone_name_t>(new english_bone_name_t(m__io, this, m__root))));
        }
    }
    n_english_morph_names = true;
    if (english_header()->compatibility() > 0) {
        n_english_morph_names = false;
        int l_english_morph_names = (morph_count() - 1);
        m_english_morph_names = std::unique_ptr<std::vector<std::unique_ptr<english_morph_name_t>>>(new std::vector<std::unique_ptr<english_morph_name_t>>());
        m_english_morph_names->reserve(l_english_morph_names);
        for (int i = 0; i < l_english_morph_names; i++) {
            m_english_morph_names->push_back(std::move(std::unique_ptr<english_morph_name_t>(new english_morph_name_t(m__io, this, m__root))));
        }
    }
    n_english_bone_frame_names = true;
    if (english_header()->compatibility() > 0) {
        n_english_bone_frame_names = false;
        int l_english_bone_frame_names = bone_frame_name_count();
        m_english_bone_frame_names = std::unique_ptr<std::vector<std::unique_ptr<english_bone_frame_name_t>>>(new std::vector<std::unique_ptr<english_bone_frame_name_t>>());
        m_english_bone_frame_names->reserve(l_english_bone_frame_names);
        for (int i = 0; i < l_english_bone_frame_names; i++) {
            m_english_bone_frame_names->push_back(std::move(std::unique_ptr<english_bone_frame_name_t>(new english_bone_frame_name_t(m__io, this, m__root))));
        }
    }
    int l_toon_textures = 10;
    m_toon_textures = std::unique_ptr<std::vector<std::unique_ptr<toon_texture_t>>>(new std::vector<std::unique_ptr<toon_texture_t>>());
    m_toon_textures->reserve(l_toon_textures);
    for (int i = 0; i < l_toon_textures; i++) {
        m_toon_textures->push_back(std::move(std::unique_ptr<toon_texture_t>(new toon_texture_t(m__io, this, m__root))));
    }
    m_rigid_body_count = m__io->read_u4le();
    int l_rigid_bodies = rigid_body_count();
    m_rigid_bodies = std::unique_ptr<std::vector<std::unique_ptr<rigid_body_t>>>(new std::vector<std::unique_ptr<rigid_body_t>>());
    m_rigid_bodies->reserve(l_rigid_bodies);
    for (int i = 0; i < l_rigid_bodies; i++) {
        m_rigid_bodies->push_back(std::move(std::unique_ptr<rigid_body_t>(new rigid_body_t(m__io, this, m__root))));
    }
    m_constraint_count = m__io->read_u4le();
    int l_constraints = constraint_count();
    m_constraints = std::unique_ptr<std::vector<std::unique_ptr<constraint_t>>>(new std::vector<std::unique_ptr<constraint_t>>());
    m_constraints->reserve(l_constraints);
    for (int i = 0; i < l_constraints; i++) {
        m_constraints->push_back(std::move(std::unique_ptr<constraint_t>(new constraint_t(m__io, this, m__root))));
    }
}

mmd_pmd_t::~mmd_pmd_t() {
    _clean_up();
}

void mmd_pmd_t::_clean_up() {
    if (!n_english_bone_names) {
    }
    if (!n_english_morph_names) {
    }
    if (!n_english_bone_frame_names) {
    }
}

mmd_pmd_t::english_morph_name_t::english_morph_name_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::english_morph_name_t::_read() {
    m_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(20), 0, false), std::string("Shift_JIS"));
}

mmd_pmd_t::english_morph_name_t::~english_morph_name_t() {
    _clean_up();
}

void mmd_pmd_t::english_morph_name_t::_clean_up() {
}

mmd_pmd_t::vec4_t::vec4_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::vec4_t::_read() {
    m_x = m__io->read_f4le();
    m_y = m__io->read_f4le();
    m_z = m__io->read_f4le();
    m_w = m__io->read_f4le();
}

mmd_pmd_t::vec4_t::~vec4_t() {
    _clean_up();
}

void mmd_pmd_t::vec4_t::_clean_up() {
}

mmd_pmd_t::vertex_t::vertex_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_position = nullptr;
    m_normal = nullptr;
    m_uv = nullptr;
    m_skin_indices = nullptr;
    _read();
}

void mmd_pmd_t::vertex_t::_read() {
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_normal = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_uv = std::unique_ptr<vec2_t>(new vec2_t(m__io, this, m__root));
    int l_skin_indices = 2;
    m_skin_indices = std::unique_ptr<std::vector<uint16_t>>(new std::vector<uint16_t>());
    m_skin_indices->reserve(l_skin_indices);
    for (int i = 0; i < l_skin_indices; i++) {
        m_skin_indices->push_back(std::move(m__io->read_u2le()));
    }
    m_skin_weights = m__io->read_u1();
    m_edge_flag = m__io->read_u1();
}

mmd_pmd_t::vertex_t::~vertex_t() {
    _clean_up();
}

void mmd_pmd_t::vertex_t::_clean_up() {
}

mmd_pmd_t::toon_texture_t::toon_texture_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::toon_texture_t::_read() {
    m_file_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(100), 0, false), std::string("Shift_JIS"));
}

mmd_pmd_t::toon_texture_t::~toon_texture_t() {
    _clean_up();
}

void mmd_pmd_t::toon_texture_t::_clean_up() {
}

mmd_pmd_t::english_bone_frame_name_t::english_bone_frame_name_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::english_bone_frame_name_t::_read() {
    m_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(50), 0, false), std::string("Shift_JIS"));
}

mmd_pmd_t::english_bone_frame_name_t::~english_bone_frame_name_t() {
    _clean_up();
}

void mmd_pmd_t::english_bone_frame_name_t::_clean_up() {
}

mmd_pmd_t::color4_t::color4_t(kaitai::kstream* p__io, mmd_pmd_t::material_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::color4_t::_read() {
    m_r = m__io->read_f4le();
    m_g = m__io->read_f4le();
    m_b = m__io->read_f4le();
    m_a = m__io->read_f4le();
}

mmd_pmd_t::color4_t::~color4_t() {
    _clean_up();
}

void mmd_pmd_t::color4_t::_clean_up() {
}

mmd_pmd_t::english_header_t::english_header_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::english_header_t::_read() {
    m_compatibility = m__io->read_u1();
    n_model_name = true;
    if (compatibility() > 0) {
        n_model_name = false;
        m_model_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(20), 0, false), std::string("Shift_JIS"));
    }
    n_comment = true;
    if (compatibility() > 0) {
        n_comment = false;
        m_comment = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(256), 0, false), std::string("Shift_JIS"));
    }
}

mmd_pmd_t::english_header_t::~english_header_t() {
    _clean_up();
}

void mmd_pmd_t::english_header_t::_clean_up() {
    if (!n_model_name) {
    }
    if (!n_comment) {
    }
}

mmd_pmd_t::morph_frame_t::morph_frame_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::morph_frame_t::_read() {
    m_index = m__io->read_u2le();
}

mmd_pmd_t::morph_frame_t::~morph_frame_t() {
    _clean_up();
}

void mmd_pmd_t::morph_frame_t::_clean_up() {
}

mmd_pmd_t::bone_t::bone_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_position = nullptr;
    _read();
}

void mmd_pmd_t::bone_t::_read() {
    m_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(20), 0, false), std::string("Shift_JIS"));
    m_parent_index = m__io->read_u2le();
    m_tail_index = m__io->read_u2le();
    m_type = m__io->read_u1();
    m_ik_index = m__io->read_u2le();
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
}

mmd_pmd_t::bone_t::~bone_t() {
    _clean_up();
}

void mmd_pmd_t::bone_t::_clean_up() {
}

mmd_pmd_t::face_t::face_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_indices = nullptr;
    _read();
}

void mmd_pmd_t::face_t::_read() {
    int l_indices = 3;
    m_indices = std::unique_ptr<std::vector<uint16_t>>(new std::vector<uint16_t>());
    m_indices->reserve(l_indices);
    for (int i = 0; i < l_indices; i++) {
        m_indices->push_back(std::move(m__io->read_u2le()));
    }
}

mmd_pmd_t::face_t::~face_t() {
    _clean_up();
}

void mmd_pmd_t::face_t::_clean_up() {
}

mmd_pmd_t::color3_t::color3_t(kaitai::kstream* p__io, mmd_pmd_t::material_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::color3_t::_read() {
    m_r = m__io->read_f4le();
    m_g = m__io->read_f4le();
    m_b = m__io->read_f4le();
}

mmd_pmd_t::color3_t::~color3_t() {
    _clean_up();
}

void mmd_pmd_t::color3_t::_clean_up() {
}

mmd_pmd_t::morph_t::morph_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_elements = nullptr;
    _read();
}

void mmd_pmd_t::morph_t::_read() {
    m_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(20), 0, false), std::string("Shift_JIS"));
    m_element_count = m__io->read_u4le();
    m_type = m__io->read_u1();
    int l_elements = element_count();
    m_elements = std::unique_ptr<std::vector<std::unique_ptr<morph_element_t>>>(new std::vector<std::unique_ptr<morph_element_t>>());
    m_elements->reserve(l_elements);
    for (int i = 0; i < l_elements; i++) {
        m_elements->push_back(std::move(std::unique_ptr<morph_element_t>(new morph_element_t(m__io, this, m__root))));
    }
}

mmd_pmd_t::morph_t::~morph_t() {
    _clean_up();
}

void mmd_pmd_t::morph_t::_clean_up() {
}

mmd_pmd_t::vec2_t::vec2_t(kaitai::kstream* p__io, mmd_pmd_t::vertex_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::vec2_t::_read() {
    m_x = m__io->read_f4le();
    m_y = m__io->read_f4le();
}

mmd_pmd_t::vec2_t::~vec2_t() {
    _clean_up();
}

void mmd_pmd_t::vec2_t::_clean_up() {
}

mmd_pmd_t::bone_frame_t::bone_frame_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::bone_frame_t::_read() {
    m_bone_index = m__io->read_u2le();
    m_frame_index = m__io->read_u1();
}

mmd_pmd_t::bone_frame_t::~bone_frame_t() {
    _clean_up();
}

void mmd_pmd_t::bone_frame_t::_clean_up() {
}

mmd_pmd_t::morph_element_t::morph_element_t(kaitai::kstream* p__io, mmd_pmd_t::morph_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_position = nullptr;
    _read();
}

void mmd_pmd_t::morph_element_t::_read() {
    m_index = m__io->read_u4le();
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
}

mmd_pmd_t::morph_element_t::~morph_element_t() {
    _clean_up();
}

void mmd_pmd_t::morph_element_t::_clean_up() {
}

mmd_pmd_t::header_t::header_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::header_t::_read() {
    m_magic = m__io->read_bytes(3);
    if (!(magic() == std::string("\x50\x6D\x64", 3))) {
        return;
    }
    m_version = m__io->read_u4le();
    m_model_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(20), 0, false), std::string("Shift_JIS"));
    m_comment = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(256), 0, false), std::string("Shift_JIS"));
}

mmd_pmd_t::header_t::~header_t() {
    _clean_up();
}

void mmd_pmd_t::header_t::_clean_up() {
}

mmd_pmd_t::constraint_t::constraint_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_rigid_body_indices = nullptr;
    m_position = nullptr;
    m_rotation = nullptr;
    m_translation_limitation_lower = nullptr;
    m_translation_limitation_upper = nullptr;
    m_rotation_limitation_lower = nullptr;
    m_rotation_limitation_upper = nullptr;
    m_spring_position = nullptr;
    m_spring_rotation = nullptr;
    _read();
}

void mmd_pmd_t::constraint_t::_read() {
    m_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(20), 0, false), std::string("Shift_JIS"));
    int l_rigid_body_indices = 2;
    m_rigid_body_indices = std::unique_ptr<std::vector<uint32_t>>(new std::vector<uint32_t>());
    m_rigid_body_indices->reserve(l_rigid_body_indices);
    for (int i = 0; i < l_rigid_body_indices; i++) {
        m_rigid_body_indices->push_back(std::move(m__io->read_u4le()));
    }
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_rotation = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_translation_limitation_lower = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_translation_limitation_upper = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_rotation_limitation_lower = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_rotation_limitation_upper = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_spring_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_spring_rotation = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
}

mmd_pmd_t::constraint_t::~constraint_t() {
    _clean_up();
}

void mmd_pmd_t::constraint_t::_clean_up() {
}

mmd_pmd_t::material_t::material_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_diffuse = nullptr;
    m_specular = nullptr;
    m_ambient = nullptr;
    _read();
}

void mmd_pmd_t::material_t::_read() {
    m_diffuse = std::unique_ptr<color4_t>(new color4_t(m__io, this, m__root));
    m_shininess = m__io->read_f4le();
    m_specular = std::unique_ptr<color3_t>(new color3_t(m__io, this, m__root));
    m_ambient = std::unique_ptr<color3_t>(new color3_t(m__io, this, m__root));
    m_toon_index = m__io->read_u1();
    m_edge_flag = m__io->read_u1();
    m_face_vertex_count = m__io->read_u4le();
    m_file_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(20), 0, false), std::string("Shift_JIS"));
}

mmd_pmd_t::material_t::~material_t() {
    _clean_up();
}

void mmd_pmd_t::material_t::_clean_up() {
}

mmd_pmd_t::vec3_t::vec3_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::vec3_t::_read() {
    m_x = m__io->read_f4le();
    m_y = m__io->read_f4le();
    m_z = m__io->read_f4le();
}

mmd_pmd_t::vec3_t::~vec3_t() {
    _clean_up();
}

void mmd_pmd_t::vec3_t::_clean_up() {
}

mmd_pmd_t::english_bone_name_t::english_bone_name_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::english_bone_name_t::_read() {
    m_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(20), 0, false), std::string("Shift_JIS"));
}

mmd_pmd_t::english_bone_name_t::~english_bone_name_t() {
    _clean_up();
}

void mmd_pmd_t::english_bone_name_t::_clean_up() {
}

mmd_pmd_t::rigid_body_t::rigid_body_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_position = nullptr;
    m_rotation = nullptr;
    _read();
}

void mmd_pmd_t::rigid_body_t::_read() {
    m_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(20), 0, false), std::string("Shift_JIS"));
    m_bone_index = m__io->read_u2le();
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

mmd_pmd_t::rigid_body_t::~rigid_body_t() {
    _clean_up();
}

void mmd_pmd_t::rigid_body_t::_clean_up() {
}

mmd_pmd_t::bone_frame_name_t::bone_frame_name_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_pmd_t::bone_frame_name_t::_read() {
    m_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(50), 0, false), std::string("Shift_JIS"));
}

mmd_pmd_t::bone_frame_name_t::~bone_frame_name_t() {
    _clean_up();
}

void mmd_pmd_t::bone_frame_name_t::_clean_up() {
}

mmd_pmd_t::ik_t::ik_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent, mmd_pmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_link_indices = nullptr;
    _read();
}

void mmd_pmd_t::ik_t::_read() {
    m_target = m__io->read_u2le();
    m_effector = m__io->read_u2le();
    m_link_count = m__io->read_u1();
    m_iteration = m__io->read_u2le();
    m_max_angle = m__io->read_f4le();
    int l_link_indices = link_count();
    m_link_indices = std::unique_ptr<std::vector<uint16_t>>(new std::vector<uint16_t>());
    m_link_indices->reserve(l_link_indices);
    for (int i = 0; i < l_link_indices; i++) {
        m_link_indices->push_back(std::move(m__io->read_u2le()));
    }
}

mmd_pmd_t::ik_t::~ik_t() {
    _clean_up();
}

void mmd_pmd_t::ik_t::_clean_up() {
}
