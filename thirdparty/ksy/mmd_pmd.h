#pragma once

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <memory>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

/**
 * PMD is the older format for storing MikuMikuDance (MMD) model data.
 */

class mmd_pmd_t : public kaitai::kstruct {

public:
    class english_morph_name_t;
    class vec4_t;
    class vertex_t;
    class toon_texture_t;
    class english_bone_frame_name_t;
    class color4_t;
    class english_header_t;
    class morph_frame_t;
    class bone_t;
    class face_t;
    class color3_t;
    class morph_t;
    class vec2_t;
    class bone_frame_t;
    class morph_element_t;
    class header_t;
    class constraint_t;
    class material_t;
    class vec3_t;
    class english_bone_name_t;
    class rigid_body_t;
    class bone_frame_name_t;
    class ik_t;

    mmd_pmd_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

private:
    void _read();
    void _clean_up();

public:
    ~mmd_pmd_t();

    class english_morph_name_t : public kaitai::kstruct {

    public:

        english_morph_name_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~english_morph_name_t();

    private:
        std::string m_name;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        std::string name() const { return m_name; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class vec4_t : public kaitai::kstruct {

    public:

        vec4_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~vec4_t();

    private:
        float m_x;
        float m_y;
        float m_z;
        float m_w;
        mmd_pmd_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        float x() const { return m_x; }
        float y() const { return m_y; }
        float z() const { return m_z; }
        float w() const { return m_w; }
        mmd_pmd_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class vertex_t : public kaitai::kstruct {

    public:

        vertex_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~vertex_t();

    private:
        std::unique_ptr<vec3_t> m_position;
        std::unique_ptr<vec3_t> m_normal;
        std::unique_ptr<vec2_t> m_uv;
        std::unique_ptr<std::vector<uint16_t>> m_skin_indices;
        uint8_t m_skin_weights;
        uint8_t m_edge_flag;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        vec3_t* position() const { return m_position.get(); }
        vec3_t* normal() const { return m_normal.get(); }
        vec2_t* uv() const { return m_uv.get(); }
        std::vector<uint16_t>* skin_indices() const { return m_skin_indices.get(); }
        uint8_t skin_weights() const { return m_skin_weights; }
        uint8_t edge_flag() const { return m_edge_flag; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class toon_texture_t : public kaitai::kstruct {

    public:

        toon_texture_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~toon_texture_t();

    private:
        std::string m_file_name;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        std::string file_name() const { return m_file_name; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class english_bone_frame_name_t : public kaitai::kstruct {

    public:

        english_bone_frame_name_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~english_bone_frame_name_t();

    private:
        std::string m_name;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        std::string name() const { return m_name; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class color4_t : public kaitai::kstruct {

    public:

        color4_t(kaitai::kstream* p__io, mmd_pmd_t::material_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~color4_t();

    private:
        float m_r;
        float m_g;
        float m_b;
        float m_a;
        mmd_pmd_t* m__root;
        mmd_pmd_t::material_t* m__parent;

    public:
        float r() const { return m_r; }
        float g() const { return m_g; }
        float b() const { return m_b; }
        float a() const { return m_a; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t::material_t* _parent() const { return m__parent; }
    };

    class english_header_t : public kaitai::kstruct {

    public:

        english_header_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~english_header_t();

    private:
        uint8_t m_compatibility;
        std::string m_model_name;
        bool n_model_name;

    public:
        bool _is_null_model_name() { model_name(); return n_model_name; };

    private:
        std::string m_comment;
        bool n_comment;

    public:
        bool _is_null_comment() { comment(); return n_comment; };

    private:
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        uint8_t compatibility() const { return m_compatibility; }
        std::string model_name() const { return m_model_name; }
        std::string comment() const { return m_comment; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class morph_frame_t : public kaitai::kstruct {

    public:

        morph_frame_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~morph_frame_t();

    private:
        uint16_t m_index;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        uint16_t index() const { return m_index; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class bone_t : public kaitai::kstruct {

    public:

        bone_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~bone_t();

    private:
        std::string m_name;
        uint16_t m_parent_index;
        uint16_t m_tail_index;
        uint8_t m_type;
        uint16_t m_ik_index;
        std::unique_ptr<vec3_t> m_position;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        std::string name() const { return m_name; }
        uint16_t parent_index() const { return m_parent_index; }
        uint16_t tail_index() const { return m_tail_index; }
        uint8_t type() const { return m_type; }
        uint16_t ik_index() const { return m_ik_index; }
        vec3_t* position() const { return m_position.get(); }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class face_t : public kaitai::kstruct {

    public:

        face_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~face_t();

    private:
        std::unique_ptr<std::vector<uint16_t>> m_indices;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        std::vector<uint16_t>* indices() const { return m_indices.get(); }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class color3_t : public kaitai::kstruct {

    public:

        color3_t(kaitai::kstream* p__io, mmd_pmd_t::material_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~color3_t();

    private:
        float m_r;
        float m_g;
        float m_b;
        mmd_pmd_t* m__root;
        mmd_pmd_t::material_t* m__parent;

    public:
        float r() const { return m_r; }
        float g() const { return m_g; }
        float b() const { return m_b; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t::material_t* _parent() const { return m__parent; }
    };

    class morph_t : public kaitai::kstruct {

    public:

        morph_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~morph_t();

    private:
        std::string m_name;
        uint32_t m_element_count;
        uint8_t m_type;
        std::unique_ptr<std::vector<std::unique_ptr<morph_element_t>>> m_elements;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        std::string name() const { return m_name; }
        uint32_t element_count() const { return m_element_count; }
        uint8_t type() const { return m_type; }
        std::vector<std::unique_ptr<morph_element_t>>* elements() const { return m_elements.get(); }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class vec2_t : public kaitai::kstruct {

    public:

        vec2_t(kaitai::kstream* p__io, mmd_pmd_t::vertex_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~vec2_t();

    private:
        float m_x;
        float m_y;
        mmd_pmd_t* m__root;
        mmd_pmd_t::vertex_t* m__parent;

    public:
        float x() const { return m_x; }
        float y() const { return m_y; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t::vertex_t* _parent() const { return m__parent; }
    };

    class bone_frame_t : public kaitai::kstruct {

    public:

        bone_frame_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~bone_frame_t();

    private:
        uint16_t m_bone_index;
        uint8_t m_frame_index;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        uint16_t bone_index() const { return m_bone_index; }
        uint8_t frame_index() const { return m_frame_index; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class morph_element_t : public kaitai::kstruct {

    public:

        morph_element_t(kaitai::kstream* p__io, mmd_pmd_t::morph_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~morph_element_t();

    private:
        uint32_t m_index;
        std::unique_ptr<vec3_t> m_position;
        mmd_pmd_t* m__root;
        mmd_pmd_t::morph_t* m__parent;

    public:
        uint32_t index() const { return m_index; }
        vec3_t* position() const { return m_position.get(); }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t::morph_t* _parent() const { return m__parent; }
    };

    class header_t : public kaitai::kstruct {

    public:

        header_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~header_t();

    private:
        std::string m_magic;
        uint32_t m_version;
        std::string m_model_name;
        std::string m_comment;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t version() const { return m_version; }
        std::string model_name() const { return m_model_name; }
        std::string comment() const { return m_comment; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class constraint_t : public kaitai::kstruct {

    public:

        constraint_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~constraint_t();

    private:
        std::string m_name;
        std::unique_ptr<std::vector<uint32_t>> m_rigid_body_indices;
        std::unique_ptr<vec3_t> m_position;
        std::unique_ptr<vec3_t> m_rotation;
        std::unique_ptr<vec3_t> m_translation_limitation_lower;
        std::unique_ptr<vec3_t> m_translation_limitation_upper;
        std::unique_ptr<vec3_t> m_rotation_limitation_lower;
        std::unique_ptr<vec3_t> m_rotation_limitation_upper;
        std::unique_ptr<vec3_t> m_spring_position;
        std::unique_ptr<vec3_t> m_spring_rotation;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        std::string name() const { return m_name; }
        std::vector<uint32_t>* rigid_body_indices() const { return m_rigid_body_indices.get(); }
        vec3_t* position() const { return m_position.get(); }
        vec3_t* rotation() const { return m_rotation.get(); }
        vec3_t* translation_limitation_lower() const { return m_translation_limitation_lower.get(); }
        vec3_t* translation_limitation_upper() const { return m_translation_limitation_upper.get(); }
        vec3_t* rotation_limitation_lower() const { return m_rotation_limitation_lower.get(); }
        vec3_t* rotation_limitation_upper() const { return m_rotation_limitation_upper.get(); }
        vec3_t* spring_position() const { return m_spring_position.get(); }
        vec3_t* spring_rotation() const { return m_spring_rotation.get(); }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class material_t : public kaitai::kstruct {

    public:

        material_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~material_t();

    private:
        std::unique_ptr<color4_t> m_diffuse;
        float m_shininess;
        std::unique_ptr<color3_t> m_specular;
        std::unique_ptr<color3_t> m_ambient;
        uint8_t m_toon_index;
        uint8_t m_edge_flag;
        uint32_t m_face_vertex_count;
        std::string m_file_name;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        color4_t* diffuse() const { return m_diffuse.get(); }
        float shininess() const { return m_shininess; }
        color3_t* specular() const { return m_specular.get(); }
        color3_t* ambient() const { return m_ambient.get(); }
        uint8_t toon_index() const { return m_toon_index; }
        uint8_t edge_flag() const { return m_edge_flag; }
        uint32_t face_vertex_count() const { return m_face_vertex_count; }
        std::string file_name() const { return m_file_name; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class vec3_t : public kaitai::kstruct {

    public:

        vec3_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~vec3_t();

    private:
        float m_x;
        float m_y;
        float m_z;
        mmd_pmd_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        float x() const { return m_x; }
        float y() const { return m_y; }
        float z() const { return m_z; }
        mmd_pmd_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class english_bone_name_t : public kaitai::kstruct {

    public:

        english_bone_name_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~english_bone_name_t();

    private:
        std::string m_name;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        std::string name() const { return m_name; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class rigid_body_t : public kaitai::kstruct {

    public:

        rigid_body_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~rigid_body_t();

    private:
        std::string m_name;
        uint16_t m_bone_index;
        uint8_t m_group_index;
        uint16_t m_group_target;
        uint8_t m_shape_type;
        float m_width;
        float m_height;
        float m_depth;
        std::unique_ptr<vec3_t> m_position;
        std::unique_ptr<vec3_t> m_rotation;
        float m_weight;
        float m_position_damping;
        float m_rotation_damping;
        float m_restitution;
        float m_friction;
        uint8_t m_type;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        std::string name() const { return m_name; }
        uint16_t bone_index() const { return m_bone_index; }
        uint8_t group_index() const { return m_group_index; }
        uint16_t group_target() const { return m_group_target; }
        uint8_t shape_type() const { return m_shape_type; }
        float width() const { return m_width; }
        float height() const { return m_height; }
        float depth() const { return m_depth; }
        vec3_t* position() const { return m_position.get(); }
        vec3_t* rotation() const { return m_rotation.get(); }
        float weight() const { return m_weight; }
        float position_damping() const { return m_position_damping; }
        float rotation_damping() const { return m_rotation_damping; }
        float restitution() const { return m_restitution; }
        float friction() const { return m_friction; }
        uint8_t type() const { return m_type; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class bone_frame_name_t : public kaitai::kstruct {

    public:

        bone_frame_name_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~bone_frame_name_t();

    private:
        std::string m_name;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        std::string name() const { return m_name; }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

    class ik_t : public kaitai::kstruct {

    public:

        ik_t(kaitai::kstream* p__io, mmd_pmd_t* p__parent = nullptr, mmd_pmd_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~ik_t();

    private:
        uint16_t m_target;
        uint16_t m_effector;
        uint8_t m_link_count;
        uint16_t m_iteration;
        float m_max_angle;
        std::unique_ptr<std::vector<uint16_t>> m_link_indices;
        mmd_pmd_t* m__root;
        mmd_pmd_t* m__parent;

    public:
        uint16_t target() const { return m_target; }
        uint16_t effector() const { return m_effector; }
        uint8_t link_count() const { return m_link_count; }
        uint16_t iteration() const { return m_iteration; }
        float max_angle() const { return m_max_angle; }
        std::vector<uint16_t>* link_indices() const { return m_link_indices.get(); }
        mmd_pmd_t* _root() const { return m__root; }
        mmd_pmd_t* _parent() const { return m__parent; }
    };

private:
    std::unique_ptr<header_t> m_header;
    uint32_t m_vertex_count;
    std::unique_ptr<std::vector<std::unique_ptr<vertex_t>>> m_vertices;
    uint32_t m_face_vertex_count;
    std::unique_ptr<std::vector<std::unique_ptr<face_t>>> m_faces;
    uint32_t m_material_count;
    std::unique_ptr<std::vector<std::unique_ptr<material_t>>> m_materials;
    uint16_t m_bone_count;
    std::unique_ptr<std::vector<std::unique_ptr<bone_t>>> m_bones;
    uint16_t m_ik_count;
    std::unique_ptr<std::vector<std::unique_ptr<ik_t>>> m_iks;
    uint16_t m_morph_count;
    std::unique_ptr<std::vector<std::unique_ptr<morph_t>>> m_morphs;
    uint8_t m_morph_frame_count;
    std::unique_ptr<std::vector<std::unique_ptr<morph_frame_t>>> m_morph_frames;
    uint8_t m_bone_frame_name_count;
    std::unique_ptr<std::vector<std::unique_ptr<bone_frame_name_t>>> m_bone_frame_names;
    uint32_t m_bone_frame_count;
    std::unique_ptr<std::vector<std::unique_ptr<bone_frame_t>>> m_bone_frames;
    std::unique_ptr<english_header_t> m_english_header;
    std::unique_ptr<std::vector<std::unique_ptr<english_bone_name_t>>> m_english_bone_names;
    bool n_english_bone_names;

public:
    bool _is_null_english_bone_names() { english_bone_names(); return n_english_bone_names; };

private:
    std::unique_ptr<std::vector<std::unique_ptr<english_morph_name_t>>> m_english_morph_names;
    bool n_english_morph_names;

public:
    bool _is_null_english_morph_names() { english_morph_names(); return n_english_morph_names; };

private:
    std::unique_ptr<std::vector<std::unique_ptr<english_bone_frame_name_t>>> m_english_bone_frame_names;
    bool n_english_bone_frame_names;

public:
    bool _is_null_english_bone_frame_names() { english_bone_frame_names(); return n_english_bone_frame_names; };

private:
    std::unique_ptr<std::vector<std::unique_ptr<toon_texture_t>>> m_toon_textures;
    uint32_t m_rigid_body_count;
    std::unique_ptr<std::vector<std::unique_ptr<rigid_body_t>>> m_rigid_bodies;
    uint32_t m_constraint_count;
    std::unique_ptr<std::vector<std::unique_ptr<constraint_t>>> m_constraints;
    mmd_pmd_t* m__root;
    kaitai::kstruct* m__parent;

public:
    header_t* header() const { return m_header.get(); }
    uint32_t vertex_count() const { return m_vertex_count; }
    std::vector<std::unique_ptr<vertex_t>>* vertices() const { return m_vertices.get(); }
    uint32_t face_vertex_count() const { return m_face_vertex_count; }
    std::vector<std::unique_ptr<face_t>>* faces() const { return m_faces.get(); }
    uint32_t material_count() const { return m_material_count; }
    std::vector<std::unique_ptr<material_t>>* materials() const { return m_materials.get(); }
    uint16_t bone_count() const { return m_bone_count; }
    std::vector<std::unique_ptr<bone_t>>* bones() const { return m_bones.get(); }
    uint16_t ik_count() const { return m_ik_count; }
    std::vector<std::unique_ptr<ik_t>>* iks() const { return m_iks.get(); }
    uint16_t morph_count() const { return m_morph_count; }
    std::vector<std::unique_ptr<morph_t>>* morphs() const { return m_morphs.get(); }
    uint8_t morph_frame_count() const { return m_morph_frame_count; }
    std::vector<std::unique_ptr<morph_frame_t>>* morph_frames() const { return m_morph_frames.get(); }
    uint8_t bone_frame_name_count() const { return m_bone_frame_name_count; }
    std::vector<std::unique_ptr<bone_frame_name_t>>* bone_frame_names() const { return m_bone_frame_names.get(); }
    uint32_t bone_frame_count() const { return m_bone_frame_count; }
    std::vector<std::unique_ptr<bone_frame_t>>* bone_frames() const { return m_bone_frames.get(); }
    english_header_t* english_header() const { return m_english_header.get(); }
    std::vector<std::unique_ptr<english_bone_name_t>>* english_bone_names() const { return m_english_bone_names.get(); }
    std::vector<std::unique_ptr<english_morph_name_t>>* english_morph_names() const { return m_english_morph_names.get(); }
    std::vector<std::unique_ptr<english_bone_frame_name_t>>* english_bone_frame_names() const { return m_english_bone_frame_names.get(); }
    std::vector<std::unique_ptr<toon_texture_t>>* toon_textures() const { return m_toon_textures.get(); }
    uint32_t rigid_body_count() const { return m_rigid_body_count; }
    std::vector<std::unique_ptr<rigid_body_t>>* rigid_bodies() const { return m_rigid_bodies.get(); }
    uint32_t constraint_count() const { return m_constraint_count; }
    std::vector<std::unique_ptr<constraint_t>>* constraints() const { return m_constraints.get(); }
    mmd_pmd_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};
