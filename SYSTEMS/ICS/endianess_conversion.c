#include <stdio.h>
#include <stdint.h>

uint32_t swap_endian(uint32_t value) {
    return ((value & 0xFF000000) >> 24) |  // Move byte 3 to byte 0
           ((value & 0x00FF0000) >> 8)  |  // Move byte 2 to byte 1
           ((value & 0x0000FF00) << 8)  |  // Move byte 1 to byte 2
           ((value & 0x000000FF) << 24);   // Move byte 0 to byte 3
}

int main() {
    uint32_t big_endian = 0x2ad45c78;  // Big Endian: 0x12 0x34 0x56 0x78
    uint32_t little_endian = swap_endian(big_endian);
    
    printf("Big Endian:    0x%08X\n", big_endian);
    printf("Little Endian: 0x%08X\n", little_endian);  // Output: 0x78563412
    return 0;
}