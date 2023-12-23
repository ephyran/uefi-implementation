#include "efi-utils/efi-types.h"
#include "efi-utils/efi-system-table.h"

#include <stdbool.h>

efi_status efi_main (efi_handle handle __attribute__((unused)), struct efi_system_table *system_table) {
    efi_status status;

    status = system_table->con_out->clear_screen(system_table->con_out);
    HANDLE_ERR(status);

    status = system_table->con_out->output_string(system_table->con_out, u"Hello World!");
    HANDLE_ERR(status);

    while (1) {
        __asm__ __volatile__("pause");
    }

    return EFI_SUCCESS;
}

