#ifndef EIP712_H_
#define EIP712_H_

#ifdef HAVE_EIP712_FULL_SUPPORT

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
    // contract defined struct
    TYPE_CUSTOM = 0,
    // native types
    TYPE_SOL_INT,
    TYPE_SOL_UINT,
    TYPE_SOL_ADDRESS,
    TYPE_SOL_BOOL,
    TYPE_SOL_STRING,
    TYPE_SOL_BYTES_FIX,
    TYPE_SOL_BYTES_DYN,
    TYPES_COUNT
}   e_type;

typedef enum
{
    ARRAY_DYNAMIC = 0,
    ARRAY_FIXED_SIZE
}   e_array_type;

// APDUs INS
#define INS_STRUCT_DEF  0x18
#define INS_STRUCT_IMPL 0x1A

// APDUs P1
#define P1_COMPLETE 0x00
#define P1_PARTIAL  0xFF
#define P1_ACTIVATE         0x00
#define P1_CONTRACT_NAME    0x0F
#define P1_FIELD_NAME       0xFF

// APDUs P2
#define P2_NAME     0x00
#define P2_ARRAY    0x0F
#define P2_FIELD    0xFF
#define P2_KEY      0x00
#define P2_VALUE    0xFF

// TypeDesc masks
#define TYPE_MASK       (0xF)
#define ARRAY_MASK      (1 << 7)
#define TYPESIZE_MASK   (1 << 6)
#define TYPENAME_ENUM   (0xF)

typedef enum
{
    EIP712_TYPE_HASH,
    EIP712_FIELD_HASH,
    EIP712_STRUCT_HASH
}   e_eip712_hash_type;

#define ARRAY_SIZE(a)   (sizeof(a) / sizeof(a[0]))

#define DOMAIN_STRUCT_NAME          "EIP712Domain"

// TODO: Move these into a new file
const char *get_struct_name(const uint8_t *ptr, uint8_t *const length);
const uint8_t *get_struct_fields_array(const uint8_t *ptr,
                                       uint8_t *const length);
const char *get_struct_field_typename(const uint8_t *ptr,
                                      uint8_t *const length);
bool    struct_field_has_typesize(const uint8_t *ptr);
uint8_t get_struct_field_typesize(const uint8_t *ptr);
bool    struct_field_is_array(const uint8_t *ptr);
e_type  struct_field_type(const uint8_t *ptr);
const uint8_t *get_struct_field_array_lvls_array(const uint8_t *ptr,
                                                 uint8_t *const length);
e_array_type struct_field_array_depth(const uint8_t *ptr,
                                      uint8_t *const array_size);
const uint8_t *get_next_struct_field_array_lvl(const uint8_t *ptr);
const char *get_struct_field_typename(const uint8_t *ptr,
                                      uint8_t *const length);
const char *get_struct_field_keyname(const uint8_t *ptr,
                                     uint8_t *const length);
const uint8_t *get_next_struct_field(const void *ptr);
const uint8_t *get_structn(const uint8_t *const ptr,
                           const char *const name_ptr,
                           const uint8_t name_length);
const void *get_array_in_mem(const void *ptr, uint8_t *const array_size);
const char *get_string_in_mem(const uint8_t *ptr, uint8_t *const string_length);

#endif // HAVE_EIP712_FULL_SUPPORT

#endif // EIP712_H_
