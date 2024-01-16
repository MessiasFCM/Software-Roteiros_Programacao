#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>

void criarCubo(Cubo *c, int n){
    c->lado = n;
}

int medidaCubo(int n){
    return n;
}

int areaCubo(int n){
    return (n*n)*6;
}

int volumeCubo(int n){
    return (n*n*n);
}