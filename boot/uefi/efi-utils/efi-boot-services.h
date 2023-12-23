#ifndef LOADER_EFI_BOOT_SERVICES_h_
#define LOADER_EFI_BOOT_SERVICES_h_

#include "efi-types.h"

#include <stdint.h>

struct efi_memory_descriptor {
    uint32_t                type;
    uint32_t                pad;
    efi_physical_address    physical_start;
    efi_virtual_address     virtual_start;
    uint64_t                number_of_pages;
    uint64_t                attribute;
};

struct efi_boot_services {
    struct efi_table_header hdr;

    efi_status              (*raise_tpl)
        (void) EFIFUNC;
    efi_status              (*restore_tpl)
        (void) EFIFUNC;

    efi_status              (*allocate_pages)
        (void) EFIFUNC;
    efi_status              (*free_pages)
        (void) EFIFUNC;
    efi_status              (*get_memory_map)
        (size_t *memory_map_size,
         struct efi_memory_descriptor *memory_map,
         size_t *map_key,
         size_t *descriptor_size,
         uint32_t *descriptor_version)
        EFIFUNC;
    efi_status              (*allocate_pool)
        (void) EFIFUNC;
    efi_status              (*free_pool)
        (void) EFIFUNC;

    efi_status              (*create_event)
        (void) EFIFUNC;
    efi_status              (*set_timer)
        (void) EFIFUNC;
    efi_status              (*wait_for_event)
        (void) EFIFUNC;
    efi_status              (*signal_event)
        (void) EFIFUNC;
    efi_status              (*close_event)
        (void) EFIFUNC;
    efi_status              (*check_event)
        (void) EFIFUNC;

    efi_status              (*install_protocol_interface)
        (void) EFIFUNC;
    efi_status              (*reinstall_protocol_interface)
        (void) EFIFUNC;
    efi_status              (*uninstall_protocol_interface)
        (void) EFIFUNC;
    efi_status              (*handle_protocol)
        (void) EFIFUNC;
    void                    *reserved;
    efi_status              (*register_protocol_notify)
        (void) EFIFUNC;
    efi_status              (*locate_handle)
        (void) EFIFUNC;
    efi_status              (*locate_device_path)
        (void) EFIFUNC;
    efi_status              (*install_configuration_table)
        (void) EFIFUNC;

    efi_status              (*image_load)
        (void) EFIFUNC;
    efi_status              (*image_start)
        (void) EFIFUNC;
    efi_status              (*exit)
        (void) EFIFUNC;
    efi_status              (*image_unload)
        (void) EFIFUNC;
    efi_status              (*exit_boot_services)
        (efi_handle image_handle, size_t map_key) EFIFUNC;

    efi_status              (*get_next_monotonic_count)
        (void) EFIFUNC;
    efi_status              (*stall)
        (size_t microseconds) EFIFUNC;
    efi_status              (*set_watchdog_timer)
        (void) EFIFUNC;

    efi_status              (*connect_controller)
        (void) EFIFUNC;
    efi_status              (*disconnect_controller)
        (void) EFIFUNC;

    efi_status              (*open_protocol)
        (void) EFIFUNC;
    efi_status              (*close_protocol)
        (void) EFIFUNC;
    efi_status              (*open_protocol_information)
        (void) EFIFUNC;

    efi_status              (*protocols_per_handle)
        (void) EFIFUNC;
    efi_status              (*locate_handle_buffer)
        (void) EFIFUNC;
    efi_status              (*locate_protocol)
        (void) EFIFUNC;
    efi_status              (*install_multiple_protocol_interfaces)
        (void) EFIFUNC;
    efi_status              (*uninstall_multiple_protocol_interfaces)
        (void) EFIFUNC;

    efi_status              (*calculate_crc32)
        (void) EFIFUNC;

    efi_status              (*copy_mem)
        (void) EFIFUNC;
    efi_status              (*set_mem)
        (void) EFIFUNC;
    efi_status              (*create_event_ex)
        (void) EFIFUNC;
};

#endif /* LOADER_EFI_BOOT_SERVICES_h_ */
