// Arquivo app.cpp
#include "stdlib.h"
#include "enclave_u.h" // Gerado pela ferramenta sgx_edger8er
#include "sgx_urts.h" // Necessário para instanciar enclaves
#define ENCLAVE_NAME "enclave.signed.so"
#define MB_SIZE 1024*1024
#define ARRAY_SIZE 4096
#define CHUNK_SIZE 1

 int main(){

    sgx_enclave_id_t eid;
    sgx_status_t ret = SGX_SUCCESS;
    sgx_launch_token_t launch_token;
    int updated = 0;

    // Instancia um enclave SGX
    ret = sgx_create_enclave( ENCLAVE_NAME, SGX_DEBUG_FLAG, &launch_token, &updated, &eid, NULL );
    
    int total_num_of_elements = ARRAY_SIZE * MB_SIZE / sizeof(int);
    int *array = (int *) calloc(total_num_of_elements,sizeof(int));
    
    generate_random_numbers(array, total_num_of_elements); // Preenche array com números inteiros aleatórios
    
    int chunk_num_of_elements = CHUNK_SIZE * MB_SIZE / sizeof(int);
    long sum = 0, partial_sum;
    int i, idx;

    for(i=0; i<total_num_of_elements/chunk_num_of_elements; ++i){
        idx = i*chunk_num_of_elements
        enclave_sum(eid, &partial_sum, &array[idx], CHUNK_SIZE);
        sum += partial_sum;
    }
    printf("A soma dos elementos do array é: %ld.\n", sum);
    sgx_destroy_enclave(eid);
    return 0;
 }