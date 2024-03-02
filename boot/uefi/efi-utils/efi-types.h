#ifndef LOADER_EFI_TYPES_h_
#define LOADER_EFI_TYPES_h_

#if __has_attribute(unavailable)
#define EFI_FUNC_UNAVAILABLE(msg) __attribute__((unavailable(msg)))
#else
#define EFI_FUNC_UNAVAILABLE(msg)
#endif

#if defined(__x86_64__)
#define EFIFUNC __attribute__((ms_abi))
#elif defined(__aarch64__) || defined(__riscv)
#define EFIFUNC
#else
#define EFIFUNC EFI_FUNC_UNAVAILABLE("EFI calling convention undefined on this architecture")
#endif

#define EFI_ERROR(x) (((intptr_t)(x)) < 0)

#define EFI_SUCCESS 0u

#define EFI_INVALID_PARAMETER EFI_ERROR(2)

#include <stddef.h>
#include <stdint.h>

typedef unsigned short wchar;

typedef uint64_t efi_physical_address;
typedef uint64_t efi_virtual_address;

typedef size_t  efi_status;
typedef void *  efi_handle;

struct efi_table_header {
    uint64_t signature;
    uint32_t revision;
    uint32_t header_size;
    uint32_t crc32;
    uint32_t reserved;
};

#endif /* LOADER_EFI_TYPES_h_ */
