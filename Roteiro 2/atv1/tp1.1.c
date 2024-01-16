#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int numeroConta;
    double saldo;
    char* nomeTitular;
}ContaBancaria;

void criarConta(ContaBancaria* c, int numero, char *titular){
    c->numeroConta = numero;
    c->saldo = 0.0;
    c->nomeTitular = titular;
}

void depositar(ContaBancaria *c, double valor){
    c->saldo += valor;
}

void sacar(ContaBancaria *c, double valor){
    c->saldo -= valor;
}

double consultarSaldo(ContaBancaria *c){
    printf("Seu saldo é : %.2lf reais\n", c->saldo);
}

void imprimirInfo(ContaBancaria *c){
    printf("Imprimindo Informações\nNúmero da Conta : %d\nNome do Títular : %s\nSaldo : %.2lf reais\n ", c->numeroConta, c->nomeTitular, c->saldo);
}


int main(){
    ContaBancaria *c = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    criarConta(c,10,"Messias");
    depositar(c, 149.99);
    sacar(c, 49.99);
    consultarSaldo(c);
    imprimirInfo(c);
    free(c);

    return 0;
}