#ifndef LOADER_PRINT_h_
#define LOADER_PRINT_h_

#include "efi-utils/efi-types.h"
#include "efi-utils/efi-system-table.h"

enum stream_type {
    STDOUT,
    STDERR
};

efi_status  clear_screen    (struct efi_system_table *system_table);
efi_status  print           (struct efi_system_table *system_table, enum stream_type type, wchar *string);

#endif /* LOADER_PRINT_h_ */
