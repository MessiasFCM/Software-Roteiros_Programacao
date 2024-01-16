#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct{
    int *elementos;
    int quantidadeElementos;
}Conjunto;

typedef struct{
    Conjunto *conjuntos;
    int tamanho;
}listadeConjuntos;

Conjunto criar_conjunto_vazio();
void criarConjunto(listadeConjuntos *c);
Conjunto uniaoConjuntos(Conjunto c1, Conjunto c2);
void inserirElemento(Conjunto *c, int elemento);
void removerElemento(Conjunto *c, int elemento);
Conjunto intersecaoConjuntos(Conjunto c1, Conjunto c2);
Conjunto diferencaConjuntos(Conjunto c1, Conjunto c2);
int pertence(Conjunto c, int numero);
int menorValor(Conjunto c);
int maiorValor(Conjunto c);
int saoIguais(Conjunto c1, Conjunto c2);
int tamanho(Conjunto c);
int eVazio(Conjunto c);
void limpar(Conjunto *c);

#endif