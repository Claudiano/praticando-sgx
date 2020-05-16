#include <stdio.h>
#include <iostream>

#include "sgx_urts.h"
#include "Enclave_u.h"

#include "sgx_utils/sgx_utils.h"




int somar(int notaA, int notaB){

    /* Initialize the enclave */
    if(initialize_enclave() < 0){
        printf("Enter a character before exit ...\n");
        getchar();
        return -1; 
    }

    sgx_status_t status;
    int result;

    // Adição
    status = calc_sum(global_eid, &notaA, &notaB, &result);
    cout << notaA << " + "  << notaB << " = " << result << endl;

       /* Destroy the enclave */
    sgx_destroy_enclave(global_eid);

    return result;

}

/*
    // Multiplicação
    status = calc_mult(global_eid, &notaA, &notaB, &result);
    cout << notaA << " * "  << notaB << " = " << result << endl;

    // Subtração
    status = calc_sub(global_eid, &notaA, &notaB, &result);
    cout << notaA << " - "  << notaB << " = " << result << endl;


*/
 