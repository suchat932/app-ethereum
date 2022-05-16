#ifndef PATH_H_
#define PATH_H_

#ifdef HAVE_EIP712_FULL_SUPPORT

#include <stdint.h>
#include <stdbool.h>

#define MAX_PATH_DEPTH  16
#define MAX_ARRAY_DEPTH 4

typedef struct
{
    uint8_t path_index;
    uint8_t size;
}   s_array_depth;

typedef enum
{
    ROOT_DOMAIN,
    ROOT_MESSAGE
} e_root_type;

typedef struct
{
    uint8_t depth_count;
    uint8_t depths[MAX_PATH_DEPTH];
    uint8_t array_depth_count;
    s_array_depth array_depths[MAX_ARRAY_DEPTH];
    const void *root_struct;
    e_root_type root_type;
}   s_path;

bool    path_set_root(const char *const struct_name, uint8_t length);
const void  *path_get_field(void);
bool    path_advance(void);
bool    path_init(void);
void    path_deinit(void);
bool    path_new_array_depth(uint8_t size);

#endif // HAVE_EIP712_FULL_SUPPORT

#endif // PATH_H_
