#ifndef SGX_UTILS_H_
#define SGX_UTILS_H_

#include <string>

void print_error_message(sgx_status_t ret);

sgx_enclave_id_t initialize_enclave(void);


#endif 