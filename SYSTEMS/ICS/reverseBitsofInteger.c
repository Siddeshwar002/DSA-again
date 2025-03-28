#include <stdint.h> // For uint32_t

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1); // Shift result left and add LSB of n
        n >>= 1; // Drop LSB of n
    }
    return result;
}

uint32_t reverseBits(uint32_t n) {
    n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16); // Swap 16-bit halves
    n = ((n & 0xFF00FF00) >> 8)  | ((n & 0x00FF00FF) << 8);  // Swap 8-bit halves
    n = ((n & 0xF0F0F0F0) >> 4)  | ((n & 0x0F0F0F0F) << 4);  // Swap 4-bit halves
    n = ((n & 0xCCCCCCCC) >> 2)  | ((n & 0x33333333) << 2);  // Swap 2-bit pairs
    n = ((n & 0xAAAAAAAA) >> 1)  | ((n & 0x55555555) << 1);  // Swap adjacent bits
    return n;
}