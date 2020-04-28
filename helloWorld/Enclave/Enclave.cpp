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

void printf_helloworld()
{
    printf("Hello World, Bazinga!!\n");
}


void printf_bazinga()
{
    printf("Bazinga!!!\n");
}


void returns_int_ptr(int *p_return_ptr, size_t len)
{
    int *p_ints = (int *) malloc(len*sizeof(int));
    /* do some stuff */
    wmemcpy(p_return_ptr, p_ints, len);
    free(p_ints);
}


