#include <stdio.h>
#include <stdint.h>

// Function to execute the CPUID instruction
void cpuid(uint32_t function, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx) {
    __asm__ __volatile__ ("cpuid"
                          : "=a" (*eax),
                            "=b" (*ebx),
                            "=c" (*ecx),
                            "=d" (*edx)
                          : "a" (function));
}

int main() {
    uint32_t eax, ebx, ecx, edx;

    // Execute CPUID with function 0x8000001F
    cpuid(0x8000001F, &eax, &ebx, &ecx, &edx);

    // Output header
    printf("%-45s %s\n", "Feature", "Status");
    printf("%-45s %s\n", "-----------------------------", "-------");

    // Check if Secure Memory Encryption (SME) is supported
    printf("%-45s %s\n", "Secure Memory Encryption (SME)", (eax & 0x1) ? "Supported" : "Not Supported");

    // Check if Secure Encrypted Virtualization (SEV) is supported
    printf("%-45s %s\n", "Secure Encrypted Virtualization (SEV)", (eax & (1 << 1)) ? "Supported" : "Not Supported");

    // Check if SEV-ES is supported
    printf("%-45s %s\n", "SEV-ES (SEV Encrypted State)", (eax & (1 << 3)) ? "Supported" : "Not Supported");

    // Check if SEV-SNP is supported
    printf("%-45s %s\n", "SEV-SNP (SEV Secure Nested Paging)", (eax & (1 << 4)) ? "Supported" : "Not Supported");

    // Check number of VMPLs (Virtual Machine Protection Levels)
    uint32_t vmpl_count = (ebx >> 12) & 0xF;
    printf("%-45s %u\n", "Number of VMPLs available", vmpl_count);

    return 0;
}

