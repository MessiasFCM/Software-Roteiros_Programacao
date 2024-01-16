#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Conjunto criar_conjunto_vazio() {
    Conjunto n;
    n.elementos = NULL;
    n.quantidadeElementos = 0;
    return n;
}

void criarConjunto(listadeConjuntos *c){
    if(c->tamanho == 0) {
        c->tamanho = 1;
        c->conjuntos = (Conjunto*)malloc(sizeof(Conjunto));
        c->conjuntos[0] = criar_conjunto_vazio();
    }else {
        c->tamanho++;
        int nt = sizeof(listadeConjuntos);
        c->conjuntos = (Conjunto*)realloc(c->conjuntos, c->tamanho*sizeof(Conjunto));
        c->conjuntos[c->tamanho-1] = criar_conjunto_vazio();
    }
}

Conjunto uniaoConjuntos(Conjunto c1, Conjunto c2) {
    Conjunto uniao = criar_conjunto_vazio();
    for (int i = 0; i < c1.quantidadeElementos; i++) {
        inserirElemento(&uniao, c1.elementos[i]);
    }
    for (int i = 0; i < c2.quantidadeElementos; i++) {
        if (!pertence(uniao, c2.elementos[i])) {
            inserirElemento(&uniao, c2.elementos[i]);
        }
    }
    return uniao;
}

void inserirElemento(Conjunto *c, int elemento) {
    for (int i = 0; i < c->quantidadeElementos; i++) {
        if (c->elementos[i] == elemento) {
            return;
        }
    }
    c->quantidadeElementos++;
    c->elementos = (int *)realloc(c->elementos, c->quantidadeElementos * sizeof(int));
    c->elementos[c->quantidadeElementos - 1] = elemento;
}

void removerElemento(Conjunto *c, int elemento) {
    for (int i = 0; i < c->quantidadeElementos; i++) {
        if (c->elementos[i] == elemento) {
            for (int j = i; j < c->quantidadeElementos - 1; j++) {
                c->elementos[j] = c->elementos[j + 1];
            }
            c->quantidadeElementos--;
            c->elementos = (int *)realloc(c->elementos, c->quantidadeElementos * sizeof(int));
            return;
        }
    }
}

Conjunto intersecaoConjuntos(Conjunto c1, Conjunto c2) {
    Conjunto intersecao = criar_conjunto_vazio();
    for (int i = 0; i < c1.quantidadeElementos; i++) {
        if (pertence(c2, c1.elementos[i])) {
            inserirElemento(&intersecao, c1.elementos[i]);
        }
    }
    return intersecao;
}

Conjunto diferencaConjuntos(Conjunto c1, Conjunto c2) {
    Conjunto diferenca = criar_conjunto_vazio();
    for (int i = 0; i < c1.quantidadeElementos; i++) {
        if (!pertence(c2, c1.elementos[i])) {
            inserirElemento(&diferenca, c1.elementos[i]);
        }
    }
    return diferenca;
}

int pertence(Conjunto c, int numero) {
    for (int i = 0; i < c.quantidadeElementos; i++) {
        if (c.elementos[i] == numero) {
            return 1; 
        }
    }
    return 0; 
}

int menorValor(Conjunto c) {
    if (c.quantidadeElementos == 0) {
        return -1; 
    }
    int menor = c.elementos[0];
    for (int i = 1; i < c.quantidadeElementos; i++) {
        if (c.elementos[i] < menor) {
            menor = c.elementos[i];
        }
    }
    return menor;
}

int maiorValor(Conjunto c) {
    if (c.quantidadeElementos == 0) {
        return -1; 
    }
    int maior = c.elementos[0];
    for (int i = 1; i < c.quantidadeElementos; i++) {
        if (c.elementos[i] > maior) {
            maior = c.elementos[i];
        }
    }
    return maior;
}

int saoIguais(Conjunto c1, Conjunto c2) {
    if (c1.quantidadeElementos != c2.quantidadeElementos) {
        return false;
    }
    for (int i = 0; i < c1.quantidadeElementos; i++) {
        if (!pertence(c2, c1.elementos[i])) {
            return false;
        }
    }
    return true; 
}

int tamanho(Conjunto c) {
    if(c.elementos == NULL || c.quantidadeElementos == 0){
        return 0;
    }else{
        return c.quantidadeElementos;
    }
}

int eVazio(Conjunto c) {
    if(c.elementos == NULL || c.quantidadeElementos == 0){
        return true;
    }else{
        return false;
    }
}

void limpar(Conjunto *c) {
    free(c->elementos);
    c->elementos = NULL;
    c->quantidadeElementos = 0;
}

