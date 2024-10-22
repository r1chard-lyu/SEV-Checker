# SEV-Checker
This is a simple C program that uses the CPUID instruction to check for specific CPU features related to Secure Memory Encryption (SME), Secure Encrypted Virtualization (SEV), and their extended features SEV-ES and SEV-SNP. Additionally, it checks for the number of Virtual Machine Protection Levels (VMPLs) available.

## Features
- **Secure Memory Encryption (SME)**: Detects if the CPU supports SME.
- **Secure Encrypted Virtualization (SEV)**: Detects if SEV is supported.
- **SEV-ES (SEV Encrypted State)**: Checks if SEV-ES is supported.
- **SEV-SNP (Secure Nested Paging)**: Detects if SEV-SNP is supported.
- **Number of VMPLs**: Displays the number of available Virtual Machine Protection Levels.
