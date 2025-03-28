#include <stdio.h>

int countSets(unsigned int n) {
    int count = 0;
    int lastBit = 0; // Track the previous bit
    
    while (n) {
        int currentBit = n & 1;
        if (currentBit == 1 && lastBit == 0) {
            count++; // New set starts
        }
        lastBit = currentBit;
        n >>= 1; // Shift right to check next bit
    }
    
    return count;
}

int main() {
    unsigned int num = 0b1101101011001; // Example: 5 sets (11011, 101, 11, 1)
    printf("Number of sets: %d\n", countSets(num));
    return 0;
}