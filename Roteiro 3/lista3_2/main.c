#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    Cubo c;
    printf("Número de lados : ");
    scanf("%d", &n);
    criarCubo(&c, n);
    printf("-> Valor do lado : %d\n", medidaCubo(c.lado));
    printf("-> Valor da área : %d\n", areaCubo(c.lado));
    printf("-> Valor do volume : %d\n", volumeCubo(c.lado));
    return 0;
}