#include <stdio.h>
#include <stdint.h>

uint8_t swap_highest_bits(uint8_t x) {
    // Extract MSB of each nibble
    uint8_t high_nibble_msb = (x >> 7) & 1;  // MSB of high nibble (bit 7)
    uint8_t low_nibble_msb  = (x >> 3) & 1;  // MSB of low nibble (bit 3)

    // Clear original MSBs
    x &= ~(1 << 7);  // Clear bit 7
    x &= ~(1 << 3);  // Clear bit 3

    // Swap and set new MSBs
    x |= (low_nibble_msb  << 7);  // Set high nibble MSB from low
    x |= (high_nibble_msb << 3);  // Set low nibble MSB from high

    return x;
}

int main() {
    uint8_t test_values[] = {0x81, 0x3C, 0xFF, 0x00, 0x5A};
    for (int i = 0; i < sizeof(test_values)/sizeof(test_values[0]); i++) {
        printf("0x%02X -> 0x%02X\n", 
               test_values[i], 
               swap_highest_bits(test_values[i]));
    }
    return 0;
}