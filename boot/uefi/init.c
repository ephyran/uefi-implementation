#include "efi-utils/efi-boot-services.h"
#include "efi-utils/efi-system-table.h"
#include "efi-utils/efi-types.h"

#include "print.h"

#include <stdbool.h>

efi_status efi_main (efi_handle handle, struct efi_system_table *system_table) {
    efi_status status;

    clear_screen(system_table);
    print(system_table, STDOUT, u"Hello World!");

    size_t memory_map_size = 0;
    struct efi_memory_descriptor memory_map;
    size_t map_key;
    size_t descriptor_size;
    uint32_t descriptor_version;

    system_table->boot_services->get_memory_map(
        &memory_map_size,
        &memory_map,
        &map_key,
        &descriptor_size,
        &descriptor_version);

    system_table->boot_services->exit_boot_services(handle, map_key);

    print(system_table, STDOUT, u"Test");

    return EFI_SUCCESS;
}

