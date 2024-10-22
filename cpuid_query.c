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

    // Query CPUID with function 0x00000000 to get basic information
    cpuid(0x00000000, &eax, &ebx, &ecx, &edx);
    printf("CPUID Function 0x00000000:\n");
    printf("  EAX: 0x%08X\n", eax);
    printf("  EBX: 0x%08X\n", ebx);
    printf("  ECX: 0x%08X\n", ecx);
    printf("  EDX: 0x%08X\n", edx);
    printf("  Processor Manufacturer String: %c%c%c%c%c%c%c%c\n",
           (ebx & 0xFF), (ebx >> 8) & 0xFF, (ebx >> 16) & 0xFF, (ebx >> 24) & 0xFF,
           (edx & 0xFF), (edx >> 8) & 0xFF, (edx >> 16) & 0xFF, (edx >> 24) & 0xFF);

    // Query CPUID with function 0x00000001 to get extended features
    cpuid(0x00000001, &eax, &ebx, &ecx, &edx);
    printf("\nCPUID Function 0x00000001:\n");
    printf("  EAX: 0x%08X\n", eax);
    printf("  EBX: 0x%08X\n", ebx);
    printf("  ECX: 0x%08X\n", ecx);
    printf("  EDX: 0x%08X\n", edx);

    // Check supported features
    printf("Supported Features:\n");
    if (edx & (1 << 25)) printf("  SSE supported\n");
    if (edx & (1 << 26)) printf("  SSE2 supported\n");
    if (ecx & (1 << 0))  printf("  SSE3 supported\n");
    if (ecx & (1 << 9))  printf("  SSSE3 supported\n");
    if (ecx & (1 << 19)) printf("  SSE4.1 supported\n");
    if (ecx & (1 << 20)) printf("  SSE4.2 supported\n");

    return 0;
}

