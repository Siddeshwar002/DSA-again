#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint64_t high;
    uint64_t low;
} uint128_t;

void read_128bit_timestamp(uint128_t ts) {
    printf("Timestamp: 0x%0llx-0x%llx\n", ts.high, ts.low);
}

int main() {
    uint128_t ts = { .high = 0x123456789ABCDEF0, .low = 0xFEDCBA9876543210 };
    read_128bit_timestamp(ts);
    return 0;
}