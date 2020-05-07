#include <stdio.h>
#include <iostream>
#include <string.h>
#include <assert.h>
#include <cstdint>

#include <stdio.h>
#include <iostream>

#include "sgx_urts.h"
#include "Enclave_u.h"

#include "sgx_utils/sgx_utils.h"

using namespace std;

/* Global EID shared by multiple threads */
// sgx_enclave_id_t global_eid = 0;



/* Application entry */
int main(int argc, char *argv[]){

    std::cout << "global_eid = " << global_eid << std::endl;

    global_eid = initialize_enclave();

    /* Initialize the enclave */
    if(global_eid < 0){
        printf("Enter a character before exit ...\n");
        getchar();
        return -1; 
    }

    sgx_status_t status;
    int result, notaA = 5, notaB = 8;

    // Adição
    status = calc_sum(global_eid, &notaA, &notaB, &result);
    cout << notaA << " + "  << notaB << " = " << result << endl;

    // Multiplicação
    status = calc_mult(global_eid, &notaA, &notaB, &result);
    cout << notaA << " * "  << notaB << " = " << result << endl;

    // Subtração
    status = calc_sub(global_eid, &notaA, &notaB, &result);
    cout << notaA << " - "  << notaB << " = " << result << endl;



    /* Destroy the enclave */
    sgx_destroy_enclave(global_eid);

    
    return 0;
}