#include <stdio.h>

long remainderPower2(long x, long n) {
    long isPos = x >> 63;
    long bias = (1L << n) + (~0L);
    long quo = (x + (isPos & bias)) >> n;

    long multiple = quo << n;

    // convert into negative
    multiple = ~multiple;
    multiple = multiple + 1;

    printf("bias : %ld \n" , bias);
    printf("multiple : %ld \n" , multiple);

    long ans = x + multiple;
    return ans;
}

int main() {
    // Test cases
    long test_cases[][2] = {
        {10, 2},    // 10 % 4 = 2
        {15, 3},     // 15 % 8 = 7
        {-10, 2},    // -10 % 4 = -2
        {-15, 3},    // -15 % 8 = -7
        {0, 5},      // 0 % 32 = 0
        {123, 0},    // 123 % 1 = 0
        {-456, 4}    // -456 % 16 = -8
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        long x = test_cases[i][0];
        long n = test_cases[i][1];
        long result = remainderPower2(x, n);
        printf("remainderPower2(%ld, %ld) = %ld\n", x, n, result);
    }

    return 0;
}