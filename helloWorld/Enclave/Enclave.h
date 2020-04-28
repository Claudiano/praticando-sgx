#ifndef _ENCLAVE_H_

#define _ENCLAVE_H_

#include <stdlib.h>
#include <assert.h>

#if defined(__cplusplus)
extern "C" {
#endif

void printf(const char *fmt, ...);
void printf_helloworld();
void printf_bazinga();
void returns_int_ptr(int *p_return_ptr, size_t len)

#if defined(__cplusplus)
}
#endif

#endif /* !_ENCLAVE_H_ */