#ifndef LOADER_EFI_SYSTEM_TABLE_h_
#define LOADER_EFI_SYSTEM_TABLE_h_

#include "efi-types.h"
#include "protocols/simple-text-output-protocol.h"

#include <stdint.h>

struct efi_system_table {
    struct efi_table_header                 hdr;
    wchar                                   *firmware_vendor;
    uint32_t                                firmware_revision;
    efi_handle                              console_in_handle;
    void                                    *con_in;
    efi_handle                              console_out_handle;
    struct efi_simple_text_output_protocol  *con_out;
    efi_handle                              standard_error_handle;
    struct efi_simple_text_output_protocol  *std_err;
    void                                    *runtime_services;
    void                                    *boot_services;
    size_t                                  number_of_table_entries;
    void                                    *configuration_table;
};

#endif /* LOADER_EFI_SYSTEM_TABLE_h_ */
