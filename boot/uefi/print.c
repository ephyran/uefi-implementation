#include "print.h"

efi_status clear_screen (struct efi_system_table *system_table) {
    return system_table->con_out->clear_screen(system_table->con_out);
}

efi_status print (struct efi_system_table *system_table, enum stream_type type, wchar *string) {
    switch (type) {
        case STDOUT:
            return system_table->con_out->output_string(system_table->con_out, string);
        case STDERR:
            return system_table->std_err->output_string(system_table->std_err, string);
    }
}
