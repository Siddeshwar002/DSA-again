#include <stdio.h>

int main() {

    int i = 0;  

loop_start:
    // break condition
    if (i >= 5) 
        goto loop_end;  

    // Loop body
    printf("i = %d\n", i);      
    i++;                        

    // tell where to go back
    goto loop_start;            

loop_end:
    printf("Loop finished!\n");
    
    return 0;
}