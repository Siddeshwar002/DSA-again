#include <stdint.h> // For uint32_t
#include <stdio.h>

int main(){

    int test_numbers[] = {-1, -2, -4, -8, -16, -32, -64};

    for (int i = 0; i < sizeof(test_numbers)/sizeof(test_numbers[0]); i++) {
        printf("\nNumber: %d (0x%x)\n", test_numbers[i], test_numbers[i]);
        printf("Binary: \n");
        
        for (int j = 31; j >= 0; j--) {
            printf("%d", (test_numbers[i] >> j) & 1);
            if (j % 4 == 0) printf(" ");
        }
        
    }
    
    return 0;

}