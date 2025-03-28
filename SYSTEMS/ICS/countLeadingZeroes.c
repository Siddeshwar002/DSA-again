#include <stdio.h>
#include <stdint.h>

// Practical implicataion : 
// Floor of log2(x) : 
    // int log2 = 31 - clz(x);  

int clz(uint32_t x) {
    // Edge case: all zeros
    if (x == 0) 
        return 32; 
    
    int n = 0;

    // Binary search for the first set bit (1)
    if (x <= 0x0000FFFF) { n += 16; x <<= 16; }
    if (x <= 0x00FFFFFF) { n +=  8; x <<=  8; }
    if (x <= 0x0FFFFFFF) { n +=  4; x <<=  4; }
    if (x <= 0x3FFFFFFF) { n +=  2; x <<=  2; }
    if (x <= 0x7FFFFFFF) { n +=  1; }
    
    return n;
}

int clz_iterative_LSB(uint32_t x) {
    if (x == 0) 
        return 32;
    
    int count = 0;
    
    for (int i = 31; i >= 0; i--) {
        if ((x >> i) & 1) break;
        count++;
    }
    
    return count;
}

int clz_iterative_MSB(uint32_t x) {
    if (x == 0) 
        return 32;
    
    int count = 0;

    while ((x & 0x80000000) == 0) { 
        x <<= 1;  
        count++;
    }

    return count;
}

int clz_builtin(uint32_t x) {
    return __builtin_clz(x); // GCC/Clang
    // Or: return _lzcnt_u32(x); // MSVC/Intel
}