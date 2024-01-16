#include <stdio.h>
#include "HashLSE.h"

int main(){

    Hash *H;
    H = criaHash(15);

    int i, resultado;
    for(i=0; i<100; i++)
        insereHashLSE(H, i);

    insereHashLSE(H, 32);
    insereHashLSE(H, 32);
    insereHashLSE(H, 32);

    imprimeHash(H);

    if(buscaHashLSE(H, 32, &resultado))
        printf("\n- Elemento encontrado: %d\n", resultado);
    else
        printf("\n- Elemento não encontrado.\n");

    destroiHash(H);
    return 0;
}