#include <stdio.h>
#include <stdint.h>
#include <limits.h>

// Returns the bit offset of first occurrence of 'pattern' in 'bitstream'
// Returns -1 if not found
int find_pattern(uint32_t bitstream, uint8_t pattern) {
    // Iterate through each possible 8-bit window
    for (int offset = 0; offset <= 24; offset++) {
        // Extract 8-bit window starting at 'offset'
        uint8_t window = (bitstream >> (24 - offset)) & 0xFF;
        
        if (window == pattern) {
            return offset;
        }
    }
    return -1; // Not found
}

int main() {
    uint32_t test_bitstreams[] = {
        0b11001010011110101011011111000001, // Example bitstream
        0xFFFFFFFF,                         // All 1s
        0x00000000,                         // All 0s
        0x12345678                          // Random pattern
    };
    uint8_t test_patterns[] = {0b10101101, 0xFF, 0x00, 0x34};

    for (int i = 0; i < sizeof(test_bitstreams)/sizeof(test_bitstreams[0]); i++) {
        int offset = find_pattern(test_bitstreams[i], test_patterns[i]);
        printf("Bitstream: 0x%08X, Pattern: 0x%02X -> Offset: %d\n",
               test_bitstreams[i], test_patterns[i], offset);
    }
    return 0;
}