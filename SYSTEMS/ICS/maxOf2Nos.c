#include <stdio.h>

int max(int a, int b) {
    int diff = a - b;
    int sign = (diff >> (sizeof(int) * 8 - 1)) & 1;
    return a - (diff * sign); // Branchless max
}

int main() {
    printf("%d\n", max(10, 20)); // 20
    printf("%d\n", max(-5, 3));  // 3
    printf("%d\n", max(7, 7));   // 7
    return 0;
}