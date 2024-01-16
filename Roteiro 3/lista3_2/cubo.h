#ifndef CUBO_H
#define CUBO_H

typedef struct{
    int lado;
}Cubo;

void criarCubo(Cubo *c, int n);
int medidaCubo(int n);
int areaCubo(int n);
int volumeCubo(int n);

#endif