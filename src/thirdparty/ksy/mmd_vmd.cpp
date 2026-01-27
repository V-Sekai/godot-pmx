// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "mmd_vmd.h"
#include "kaitai/exceptions.h"

mmd_vmd_t::mmd_vmd_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_vmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_header = nullptr;
    m_motions = nullptr;
    m_morphs = nullptr;
    m_cameras = nullptr;
    _read();
}

void mmd_vmd_t::_read() {
    m_header = std::unique_ptr<header_t>(new header_t(m__io, this, m__root));
    m_motion_count = m__io->read_u4le();
    int l_motions = motion_count();
    m_motions = std::unique_ptr<std::vector<std::unique_ptr<motion_t>>>(new std::vector<std::unique_ptr<motion_t>>());
    m_motions->reserve(l_motions);
    for (int i = 0; i < l_motions; i++) {
        m_motions->push_back(std::move(std::unique_ptr<motion_t>(new motion_t(m__io, this, m__root))));
    }
    m_morph_count = m__io->read_u4le();
    int l_morphs = morph_count();
    m_morphs = std::unique_ptr<std::vector<std::unique_ptr<morph_t>>>(new std::vector<std::unique_ptr<morph_t>>());
    m_morphs->reserve(l_morphs);
    for (int i = 0; i < l_morphs; i++) {
        m_morphs->push_back(std::move(std::unique_ptr<morph_t>(new morph_t(m__io, this, m__root))));
    }
    m_camera_count = m__io->read_u4le();
    int l_cameras = camera_count();
    m_cameras = std::unique_ptr<std::vector<std::unique_ptr<camera_t>>>(new std::vector<std::unique_ptr<camera_t>>());
    m_cameras->reserve(l_cameras);
    for (int i = 0; i < l_cameras; i++) {
        m_cameras->push_back(std::move(std::unique_ptr<camera_t>(new camera_t(m__io, this, m__root))));
    }
    m_reserved = m__io->read_bytes(8);
    if (!(reserved() == std::string("\x00\x00\x00\x00\x00\x00\x00\x00", 8))) {
        return;
    }
}

mmd_vmd_t::~mmd_vmd_t() {
    _clean_up();
}

void mmd_vmd_t::_clean_up() {
}

mmd_vmd_t::vec4_t::vec4_t(kaitai::kstream* p__io, mmd_vmd_t::motion_t* p__parent, mmd_vmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_vmd_t::vec4_t::_read() {
    m_x = m__io->read_f4le();
    m_y = m__io->read_f4le();
    m_z = m__io->read_f4le();
    m_w = m__io->read_f4le();
}

mmd_vmd_t::vec4_t::~vec4_t() {
    _clean_up();
}

void mmd_vmd_t::vec4_t::_clean_up() {
}

mmd_vmd_t::color4_t::color4_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_vmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_vmd_t::color4_t::_read() {
    m_r = m__io->read_f4le();
    m_g = m__io->read_f4le();
    m_b = m__io->read_f4le();
    m_a = m__io->read_f4le();
}

mmd_vmd_t::color4_t::~color4_t() {
    _clean_up();
}

void mmd_vmd_t::color4_t::_clean_up() {
}

mmd_vmd_t::camera_t::camera_t(kaitai::kstream* p__io, mmd_vmd_t* p__parent, mmd_vmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_position = nullptr;
    m_rotation = nullptr;
    m_interpolation = nullptr;
    _read();
}

void mmd_vmd_t::camera_t::_read() {
    m_frame_number = m__io->read_u4le();
    m_distance = m__io->read_f4le();
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_rotation = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    int l_interpolation = 24;
    m_interpolation = std::unique_ptr<std::vector<uint8_t>>(new std::vector<uint8_t>());
    m_interpolation->reserve(l_interpolation);
    for (int i = 0; i < l_interpolation; i++) {
        m_interpolation->push_back(std::move(m__io->read_u1()));
    }
    m_fov = m__io->read_u4le();
    m_perspective = m__io->read_u1();
}

mmd_vmd_t::camera_t::~camera_t() {
    _clean_up();
}

void mmd_vmd_t::camera_t::_clean_up() {
}

mmd_vmd_t::motion_t::motion_t(kaitai::kstream* p__io, mmd_vmd_t* p__parent, mmd_vmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_position = nullptr;
    m_rotation = nullptr;
    m_interpolation = nullptr;
    _read();
}

void mmd_vmd_t::motion_t::_read() {
    m_bone_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(15), 0, false), std::string("Shift_JIS"));
    m_frame_number = m__io->read_u4le();
    m_position = std::unique_ptr<vec3_t>(new vec3_t(m__io, this, m__root));
    m_rotation = std::unique_ptr<vec4_t>(new vec4_t(m__io, this, m__root));
    int l_interpolation = 64;
    m_interpolation = std::unique_ptr<std::vector<uint8_t>>(new std::vector<uint8_t>());
    m_interpolation->reserve(l_interpolation);
    for (int i = 0; i < l_interpolation; i++) {
        m_interpolation->push_back(std::move(m__io->read_u1()));
    }
}

mmd_vmd_t::motion_t::~motion_t() {
    _clean_up();
}

void mmd_vmd_t::motion_t::_clean_up() {
}

mmd_vmd_t::color3_t::color3_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_vmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_vmd_t::color3_t::_read() {
    m_r = m__io->read_f4le();
    m_g = m__io->read_f4le();
    m_b = m__io->read_f4le();
}

mmd_vmd_t::color3_t::~color3_t() {
    _clean_up();
}

void mmd_vmd_t::color3_t::_clean_up() {
}

mmd_vmd_t::morph_t::morph_t(kaitai::kstream* p__io, mmd_vmd_t* p__parent, mmd_vmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_vmd_t::morph_t::_read() {
    m_morph_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(15), 0, false), std::string("Shift_JIS"));
    m_frame_number = m__io->read_u4le();
    m_weight = m__io->read_f4le();
}

mmd_vmd_t::morph_t::~morph_t() {
    _clean_up();
}

void mmd_vmd_t::morph_t::_clean_up() {
}

mmd_vmd_t::vec2_t::vec2_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_vmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_vmd_t::vec2_t::_read() {
    m_x = m__io->read_f4le();
    m_y = m__io->read_f4le();
}

mmd_vmd_t::vec2_t::~vec2_t() {
    _clean_up();
}

void mmd_vmd_t::vec2_t::_clean_up() {
}

mmd_vmd_t::header_t::header_t(kaitai::kstream* p__io, mmd_vmd_t* p__parent, mmd_vmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_vmd_t::header_t::_read() {
    m_magic = m__io->read_bytes(30);
    if (!(magic() == std::string("\x56\x6F\x63\x61\x6C\x6F\x69\x64\x20\x4D\x6F\x74\x69\x6F\x6E\x20\x44\x61\x74\x61\x20\x30\x30\x30\x32\x00\x00\x00\x00\x00", 30))) {
       return;
    }
    m_name = kaitai::kstream::bytes_to_str(kaitai::kstream::bytes_terminate(m__io->read_bytes(20), 0, false), std::string("Shift_JIS"));
}

mmd_vmd_t::header_t::~header_t() {
    _clean_up();
}

void mmd_vmd_t::header_t::_clean_up() {
}

mmd_vmd_t::vec3_t::vec3_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, mmd_vmd_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void mmd_vmd_t::vec3_t::_read() {
    m_x = m__io->read_f4le();
    m_y = m__io->read_f4le();
    m_z = m__io->read_f4le();
}

mmd_vmd_t::vec3_t::~vec3_t() {
    _clean_up();
}

void mmd_vmd_t::vec3_t::_clean_up() {
}
