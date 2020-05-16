
#include <stdio.h>
#include <iostream>
#include "security/serviceEnclave.h"



using namespace std;

/* Global EID shared by multiple threads */
// sgx_enclave_id_t global_eid = 0;



/* Application entry */
int main(int argc, char *argv[]){

    std::cout << "global_eid = " << somar(5, 5) << std::endl;

    
    return 0;
}