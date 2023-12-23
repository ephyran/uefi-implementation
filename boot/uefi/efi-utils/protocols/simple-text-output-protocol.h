#ifndef LOADER_EFI_SIMPLE_TEXT_OUTPUT_h_
#define LOADER_EFI_SIMPLE_TEXT_OUTPUT_h_

#include "../efi-types.h"

#include <stdbool.h>
#include <stdint.h>

struct simple_text_output_mode {
    uint32_t    max_mode;
    uint32_t    mode;
    uint32_t    attribute;
    uint32_t    cursor_column;
    uint32_t    cursor_row;
    bool        cursor_visible;
};

struct efi_simple_text_output_protocol {
    efi_status                      (*reset)                (struct efi_simple_text_output_protocol *identity, bool extended_verification) EFIFUNC;
    efi_status                      (*output_string)        (struct efi_simple_text_output_protocol *identity, wchar *string) EFIFUNC;
    efi_status                      (*test_string)          (struct efi_simple_text_output_protocol *identity, wchar *string) EFIFUNC;
    efi_status                      (*query_mode)           (struct efi_simple_text_output_protocol *identity,
                                                                size_t mode_number,
                                                                size_t columns,
                                                                size_t rows)
                                                            EFIFUNC;
    efi_status                      (*set_mode)             (struct efi_simple_text_output_protocol *identity, size_t mode_number) EFIFUNC;
    efi_status                      (*set_attribute)        (struct efi_simple_text_output_protocol *identity, size_t attribute) EFIFUNC;
    efi_status                      (*clear_screen)         (struct efi_simple_text_output_protocol *identity) EFIFUNC;
    efi_status                      (*set_cursor_position)  (struct efi_simple_text_output_protocol *identity, size_t column, size_t row);
    efi_status                      (*enable_cursor)        (struct efi_simple_text_output_protocol *identity, bool visible);
    struct simple_text_output_mode  *mode;
};

#endif /* LOADER_EFI_SIMPLE_TEXT_OUTPUT_h_ */
