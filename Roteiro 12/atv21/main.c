#include <stdio.h>
#include "Hash.h"

void binary(int n){
	if(n<2) 
          printf("%d", n%2);
	else{
          binary(n/2);
	  printf("%d", n%2);
	}
}

int main() {
    Hash *H;
    int resultado;

    H = criaHash(31);
    printf("-> Hashing por divisão(semTratar):\n");
    insereHash_semTratarDivisao(H, 10);
    insereHash_semTratarDivisao(H, 16);
    insereHash_semTratarDivisao(H, 28);
    imprimeHash(H);

    if(buscaHash_semTratarDivisao(H, 16, &resultado))
        printf("- Elemento encontrado: %d\n", resultado);
    else
        printf("- Elemento não encontrado.\n");
    
    destroiHash(H);

    printf("\n-> Hashing por multiplicação(semTratar):\n");
    H = criaHash(31);
    insereHash_semTratarMultiplicacao(H, 11);
    insereHash_semTratarMultiplicacao(H, 3);
    insereHash_semTratarMultiplicacao(H, 24);
    imprimeHash(H);

    if(buscaHash_semTratarMultiplicacao(H, 34, &resultado))
        printf("- Elemento encontrado: %d\n", resultado);
    else
        printf("- Elemento não encontrado.\n");
    
    destroiHash(H);

    printf("\n-> Hashing por dobra(semTratar):\n");
    H = criaHash(31);
    insereHash_semTratarDobra(H, 17);
    insereHash_semTratarDobra(H, 12);
    insereHash_semTratarDobra(H, 21);
    imprimeHash(H);

    if(buscaHash_semTratarDobra(H, 12, &resultado))
        printf("- Elemento encontrado: %d\n", resultado);
    else
        printf("- Elemento não encontrado.\n");
    
    destroiHash(H);

    return 0;
}