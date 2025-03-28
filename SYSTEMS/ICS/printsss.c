#include <stdio.h>
#include <stdint.h> // Fixed-width types (int32_t, uint64_t)
#include <stdlib.h>  // Memory allocation (malloc), conversions (atoi)

int main(){

    printf("%d", 42);        // int (signed decimal)  
    printf("%i", 42);        // int (same as %d)  
    printf("%u", 42U);       // unsigned int  
    printf("%o", 42);        // unsigned octal  
    printf("%x", 42);        // unsigned hex (lowercase)  
    printf("%X", 42);        // unsigned hex (uppercase)  
    printf("%f", 3.14);      // double (decimal)  
    printf("%F", 3.14);      // double (uppercase INF/NAN)  
    printf("%e", 3.14);      // scientific (lowercase)  
    printf("%E", 3.14);      // scientific (uppercase)  
    printf("%g", 3.14);      // shortest %f/%e  
    printf("%G", 3.14);      // shortest %F/%E  
    printf("%a", 3.14);      // hex float (lowercase)  
    printf("%A", 3.14);      // hex float (uppercase)  
    printf("%c", 'A');       // char  
    printf("%s", "hello");   // string  
    // printf("%p", &x);        // pointer address  
    printf("%%");            // literal '%'  

    // Length modifiers

    // printf("%hd", (short)42);    // short int  
    // printf("%hu", (ushort)42);   // unsigned short  
    printf("%ld", 42L);          // long int  
    printf("%lu", 42UL);         // unsigned long  
    printf("%lld", 42LL);        // long long  
    printf("%llu", 42ULL);       // unsigned long long  
    printf("%Lf", 3.14L);        // long double  
    // printf("%zu", sizeof(x));    // size_t  
    // printf("%td", ptrdiff);      // ptrdiff_t  
}
