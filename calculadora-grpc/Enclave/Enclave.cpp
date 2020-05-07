#include <stdarg.h>
#include <stdio.h>      /* vsnprintf */

#include "Enclave.h"
#include "Enclave_t.h"  /* print_string */



void calc_sum(int *p_notaA, int *p_notaB, int *p_result){
    *p_result = *p_notaA + *p_notaB;
}

void calc_mult(int *p_notaA, int *p_notaB, int *p_result){
    *p_result = *p_notaA * *p_notaB;
}


void calc_sub(int *p_notaA, int *p_notaB, int *p_result){
    *p_result = *p_notaA - *p_notaB;
}

