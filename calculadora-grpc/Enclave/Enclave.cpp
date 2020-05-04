#include <stdarg.h>
#include <stdio.h>      /* vsnprintf */

#include "Enclave.h"
#include "Enclave_t.h"  /* print_string */

/* 
 * printf: 
 *   Invokes OCALL to display the enclave buffer to the terminal.
 */
void printf(const char *fmt, ...)
{
    char buf[BUFSIZ] = {'\0'};
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, BUFSIZ, fmt, ap);
    va_end(ap);
    ocall_print_string(buf);
}


void calc_sum(int *p_notaA, int *p_notaB, int *p_result){
    *p_result = *p_notaA + *p_notaB;
}

void calc_mult(int *p_notaA, int *p_notaB, int *p_result){
    *p_result = *p_notaA + *p_notaB;
}

void calc_div(int *p_notaA, int *p_notaB, int *p_result){
    *p_result = *p_notaA + *p_notaB;
}

void calc_sub(int *p_notaA, int *p_notaB, int *p_result){
    *p_result = *p_notaA + *p_notaB;
}

