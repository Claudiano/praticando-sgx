echo "Iniciando..."
echo "Gerando interfaces de comunicação"
sgx_edger8r --trusted enclave.edl --search-path ${SGXSDK_PATH}/include 
sgx_edger8r --untrusted enclave.edl --search-path ${SGXSDK_PATH}/include

echo "Intefaces geradas"

echo "Compilando enclaves"
sgx_signer sign -key priv_key -enclave enclave.so -out enclave.signed.so -config enclave.config.xml

echo "Enclaves criados"