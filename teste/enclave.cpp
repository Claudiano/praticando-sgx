
// Arquivo enclave.cpp
#include "stdlib.h"
#include "enclave_t.h" // Gerado pela ferramenta sgx_edger8er

long enclave_sum( int *array, size_t array_size) {
    long sum = 0;
    int i;
    for (i=0; i<array_size/sizeof(int); ++i){
        sum += array[i];
    }
    return sum;
}