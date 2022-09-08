#ifndef WUFFS_INCLUDE_GUARD__PMX
#define WUFFS_INCLUDE_GUARD__PMX

#if defined(WUFFS_IMPLEMENTATION) && !defined(WUFFS_CONFIG__MODULES)
#define WUFFS_CONFIG__MODULES
#define WUFFS_CONFIG__MODULE__PMX
#endif

#include "./wuffs-base.c"

// !! WUFFS MONOLITHIC RELEASE DISCARDS EVERYTHING ABOVE.

#ifdef __cplusplus
extern "C" {
#endif

// ---------------- Status Codes

// ---------------- Public Consts

// ---------------- Struct Declarations

typedef struct wuffs_pmx__parser__struct wuffs_pmx__parser;

// ---------------- Public Initializer Prototypes

// For any given "wuffs_foo__bar* self", "wuffs_foo__bar__initialize(self,
// etc)" should be called before any other "wuffs_foo__bar__xxx(self, etc)".
//
// Pass sizeof(*self) and WUFFS_VERSION for sizeof_star_self and wuffs_version.
// Pass 0 (or some combination of WUFFS_INITIALIZE__XXX) for initialize_flags.

wuffs_base__status WUFFS_BASE__WARN_UNUSED_RESULT  //
wuffs_pmx__parser__initialize(wuffs_pmx__parser* self,
                              size_t sizeof_star_self,
                              uint64_t wuffs_version,
                              uint32_t initialize_flags);

size_t  //
sizeof__wuffs_pmx__parser();

// ---------------- Public Function Prototypes

WUFFS_BASE__MAYBE_STATIC wuffs_base__status  //
wuffs_pmx__parser__parse(wuffs_pmx__parser* self, wuffs_base__io_buffer* a_src);

WUFFS_BASE__MAYBE_STATIC uint32_t  //
wuffs_pmx__parser__value(const wuffs_pmx__parser* self);

// ---------------- Struct Definitions

// These structs' fields, and the sizeof them, are private implementation
// details that aren't guaranteed to be stable across Wuffs versions.
//
// See https://en.wikipedia.org/wiki/Opaque_pointer#C

#if defined(__cplusplus) || defined(WUFFS_IMPLEMENTATION)

struct wuffs_pmx__parser__struct {
#ifdef WUFFS_IMPLEMENTATION

  // Do not access the private_impl's or private_data's fields directly. There
  // is no API/ABI compatibility or safety guarantee if you do so. Instead, use
  // the wuffs_foo__bar__baz functions.
  //
  // It is a struct, not a struct*, so that the outermost wuffs_foo__bar struct
  // can be stack allocated when WUFFS_IMPLEMENTATION is defined.

  struct {
    uint32_t magic;
    uint32_t active_coroutine;

    uint32_t f_val;

    uint32_t p_parse[1];
  } private_impl;

#else  // WUFFS_IMPLEMENTATION

  // When WUFFS_IMPLEMENTATION is not defined, this placeholder private_impl is
  // large enough to discourage trying to allocate one on the stack. The sizeof
  // the real private_impl (and the sizeof the real outermost wuffs_foo__bar
  // struct) is not part of the public, stable, memory-safe API. Call
  // wuffs_foo__bar__baz methods (which all take a "this"-like pointer as their
  // first argument) instead of fiddling with bar.private_impl.qux fields.
  //
  // Even when WUFFS_IMPLEMENTATION is not defined, the outermost struct still
  // defines C++ convenience methods. These methods forward on "this", so that
  // you can write "bar->baz(etc)" instead of "wuffs_foo__bar__baz(bar, etc)".
 private:
  union {
    uint32_t align_as_per_magic_field;
    uint8_t placeholder[1073741824];  // 1 GiB.
  } private_impl WUFFS_BASE__POTENTIALLY_UNUSED_FIELD;

 public:

#endif  // WUFFS_IMPLEMENTATION

#ifdef __cplusplus

  inline wuffs_base__status WUFFS_BASE__WARN_UNUSED_RESULT  //
  initialize(size_t sizeof_star_self,
             uint64_t wuffs_version,
             uint32_t initialize_flags) {
    return wuffs_pmx__parser__initialize(this, sizeof_star_self, wuffs_version,
                                         initialize_flags);
  }

  inline wuffs_base__status  //
  parse(wuffs_base__io_buffer* a_src) {
    return wuffs_pmx__parser__parse(this, a_src);
  }

  inline uint32_t  //
  value() const {
    return wuffs_pmx__parser__value(this);
  }

#if (__cplusplus >= 201103L) && !defined(WUFFS_IMPLEMENTATION)
  // Disallow copy and assign.
  wuffs_pmx__parser__struct(const wuffs_pmx__parser__struct&) = delete;
  wuffs_pmx__parser__struct& operator=(const wuffs_pmx__parser__struct&) =
      delete;
#endif  // (__cplusplus >= 201103L) && !defined(WUFFS_IMPLEMENTATION)

#endif  // __cplusplus

};  // struct wuffs_pmx__parser__struct

#endif  // defined(__cplusplus) || defined(WUFFS_IMPLEMENTATION)

#ifdef __cplusplus
}  // extern "C"
#endif

// WUFFS C HEADER ENDS HERE.
#ifdef WUFFS_IMPLEMENTATION

#if !defined(WUFFS_CONFIG__MODULES) || defined(WUFFS_CONFIG__MODULE__PMX)

// ---------------- Status Codes Implementations

const char* wuffs_pmx__error__not_a_pmx_file = "#pmx: not a pmx file";

// ---------------- Private Consts

// ---------------- Private Initializer Prototypes

// ---------------- Private Function Prototypes

// ---------------- Initializer Implementations

wuffs_base__status WUFFS_BASE__WARN_UNUSED_RESULT  //
wuffs_pmx__parser__initialize(wuffs_pmx__parser* self,
                              size_t sizeof_star_self,
                              uint64_t wuffs_version,
                              uint32_t initialize_flags) {
  if (!self) {
    return wuffs_base__error__bad_receiver;
  }
  if (sizeof(*self) != sizeof_star_self) {
    return wuffs_base__error__bad_sizeof_receiver;
  }
  if (((wuffs_version >> 32) != WUFFS_VERSION_MAJOR) ||
      (((wuffs_version >> 16) & 0xFFFF) > WUFFS_VERSION_MINOR)) {
    return wuffs_base__error__bad_wuffs_version;
  }

  if ((initialize_flags & WUFFS_INITIALIZE__ALREADY_ZEROED) != 0) {
// The whole point of this if-check is to detect an uninitialized *self.
// We disable the warning on GCC. Clang-5.0 does not have this warning.
#if !defined(__clang__) && defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif
    if (self->private_impl.magic != 0) {
      return wuffs_base__error__initialize_falsely_claimed_already_zeroed;
    }
#if !defined(__clang__) && defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
  } else {
    if ((initialize_flags &
         WUFFS_INITIALIZE__LEAVE_INTERNAL_BUFFERS_UNINITIALIZED) == 0) {
      memset(self, 0, sizeof(*self));
      initialize_flags |= WUFFS_INITIALIZE__ALREADY_ZEROED;
    } else {
      memset(&(self->private_impl), 0, sizeof(self->private_impl));
    }
  }

  self->private_impl.magic = WUFFS_BASE__MAGIC;
  return NULL;
}

size_t  //
sizeof__wuffs_pmx__parser() {
  return sizeof(wuffs_pmx__parser);
}

// ---------------- Function Implementations

// -------- func pmx.parser.parse

WUFFS_BASE__MAYBE_STATIC wuffs_base__status  //
wuffs_pmx__parser__parse(wuffs_pmx__parser* self,
                         wuffs_base__io_buffer* a_src) {
  if (!self) {
    return wuffs_base__error__bad_receiver;
  }
  if (self->private_impl.magic != WUFFS_BASE__MAGIC) {
    return (self->private_impl.magic == WUFFS_BASE__DISABLED)
               ? wuffs_base__error__disabled_by_previous_error
               : wuffs_base__error__initialize_not_called;
  }
  if (!a_src) {
    self->private_impl.magic = WUFFS_BASE__DISABLED;
    return wuffs_base__error__bad_argument;
  }
  if ((self->private_impl.active_coroutine != 0) &&
      (self->private_impl.active_coroutine != 1)) {
    self->private_impl.magic = WUFFS_BASE__DISABLED;
    return wuffs_base__error__interleaved_coroutine_calls;
  }
  self->private_impl.active_coroutine = 0;
  wuffs_base__status status = NULL;

  uint8_t v_c = 0;

  uint8_t* iop_a_src = NULL;
  uint8_t* io0_a_src WUFFS_BASE__POTENTIALLY_UNUSED = NULL;
  uint8_t* io1_a_src WUFFS_BASE__POTENTIALLY_UNUSED = NULL;
  uint8_t* io2_a_src WUFFS_BASE__POTENTIALLY_UNUSED = NULL;
  if (a_src) {
    io0_a_src = a_src->data.ptr;
    io1_a_src = io0_a_src + a_src->meta.ri;
    iop_a_src = io1_a_src;
    io2_a_src = io0_a_src + a_src->meta.wi;
  }

  uint32_t coro_susp_point = self->private_impl.p_parse[0];
  if (coro_susp_point) {
  }
  switch (coro_susp_point) {
    WUFFS_BASE__COROUTINE_SUSPENSION_POINT_0;

    self->private_impl.f_val = 0;
    {
      WUFFS_BASE__COROUTINE_SUSPENSION_POINT(1);
      if (WUFFS_BASE__UNLIKELY(iop_a_src == io2_a_src)) {
        status = wuffs_base__suspension__short_read;
        goto suspend;
      }
      uint8_t t_0 = *iop_a_src++;
      v_c = t_0;
    }
    if (v_c != 80) {
      status = wuffs_pmx__error__not_a_pmx_file;
      goto exit;
    }
    {
      WUFFS_BASE__COROUTINE_SUSPENSION_POINT(2);
      if (WUFFS_BASE__UNLIKELY(iop_a_src == io2_a_src)) {
        status = wuffs_base__suspension__short_read;
        goto suspend;
      }
      uint8_t t_1 = *iop_a_src++;
      v_c = t_1;
    }
    if (v_c != 77) {
      status = wuffs_pmx__error__not_a_pmx_file;
      goto exit;
    }
    {
      WUFFS_BASE__COROUTINE_SUSPENSION_POINT(3);
      if (WUFFS_BASE__UNLIKELY(iop_a_src == io2_a_src)) {
        status = wuffs_base__suspension__short_read;
        goto suspend;
      }
      uint8_t t_2 = *iop_a_src++;
      v_c = t_2;
    }
    if (v_c != 88) {
      status = wuffs_pmx__error__not_a_pmx_file;
      goto exit;
    }
    {
      WUFFS_BASE__COROUTINE_SUSPENSION_POINT(4);
      if (WUFFS_BASE__UNLIKELY(iop_a_src == io2_a_src)) {
        status = wuffs_base__suspension__short_read;
        goto suspend;
      }
      uint8_t t_3 = *iop_a_src++;
      v_c = t_3;
    }
    if (v_c != 32) {
      status = wuffs_pmx__error__not_a_pmx_file;
      goto exit;
    }
    self->private_impl.f_val = 1;
    status = NULL;
    goto ok;
    goto ok;
  ok:
    self->private_impl.p_parse[0] = 0;
    goto exit;
  }

  goto suspend;
suspend:
  self->private_impl.p_parse[0] =
      wuffs_base__status__is_suspension(status) ? coro_susp_point : 0;
  self->private_impl.active_coroutine =
      wuffs_base__status__is_suspension(status) ? 1 : 0;

  goto exit;
exit:
  if (a_src) {
    a_src->meta.ri = ((size_t)(iop_a_src - a_src->data.ptr));
  }

  if (wuffs_base__status__is_error(status)) {
    self->private_impl.magic = WUFFS_BASE__DISABLED;
  }
  return status;
}

// -------- func pmx.parser.value

WUFFS_BASE__MAYBE_STATIC uint32_t  //
wuffs_pmx__parser__value(const wuffs_pmx__parser* self) {
  if (!self) {
    return 0;
  }
  if ((self->private_impl.magic != WUFFS_BASE__MAGIC) &&
      (self->private_impl.magic != WUFFS_BASE__DISABLED)) {
    return 0;
  }

  return self->private_impl.f_val;
}

#endif  // !defined(WUFFS_CONFIG__MODULES) || defined(WUFFS_CONFIG__MODULE__PMX)

#endif  // WUFFS_IMPLEMENTATION

// !! WUFFS MONOLITHIC RELEASE DISCARDS EVERYTHING BELOW.

#endif  // WUFFS_INCLUDE_GUARD__PMX
