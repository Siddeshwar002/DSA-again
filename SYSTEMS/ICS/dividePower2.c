#include <stdio.h>
#include <limits.h>

// Divides x by 2^n (rounding towards zero for negative numbers)
long dividePower2(long x, long n) {
    long isPos = x >> 63;              // 0 for positive, -1 for negative
    long bias = (1L << n) + (~0L);     // (2^n - 1)
    return (x + (isPos & bias)) >> n;  // Add bias only for negative numbers
}


int main() {
    // Test cases
    long test_values[][2] = {
        {10, 2},    // 10/4
        {15, 3},     // 15/8
        {-10, 2},    // -10/4
        {-15, 3},    // -15/8
        {0, 5},      // 0/32
        {123, 0},    // 123/1
        {-456, 4},   // -456/16
        {27 , 3},
        {-27 , 3},
        {LONG_MAX, 3},
        {LONG_MIN, 3}
    };

    for (int i = 0; i < sizeof(test_values)/sizeof(test_values[0]); i++) {
        long x = test_values[i][0];
        long n = test_values[i][1];
        printf("dividePower2(%ld, %ld) = %ld\n", x, n, dividePower2(x, n));
    }

    return 0;
}