#include <stdio.h>

long CountTotalOnes(int x) {
    long result = 0;
    while (x) {  
        result += (x & 1);
        x >>= 1;  
    }
    return result;
}

int main() {
    // Test cases
    int test_numbers[] = {0, 1, 2, 5, 255, -1, 12345};
    int expected[] = {0, 1, 1, 2, 8, 32, 6}; // Assuming 32-bit integers
    
    printf("Testing CountTotalOnes():\n");
    printf("------------------------\n");
    
    for (int i = 0; i < sizeof(test_numbers)/sizeof(test_numbers[0]); i++) {
        long count = CountTotalOnes(test_numbers[i]);
        printf("Number: %d (0x%x)\n", test_numbers[i], test_numbers[i]);
        printf("Binary: ");
        
        // Print binary representation (for visualization)
        // while loop down ?? --> need to print MSB.........LSB so.
        for (int j = 31; j >= 0; j--) {
            printf("%d", (test_numbers[i] >> j) & 1);
            if (j % 4 == 0) printf(" ");
        }
        
        printf("\nCount of 1s: %ld\n\n", count);
    }
    
    return 0;
}