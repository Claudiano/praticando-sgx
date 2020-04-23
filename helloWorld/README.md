# Hello World

Este repositorio foi criado para estudo da intel SGX. Os códigos encontrados nesse repositorio foram baseados do site: [**http://www.sgx101.com/portfolio/enclave_example/**](http://www.sgx101.com/portfolio/enclave_example/).

## Requisitos 

Para iniciar utilizar o Intel SGX é necessario que o processador tenha suporte a essa tecnologia e que a opção do Intel SGX esteja habilitada no setup da BIOS da máquina.
Esse exemplo foi desenvolvido sobre uma máquina linux, onde é necessario realizar a instalação do **SGX SDK**, nesse processo foi seguido os passos do seguinte link: [**https://github.com/intel/linux-sgx**](https://github.com/intel/linux-sgx)

## Executar

Primeiro realize a compilação do projeto através do comando:
```
 make SGX_MODE=SIM
```

Depois execute o arquivo compilado na pasta App
```
./app
```