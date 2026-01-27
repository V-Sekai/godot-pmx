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
 * PMX is the newer format for storing MikuMikuDance (MMD) model data.
 * Its main improvement over the prior PMD format was that strings are
 * now encoded in UTF-16 instead of Shift_JIS, and index arrays were
 * made somewhat more compact.
 * \sa https://gist.github.com/felixjones/f8a06bd48f9da9a4539f Source
 */

class mmd_pmx_t : public kaitai::kstruct {

public:
    class bone_ik_link_t;
    class vec4_t;
    class bdef1_weights_t;
    class vertex_t;
    class material_morph_element_t;
    class bone_morph_element_t;
    class color4_t;
    class bone_grant_t;
    class vertex_morph_element_t;
    class sdef_weights_t;
    class group_morph_element_t;
    class joint_t;
    class bone_t;
    class frame_t;
    class qdef_weights_t;
    class face_t;
    class color3_t;
    class morph_t;
    class vec2_t;
    class frame_element_t;
    class impulse_morph_element_t;
    class bone_ik_t;
    class uv_morph_element_t;
    class bdef2_weights_t;
    class header_t;
    class common_toon_index_t;
    class material_t;
    class vec3_t;
    class sized_index_t;
    class bdef4_weights_t;
    class rigid_body_t;
    class texture_t;
    class len_string_t;

    enum sphere_op_mode_t {
        SPHERE_OP_MODE_DISABLED = 0,
        SPHERE_OP_MODE_MULTIPLY = 1,
        SPHERE_OP_MODE_ADD = 2,
        SPHERE_OP_MODE_SUBTEXTURE = 3
    };

    enum index_id_t {
        INDEX_ID_VERTEX = 1,
        INDEX_ID_TEXTURE = 2,
        INDEX_ID_MATERIAL = 3,
        INDEX_ID_BONE = 4,
        INDEX_ID_MORPH = 5,
        INDEX_ID_RIGID_BODY = 6
    };

    enum joint_type_t {
        JOINT_TYPE_SPRING_SIXDOF = 0,
        JOINT_TYPE_SIXDOF = 1,
        JOINT_TYPE_P2P = 2,
        JOINT_TYPE_CONE_TWIST = 3,
        JOINT_TYPE_SLIDER = 4,
        JOINT_TYPE_HINGE = 5
    };

    enum morph_type_t {
        MORPH_TYPE_GROUP = 0,
        MORPH_TYPE_VERTEX = 1,
        MORPH_TYPE_BONE = 2,
        MORPH_TYPE_UV = 3,
        MORPH_TYPE_ADDITIONAL_UV1 = 4,
        MORPH_TYPE_ADDITIONAL_UV2 = 5,
        MORPH_TYPE_ADDITIONAL_UV3 = 6,
        MORPH_TYPE_ADDITIONAL_UV4 = 7,
        MORPH_TYPE_MATERIAL = 8,
        MORPH_TYPE_FLIP = 9,
        MORPH_TYPE_IMPULSE = 10
    };

    enum bone_type_t {
        BONE_TYPE_BDEF1 = 0,
        BONE_TYPE_BDEF2 = 1,
        BONE_TYPE_BDEF4 = 2,
        BONE_TYPE_SDEF = 3,
        BONE_TYPE_QDEF = 4
    };

    mmd_pmx_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

private:
    void _read();
    void _clean_up();

public:
    ~mmd_pmx_t();

    class bone_ik_link_t : public kaitai::kstruct {

    public:

        bone_ik_link_t(kaitai::kstream* p__io, mmd_pmx_t::bone_ik_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~bone_ik_link_t();

    private:
        std::unique_ptr<sized_index_t> m_index;
        uint8_t m_angle_limitation;
        std::unique_ptr<vec3_t> m_lower_limitation_angle;
        bool n_lower_limitation_angle;

    public:
        bool _is_null_lower_limitation_angle() { lower_limitation_angle(); return n_lower_limitation_angle; };

    private:
        std::unique_ptr<vec3_t> m_upper_limitation_angle;
        bool n_upper_limitation_angle;

    public:
        bool _is_null_upper_limitation_angle() { upper_limitation_angle(); return n_upper_limitation_angle; };

    private:
        mmd_pmx_t* m__root;
        mmd_pmx_t::bone_ik_t* m__parent;

    public:
        sized_index_t* index() const { return m_index.get(); }
        uint8_t angle_limitation() const { return m_angle_limitation; }
        vec3_t* lower_limitation_angle() const { return m_lower_limitation_angle.get(); }
        vec3_t* upper_limitation_angle() const { return m_upper_limitation_angle.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::bone_ik_t* _parent() const { return m__parent; }
    };

    class vec4_t : public kaitai::kstruct {

    public:

        vec4_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

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
        mmd_pmx_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        float x() const { return m_x; }
        float y() const { return m_y; }
        float z() const { return m_z; }
        float w() const { return m_w; }
        mmd_pmx_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class bdef1_weights_t : public kaitai::kstruct {

    public:

        bdef1_weights_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~bdef1_weights_t();

    private:
        std::unique_ptr<sized_index_t> m_bone_index;
        mmd_pmx_t* m__root;
        mmd_pmx_t::vertex_t* m__parent;

    public:

        /**
         * The weight of the bone will be 1.0
         */
        sized_index_t* bone_index() const { return m_bone_index.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::vertex_t* _parent() const { return m__parent; }
    };

    class vertex_t : public kaitai::kstruct {

    public:

        vertex_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~vertex_t();

    private:
        std::unique_ptr<vec3_t> m_position;
        std::unique_ptr<vec3_t> m_normal;
        std::unique_ptr<vec2_t> m_uv;
        std::unique_ptr<std::vector<std::unique_ptr<vec4_t>>> m_additional_uvs;
        bone_type_t m_type;
        std::unique_ptr<kaitai::kstruct> m_skin_weights;
        bool n_skin_weights;

    public:
        bool _is_null_skin_weights() { skin_weights(); return n_skin_weights; };

    private:
        float m_edge_ratio;
        mmd_pmx_t* m__root;
        mmd_pmx_t* m__parent;

    public:
        vec3_t* position() const { return m_position.get(); }

        /**
         * normal vector, which is supposed to be normalized.
         */
        vec3_t* normal() const { return m_normal.get(); }

        /**
         * texture coordinate.
         */
        vec2_t* uv() const { return m_uv.get(); }
        std::vector<std::unique_ptr<vec4_t>>* additional_uvs() const { return m_additional_uvs.get(); }
        bone_type_t type() const { return m_type; }
        kaitai::kstruct* skin_weights() const { return m_skin_weights.get(); }
        float edge_ratio() const { return m_edge_ratio; }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t* _parent() const { return m__parent; }
    };

    class material_morph_element_t : public kaitai::kstruct {

    public:

        material_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~material_morph_element_t();

    private:
        std::unique_ptr<sized_index_t> m_index;
        uint8_t m_type;
        std::unique_ptr<color4_t> m_diffuse;
        std::unique_ptr<color3_t> m_specular;
        float m_shininess;
        std::unique_ptr<color3_t> m_ambient;
        std::unique_ptr<color4_t> m_edge_color;
        float m_edge_size;
        std::unique_ptr<color4_t> m_texture_color;
        std::unique_ptr<color4_t> m_sphere_texture_color;
        std::unique_ptr<color4_t> m_toon_color;
        mmd_pmx_t* m__root;
        mmd_pmx_t::morph_t* m__parent;

    public:
        sized_index_t* index() const { return m_index.get(); }

        /**
         * 0 = Multiply, 1 = Additive
         */
        uint8_t type() const { return m_type; }
        color4_t* diffuse() const { return m_diffuse.get(); }
        color3_t* specular() const { return m_specular.get(); }
        float shininess() const { return m_shininess; }
        color3_t* ambient() const { return m_ambient.get(); }
        color4_t* edge_color() const { return m_edge_color.get(); }
        float edge_size() const { return m_edge_size; }
        color4_t* texture_color() const { return m_texture_color.get(); }
        color4_t* sphere_texture_color() const { return m_sphere_texture_color.get(); }
        color4_t* toon_color() const { return m_toon_color.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::morph_t* _parent() const { return m__parent; }
    };

    class bone_morph_element_t : public kaitai::kstruct {

    public:

        bone_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~bone_morph_element_t();

    private:
        std::unique_ptr<sized_index_t> m_index;
        std::unique_ptr<vec3_t> m_position;
        std::unique_ptr<vec4_t> m_rotation;
        mmd_pmx_t* m__root;
        mmd_pmx_t::morph_t* m__parent;

    public:
        sized_index_t* index() const { return m_index.get(); }
        vec3_t* position() const { return m_position.get(); }
        vec4_t* rotation() const { return m_rotation.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::morph_t* _parent() const { return m__parent; }
    };

    class color4_t : public kaitai::kstruct {

    public:

        color4_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

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
        mmd_pmx_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        float r() const { return m_r; }
        float g() const { return m_g; }
        float b() const { return m_b; }
        float a() const { return m_a; }
        mmd_pmx_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Another project commented that this wasn't a good name. I'm not sure
     * either way. What this element _appears_ to do is grant additional motion
     * to a bone based on another bone, where those bones are not otherwise
     * related.
     * For example, you might have a watch hand spin at 1/12 the rate
     * of another watch hand, even though both hands are parented to the watch,
     * neither to each other.
     */

    class bone_grant_t : public kaitai::kstruct {

    public:

        bone_grant_t(kaitai::kstream* p__io, mmd_pmx_t::bone_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~bone_grant_t();

    private:
        bool f_local;
        bool m_local;

    public:
        bool local();

    private:
        bool f_affect_rotation;
        bool m_affect_rotation;

    public:
        bool affect_rotation();

    private:
        bool f_affect_position;
        bool m_affect_position;

    public:
        bool affect_position();

    private:
        std::unique_ptr<sized_index_t> m_parent_index;
        float m_ratio;
        mmd_pmx_t* m__root;
        mmd_pmx_t::bone_t* m__parent;

    public:
        sized_index_t* parent_index() const { return m_parent_index.get(); }
        float ratio() const { return m_ratio; }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::bone_t* _parent() const { return m__parent; }
    };

    class vertex_morph_element_t : public kaitai::kstruct {

    public:

        vertex_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~vertex_morph_element_t();

    private:
        std::unique_ptr<sized_index_t> m_index;
        std::unique_ptr<vec3_t> m_position;
        mmd_pmx_t* m__root;
        mmd_pmx_t::morph_t* m__parent;

    public:
        sized_index_t* index() const { return m_index.get(); }
        vec3_t* position() const { return m_position.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::morph_t* _parent() const { return m__parent; }
    };

    class sdef_weights_t : public kaitai::kstruct {

    public:

        sdef_weights_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~sdef_weights_t();

    private:
        bool f_weights;
        std::unique_ptr<std::vector<double>> m_weights;

    public:
        std::vector<double>* weights();

    private:
        std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>> m_bone_indices;
        float m_weight1;
        std::unique_ptr<vec3_t> m_c;
        std::unique_ptr<vec3_t> m_r0;
        std::unique_ptr<vec3_t> m_r1;
        mmd_pmx_t* m__root;
        mmd_pmx_t::vertex_t* m__parent;

    public:
        std::vector<std::unique_ptr<sized_index_t>>* bone_indices() const { return m_bone_indices.get(); }
        float weight1() const { return m_weight1; }
        vec3_t* c() const { return m_c.get(); }
        vec3_t* r0() const { return m_r0.get(); }
        vec3_t* r1() const { return m_r1.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::vertex_t* _parent() const { return m__parent; }
    };

    class group_morph_element_t : public kaitai::kstruct {

    public:

        group_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~group_morph_element_t();

    private:
        std::unique_ptr<sized_index_t> m_index;
        float m_ratio;
        mmd_pmx_t* m__root;
        mmd_pmx_t::morph_t* m__parent;

    public:
        sized_index_t* index() const { return m_index.get(); }
        float ratio() const { return m_ratio; }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::morph_t* _parent() const { return m__parent; }
    };

    class joint_t : public kaitai::kstruct {

    public:

        joint_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~joint_t();

    private:
        std::unique_ptr<len_string_t> m_name;
        std::unique_ptr<len_string_t> m_english_name;
        joint_type_t m_type;
        std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>> m_rigid_body_indices;
        std::unique_ptr<vec3_t> m_position;
        std::unique_ptr<vec3_t> m_rotation;
        std::unique_ptr<vec3_t> m_position_constraint_lower;
        std::unique_ptr<vec3_t> m_position_constraint_upper;
        std::unique_ptr<vec3_t> m_rotation_constraint_lower;
        std::unique_ptr<vec3_t> m_rotation_constraint_upper;
        std::unique_ptr<vec3_t> m_spring_position;
        std::unique_ptr<vec3_t> m_spring_rotation;
        mmd_pmx_t* m__root;
        mmd_pmx_t* m__parent;

    public:
        len_string_t* name() const { return m_name.get(); }
        len_string_t* english_name() const { return m_english_name.get(); }
        joint_type_t type() const { return m_type; }
        std::vector<std::unique_ptr<sized_index_t>>* rigid_body_indices() const { return m_rigid_body_indices.get(); }
        vec3_t* position() const { return m_position.get(); }
        vec3_t* rotation() const { return m_rotation.get(); }
        vec3_t* position_constraint_lower() const { return m_position_constraint_lower.get(); }
        vec3_t* position_constraint_upper() const { return m_position_constraint_upper.get(); }
        vec3_t* rotation_constraint_lower() const { return m_rotation_constraint_lower.get(); }
        vec3_t* rotation_constraint_upper() const { return m_rotation_constraint_upper.get(); }
        vec3_t* spring_position() const { return m_spring_position.get(); }
        vec3_t* spring_rotation() const { return m_spring_rotation.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t* _parent() const { return m__parent; }
    };

    class bone_t : public kaitai::kstruct {

    public:

        bone_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~bone_t();

    private:
        std::unique_ptr<len_string_t> m_name;
        std::unique_ptr<len_string_t> m_english_name;
        std::unique_ptr<vec3_t> m_position;
        std::unique_ptr<sized_index_t> m_parent_index;
        uint32_t m_transformation_class;
        bool m_indexed_tail_position;
        bool m_rotatable;
        bool m_translatable;
        bool m_visible;
        bool m_enabled;
        bool m_has_ik;
        bool m_unknown6;
        bool m_add_local_deform;
        bool m_inherit_rotation;
        bool m_inherit_translation;
        bool m_has_fixed_axis;
        bool m_has_local_axes;
        bool m_physics_after_deform;
        bool m_external_parent_deform;
        uint64_t m_reserved;
        std::unique_ptr<sized_index_t> m_connect_index;
        bool n_connect_index;

    public:
        bool _is_null_connect_index() { connect_index(); return n_connect_index; };

    private:
        std::unique_ptr<vec3_t> m_offset_position;
        bool n_offset_position;

    public:
        bool _is_null_offset_position() { offset_position(); return n_offset_position; };

    private:
        std::unique_ptr<bone_grant_t> m_grant;
        bool n_grant;

    public:
        bool _is_null_grant() { grant(); return n_grant; };

    private:
        std::unique_ptr<vec3_t> m_fixed_axis;
        bool n_fixed_axis;

    public:
        bool _is_null_fixed_axis() { fixed_axis(); return n_fixed_axis; };

    private:
        std::unique_ptr<vec3_t> m_local_x_vector;
        bool n_local_x_vector;

    public:
        bool _is_null_local_x_vector() { local_x_vector(); return n_local_x_vector; };

    private:
        std::unique_ptr<vec3_t> m_local_z_vector;
        bool n_local_z_vector;

    public:
        bool _is_null_local_z_vector() { local_z_vector(); return n_local_z_vector; };

    private:
        uint32_t m_key;
        bool n_key;

    public:
        bool _is_null_key() { key(); return n_key; };

    private:
        std::unique_ptr<bone_ik_t> m_ik;
        bool n_ik;

    public:
        bool _is_null_ik() { ik(); return n_ik; };

    private:
        mmd_pmx_t* m__root;
        mmd_pmx_t* m__parent;

    public:
        len_string_t* name() const { return m_name.get(); }
        len_string_t* english_name() const { return m_english_name.get(); }
        vec3_t* position() const { return m_position.get(); }
        sized_index_t* parent_index() const { return m_parent_index.get(); }
        uint32_t transformation_class() const { return m_transformation_class; }

        /**
         * Is the tail position a vec3 or bone index
         */
        bool indexed_tail_position() const { return m_indexed_tail_position; }

        /**
         * Enables rotation
         */
        bool rotatable() const { return m_rotatable; }

        /**
         * Enables translation
         */
        bool translatable() const { return m_translatable; }
        bool visible() const { return m_visible; }
        bool enabled() const { return m_enabled; }
        bool has_ik() const { return m_has_ik; }
        bool unknown6() const { return m_unknown6; }
        bool add_local_deform() const { return m_add_local_deform; }

        /**
         * Rotation inherits from another bone
         */
        bool inherit_rotation() const { return m_inherit_rotation; }

        /**
         * Translation inherits from another bone
         */
        bool inherit_translation() const { return m_inherit_translation; }

        /**
         * The bone's shaft is fixed in a direction
         */
        bool has_fixed_axis() const { return m_has_fixed_axis; }
        bool has_local_axes() const { return m_has_local_axes; }
        bool physics_after_deform() const { return m_physics_after_deform; }
        bool external_parent_deform() const { return m_external_parent_deform; }
        uint64_t reserved() const { return m_reserved; }
        sized_index_t* connect_index() const { return m_connect_index.get(); }
        vec3_t* offset_position() const { return m_offset_position.get(); }
        bone_grant_t* grant() const { return m_grant.get(); }
        vec3_t* fixed_axis() const { return m_fixed_axis.get(); }
        vec3_t* local_x_vector() const { return m_local_x_vector.get(); }
        vec3_t* local_z_vector() const { return m_local_z_vector.get(); }
        uint32_t key() const { return m_key; }
        bone_ik_t* ik() const { return m_ik.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t* _parent() const { return m__parent; }
    };

    class frame_t : public kaitai::kstruct {

    public:

        frame_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~frame_t();

    private:
        std::unique_ptr<len_string_t> m_name;
        std::unique_ptr<len_string_t> m_english_name;
        uint8_t m_type;
        uint32_t m_element_count;
        std::unique_ptr<std::vector<std::unique_ptr<frame_element_t>>> m_elements;
        mmd_pmx_t* m__root;
        mmd_pmx_t* m__parent;

    public:
        len_string_t* name() const { return m_name.get(); }
        len_string_t* english_name() const { return m_english_name.get(); }
        uint8_t type() const { return m_type; }
        uint32_t element_count() const { return m_element_count; }
        std::vector<std::unique_ptr<frame_element_t>>* elements() const { return m_elements.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t* _parent() const { return m__parent; }
    };

    /**
     * Since 2.1
     */

    class qdef_weights_t : public kaitai::kstruct {

    public:

        qdef_weights_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~qdef_weights_t();

    private:
        std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>> m_bone_indices;
        std::unique_ptr<std::vector<float>> m_weights;
        mmd_pmx_t* m__root;
        mmd_pmx_t::vertex_t* m__parent;

    public:
        std::vector<std::unique_ptr<sized_index_t>>* bone_indices() const { return m_bone_indices.get(); }
        std::vector<float>* weights() const { return m_weights.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::vertex_t* _parent() const { return m__parent; }
    };

    class face_t : public kaitai::kstruct {

    public:

        face_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~face_t();

    private:
        std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>> m_indices;
        mmd_pmx_t* m__root;
        mmd_pmx_t* m__parent;

    public:
        std::vector<std::unique_ptr<sized_index_t>>* indices() const { return m_indices.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t* _parent() const { return m__parent; }
    };

    class color3_t : public kaitai::kstruct {

    public:

        color3_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~color3_t();

    private:
        float m_r;
        float m_g;
        float m_b;
        mmd_pmx_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        float r() const { return m_r; }
        float g() const { return m_g; }
        float b() const { return m_b; }
        mmd_pmx_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class morph_t : public kaitai::kstruct {

    public:

        morph_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~morph_t();

    private:
        std::unique_ptr<len_string_t> m_name;
        std::unique_ptr<len_string_t> m_english_name;
        uint8_t m_panel;
        morph_type_t m_type;
        uint32_t m_element_count;
        std::unique_ptr<std::vector<std::unique_ptr<kaitai::kstruct>>> m_elements;
        mmd_pmx_t* m__root;
        mmd_pmx_t* m__parent;

    public:
        len_string_t* name() const { return m_name.get(); }
        len_string_t* english_name() const { return m_english_name.get(); }
        uint8_t panel() const { return m_panel; }
        morph_type_t type() const { return m_type; }
        uint32_t element_count() const { return m_element_count; }
        std::vector<std::unique_ptr<kaitai::kstruct>>* elements() const { return m_elements.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t* _parent() const { return m__parent; }
    };

    class vec2_t : public kaitai::kstruct {

    public:

        vec2_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~vec2_t();

    private:
        float m_x;
        float m_y;
        mmd_pmx_t* m__root;
        mmd_pmx_t::vertex_t* m__parent;

    public:
        float x() const { return m_x; }
        float y() const { return m_y; }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::vertex_t* _parent() const { return m__parent; }
    };

    class frame_element_t : public kaitai::kstruct {

    public:

        frame_element_t(kaitai::kstream* p__io, mmd_pmx_t::frame_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~frame_element_t();

    private:
        uint8_t m_target;
        std::unique_ptr<sized_index_t> m_index;
        mmd_pmx_t* m__root;
        mmd_pmx_t::frame_t* m__parent;

    public:

        /**
         * 0 = target bone, 1 = target morph
         */
        uint8_t target() const { return m_target; }
        sized_index_t* index() const { return m_index.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::frame_t* _parent() const { return m__parent; }
    };

    class impulse_morph_element_t : public kaitai::kstruct {

    public:

        impulse_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~impulse_morph_element_t();

    private:
        std::unique_ptr<sized_index_t> m_rigid_body_index;
        uint8_t m_local;
        std::unique_ptr<vec3_t> m_translational_velocity;
        std::unique_ptr<vec3_t> m_angular_velocity;
        mmd_pmx_t* m__root;
        mmd_pmx_t::morph_t* m__parent;

    public:
        sized_index_t* rigid_body_index() const { return m_rigid_body_index.get(); }
        uint8_t local() const { return m_local; }
        vec3_t* translational_velocity() const { return m_translational_velocity.get(); }

        /**
         * another source had this as torque, but it would be odd for one
         * value to represent a velocity while the other represented a force
         */
        vec3_t* angular_velocity() const { return m_angular_velocity.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::morph_t* _parent() const { return m__parent; }
    };

    class bone_ik_t : public kaitai::kstruct {

    public:

        bone_ik_t(kaitai::kstream* p__io, mmd_pmx_t::bone_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~bone_ik_t();

    private:
        std::unique_ptr<sized_index_t> m_effector;
        uint32_t m_iteration;
        float m_max_angle;
        uint32_t m_link_count;
        std::unique_ptr<std::vector<std::unique_ptr<bone_ik_link_t>>> m_links;
        mmd_pmx_t* m__root;
        mmd_pmx_t::bone_t* m__parent;

    public:
        sized_index_t* effector() const { return m_effector.get(); }
        uint32_t iteration() const { return m_iteration; }
        float max_angle() const { return m_max_angle; }
        uint32_t link_count() const { return m_link_count; }
        std::vector<std::unique_ptr<bone_ik_link_t>>* links() const { return m_links.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::bone_t* _parent() const { return m__parent; }
    };

    class uv_morph_element_t : public kaitai::kstruct {

    public:

        uv_morph_element_t(kaitai::kstream* p__io, mmd_pmx_t::morph_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~uv_morph_element_t();

    private:
        std::unique_ptr<sized_index_t> m_index;
        std::unique_ptr<vec4_t> m_uv;
        mmd_pmx_t* m__root;
        mmd_pmx_t::morph_t* m__parent;

    public:
        sized_index_t* index() const { return m_index.get(); }
        vec4_t* uv() const { return m_uv.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::morph_t* _parent() const { return m__parent; }
    };

    class bdef2_weights_t : public kaitai::kstruct {

    public:

        bdef2_weights_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~bdef2_weights_t();

    private:
        bool f_weights;
        std::unique_ptr<std::vector<double>> m_weights;

    public:
        std::vector<double>* weights();

    private:
        std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>> m_bone_indices;
        float m_weight1;
        mmd_pmx_t* m__root;
        mmd_pmx_t::vertex_t* m__parent;

    public:
        std::vector<std::unique_ptr<sized_index_t>>* bone_indices() const { return m_bone_indices.get(); }
        float weight1() const { return m_weight1; }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::vertex_t* _parent() const { return m__parent; }
    };

    class header_t : public kaitai::kstruct {

    public:

        header_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~header_t();

    private:
        std::string m_magic;
        float m_version;
        uint8_t m_header_size;
        uint8_t m_encoding;
        uint8_t m_additional_uv_count;
        uint8_t m_vertex_index_size;
        uint8_t m_texture_index_size;
        uint8_t m_material_index_size;
        uint8_t m_bone_index_size;
        uint8_t m_morph_index_size;
        uint8_t m_rigid_body_index_size;
        std::unique_ptr<len_string_t> m_model_name;
        std::unique_ptr<len_string_t> m_english_model_name;
        std::unique_ptr<len_string_t> m_comment;
        std::unique_ptr<len_string_t> m_english_comment;
        mmd_pmx_t* m__root;
        mmd_pmx_t* m__parent;

    public:
        std::string magic() const { return m_magic; }

        /**
         * Version of the format as a floating-point number.
         * Can be either 2.0 or 2.1.
         * Specifies the lowest format version capable of reading the file, so
         * don't be surprised to see 2.0 files created recently.
         */
        float version() const { return m_version; }
        uint8_t header_size() const { return m_header_size; }

        /**
         * 0 for UTF-16LE, 1 for UTF-8
         */
        uint8_t encoding() const { return m_encoding; }
        uint8_t additional_uv_count() const { return m_additional_uv_count; }
        uint8_t vertex_index_size() const { return m_vertex_index_size; }
        uint8_t texture_index_size() const { return m_texture_index_size; }
        uint8_t material_index_size() const { return m_material_index_size; }
        uint8_t bone_index_size() const { return m_bone_index_size; }
        uint8_t morph_index_size() const { return m_morph_index_size; }
        uint8_t rigid_body_index_size() const { return m_rigid_body_index_size; }
        len_string_t* model_name() const { return m_model_name.get(); }
        len_string_t* english_model_name() const { return m_english_model_name.get(); }
        len_string_t* comment() const { return m_comment.get(); }
        len_string_t* english_comment() const { return m_english_comment.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t* _parent() const { return m__parent; }
    };

    /**
     * Contains the index of one of the built-in common toon textures
     * shipped with MMD.
     * Exists as a wrapper type as a workaround for a bug in Kaitai:
     * https://github.com/kaitai-io/kaitai_struct/issues/416
     */

    class common_toon_index_t : public kaitai::kstruct {

    public:

        common_toon_index_t(kaitai::kstream* p__io, mmd_pmx_t::material_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~common_toon_index_t();

    private:
        uint8_t m_value;
        mmd_pmx_t* m__root;
        mmd_pmx_t::material_t* m__parent;

    public:
        uint8_t value() const { return m_value; }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::material_t* _parent() const { return m__parent; }
    };

    class material_t : public kaitai::kstruct {

    public:

        material_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~material_t();

    private:
        std::unique_ptr<len_string_t> m_name;
        std::unique_ptr<len_string_t> m_english_name;
        std::unique_ptr<color4_t> m_diffuse;
        std::unique_ptr<color3_t> m_specular;
        float m_shininess;
        std::unique_ptr<color3_t> m_ambient;
        bool m_no_cull;
        bool m_ground_shadow;
        bool m_cast_shadow;
        bool m_receive_shadow;
        bool m_outlined;
        bool m_uses_vertex_color;
        bool m_render_points;
        bool m_render_lines;
        std::unique_ptr<color4_t> m_edge_color;
        float m_edge_size;
        std::unique_ptr<sized_index_t> m_texture_index;
        std::unique_ptr<sized_index_t> m_sphere_texture_index;
        sphere_op_mode_t m_sphere_op_mode;
        uint8_t m_is_common_toon;
        std::unique_ptr<kaitai::kstruct> m_toon_index;
        bool n_toon_index;

    public:
        bool _is_null_toon_index() { toon_index(); return n_toon_index; };

    private:
        std::unique_ptr<len_string_t> m_comment;
        uint32_t m_face_vertex_count;
        mmd_pmx_t* m__root;
        mmd_pmx_t* m__parent;

    public:
        len_string_t* name() const { return m_name.get(); }
        len_string_t* english_name() const { return m_english_name.get(); }
        color4_t* diffuse() const { return m_diffuse.get(); }
        color3_t* specular() const { return m_specular.get(); }
        float shininess() const { return m_shininess; }
        color3_t* ambient() const { return m_ambient.get(); }

        /**
         * Disables back-face culling
         */
        bool no_cull() const { return m_no_cull; }

        /**
         * Projects a shadow onto the ground
         */
        bool ground_shadow() const { return m_ground_shadow; }

        /**
         * Writes to shadow map
         */
        bool cast_shadow() const { return m_cast_shadow; }

        /**
         * Reads from shadow map
         */
        bool receive_shadow() const { return m_receive_shadow; }

        /**
         * Draws pencil outline
         */
        bool outlined() const { return m_outlined; }

        /**
         * Uses additional color4 1 for vertex color (since 2.1)
         */
        bool uses_vertex_color() const { return m_uses_vertex_color; }

        /**
         * Rendered as points (since 2.1)
         */
        bool render_points() const { return m_render_points; }

        /**
         * Rendered as lines (since 2.1)
         */
        bool render_lines() const { return m_render_lines; }
        color4_t* edge_color() const { return m_edge_color.get(); }
        float edge_size() const { return m_edge_size; }
        sized_index_t* texture_index() const { return m_texture_index.get(); }
        sized_index_t* sphere_texture_index() const { return m_sphere_texture_index.get(); }
        sphere_op_mode_t sphere_op_mode() const { return m_sphere_op_mode; }
        uint8_t is_common_toon() const { return m_is_common_toon; }

        /**
         * If using a common toon texture contains an index into one of the
         * common toon textures shipped with MMD.  Otherwise, contains the
         * index of a texture.
         */
        kaitai::kstruct* toon_index() const { return m_toon_index.get(); }
        len_string_t* comment() const { return m_comment.get(); }
        uint32_t face_vertex_count() const { return m_face_vertex_count; }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t* _parent() const { return m__parent; }
    };

    class vec3_t : public kaitai::kstruct {

    public:

        vec3_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~vec3_t();

    private:
        float m_x;
        float m_y;
        float m_z;
        mmd_pmx_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        float x() const { return m_x; }
        float y() const { return m_y; }
        float z() const { return m_z; }
        mmd_pmx_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Variable-length type storing an index of a vertex, bone, etc.
     */

    class sized_index_t : public kaitai::kstruct {

    public:

        sized_index_t(uint8_t p_size, kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~sized_index_t();

    private:
        uint32_t m_value;
        bool n_value;

    public:
        bool _is_null_value() { value(); return n_value; };

    private:
        uint8_t m_size;
        mmd_pmx_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint32_t value() const { return m_value; }
        uint8_t size() const { return m_size; }
        mmd_pmx_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class bdef4_weights_t : public kaitai::kstruct {

    public:

        bdef4_weights_t(kaitai::kstream* p__io, mmd_pmx_t::vertex_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~bdef4_weights_t();

    private:
        std::unique_ptr<std::vector<std::unique_ptr<sized_index_t>>> m_bone_indices;
        std::unique_ptr<std::vector<float>> m_weights;
        mmd_pmx_t* m__root;
        mmd_pmx_t::vertex_t* m__parent;

    public:
        std::vector<std::unique_ptr<sized_index_t>>* bone_indices() const { return m_bone_indices.get(); }
        std::vector<float>* weights() const { return m_weights.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t::vertex_t* _parent() const { return m__parent; }
    };

    class rigid_body_t : public kaitai::kstruct {

    public:

        rigid_body_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~rigid_body_t();

    private:
        std::unique_ptr<len_string_t> m_name;
        std::unique_ptr<len_string_t> m_english_name;
        std::unique_ptr<sized_index_t> m_bone_index;
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
        mmd_pmx_t* m__root;
        mmd_pmx_t* m__parent;

    public:
        len_string_t* name() const { return m_name.get(); }
        len_string_t* english_name() const { return m_english_name.get(); }

        /**
         * index of a related bone
         */
        sized_index_t* bone_index() const { return m_bone_index.get(); }
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

        /**
         * 0 = "Jelly" style bone follow
         * 1 = Real physics
         * 2 = Real physics affecting bone
         */
        uint8_t type() const { return m_type; }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t* _parent() const { return m__parent; }
    };

    class texture_t : public kaitai::kstruct {

    public:

        texture_t(kaitai::kstream* p__io, mmd_pmx_t* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~texture_t();

    private:
        std::unique_ptr<len_string_t> m_name;
        mmd_pmx_t* m__root;
        mmd_pmx_t* m__parent;

    public:

        /**
         * Indicates the filename of the texture image
         */
        len_string_t* name() const { return m_name.get(); }
        mmd_pmx_t* _root() const { return m__root; }
        mmd_pmx_t* _parent() const { return m__parent; }
    };

    class len_string_t : public kaitai::kstruct {

    public:

        len_string_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, mmd_pmx_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~len_string_t();

    private:
        uint32_t m_length;
        std::string m_value;
        mmd_pmx_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint32_t length() const { return m_length; }
        std::string value() const { return m_value; }
        mmd_pmx_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

private:
    std::unique_ptr<header_t> m_header;
    uint32_t m_vertex_count;
    std::unique_ptr<std::vector<std::unique_ptr<vertex_t>>> m_vertices;
    uint32_t m_face_vertex_count;
    std::unique_ptr<std::vector<std::unique_ptr<face_t>>> m_faces;
    uint32_t m_texture_count;
    std::unique_ptr<std::vector<std::unique_ptr<texture_t>>> m_textures;
    uint32_t m_material_count;
    std::unique_ptr<std::vector<std::unique_ptr<material_t>>> m_materials;
    uint32_t m_bone_count;
    std::unique_ptr<std::vector<std::unique_ptr<bone_t>>> m_bones;
    uint32_t m_morph_count;
    std::unique_ptr<std::vector<std::unique_ptr<morph_t>>> m_morphs;
    uint32_t m_frame_count;
    std::unique_ptr<std::vector<std::unique_ptr<frame_t>>> m_frames;
    uint32_t m_rigid_body_count;
    std::unique_ptr<std::vector<std::unique_ptr<rigid_body_t>>> m_rigid_bodies;
    uint32_t m_joint_count;
    std::unique_ptr<std::vector<std::unique_ptr<joint_t>>> m_joints;
    mmd_pmx_t* m__root;
    kaitai::kstruct* m__parent;

public:
    header_t* header() const { return m_header.get(); }
    uint32_t vertex_count() const { return m_vertex_count; }
    std::vector<std::unique_ptr<vertex_t>>* vertices() const { return m_vertices.get(); }
    uint32_t face_vertex_count() const { return m_face_vertex_count; }
    std::vector<std::unique_ptr<face_t>>* faces() const { return m_faces.get(); }
    uint32_t texture_count() const { return m_texture_count; }
    std::vector<std::unique_ptr<texture_t>>* textures() const { return m_textures.get(); }
    uint32_t material_count() const { return m_material_count; }
    std::vector<std::unique_ptr<material_t>>* materials() const { return m_materials.get(); }
    uint32_t bone_count() const { return m_bone_count; }
    std::vector<std::unique_ptr<bone_t>>* bones() const { return m_bones.get(); }
    uint32_t morph_count() const { return m_morph_count; }
    std::vector<std::unique_ptr<morph_t>>* morphs() const { return m_morphs.get(); }
    uint32_t frame_count() const { return m_frame_count; }
    std::vector<std::unique_ptr<frame_t>>* frames() const { return m_frames.get(); }
    uint32_t rigid_body_count() const { return m_rigid_body_count; }
    std::vector<std::unique_ptr<rigid_body_t>>* rigid_bodies() const { return m_rigid_bodies.get(); }
    uint32_t joint_count() const { return m_joint_count; }
    std::vector<std::unique_ptr<joint_t>>* joints() const { return m_joints.get(); }
    mmd_pmx_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};
