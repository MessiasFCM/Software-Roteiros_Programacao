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
    printf("-> Hashing por divisão(EnderAberto):\n");
    insereHash_EnderAbertoDivisao(H, 10);
    insereHash_EnderAbertoDivisao(H, 16);
    insereHash_EnderAbertoDivisao(H, 28);
    imprimeHash(H);

    if(buscaHash_EnderAbertoDivisao(H, 16, &resultado))
        printf("- Elemento encontrado: %d\n", resultado);
    else
        printf("- Elemento não encontrado.\n");
    
    destroiHash(H);

    printf("\n-> Hashing por multiplicação(EnderAberto):\n");
    H = criaHash(31);
    insereHash_EnderAbertoMultiplicacao(H, 11);
    insereHash_EnderAbertoMultiplicacao(H, 3);
    insereHash_EnderAbertoMultiplicacao(H, 24);
    imprimeHash(H);

    if(buscaHash_EnderAbertoMultiplicacao(H, 34, &resultado))
        printf("- Elemento encontrado: %d\n", resultado);
    else
        printf("- Elemento não encontrado.\n");
    
    destroiHash(H);

    printf("\n-> Hashing por dobra(EnderAberto):\n");
    H = criaHash(31);
    insereHash_EnderAbertoDobra(H, 17);
    insereHash_EnderAbertoDobra(H, 12);
    insereHash_EnderAbertoDobra(H, 21);
    imprimeHash(H);

    if(buscaHash_EnderAbertoDobra(H, 12, &resultado))
        printf("- Elemento encontrado: %d\n", resultado);
    else
        printf("- Elemento não encontrado.\n");
    
    destroiHash(H);

    return 0;
}