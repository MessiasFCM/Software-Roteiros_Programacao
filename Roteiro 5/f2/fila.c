#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila* criaFila(){
    Fila* fi = (Fila*)malloc(sizeof(Fila));
    if (fi != NULL){
        fi->qtd = 0;
        fi->ini = NULL;
        fi->fim = NULL;
    }
    return fi;
}

void destroiFila(Fila* fi){
    if (fi != NULL){
        NO* aux;
        while (fi->ini != NULL){
            aux = fi->ini;
            fi->ini = fi->ini->prox;
            free(aux);
        }
        free(fi);
    }
}

int tamanhoFila(Fila* fi){
    if (fi == NULL)
        return -1;
    return fi->qtd;
}

int estaVazia(Fila* fi){
    if (fi == NULL)
        return -1;
    return (fi->qtd == 0);
}

int enfileirar(Fila* fi, int elem){
    if (fi == NULL)
        return 0;
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL)
        return 0;
    novo->info = elem;
    novo->prox = NULL;
    if (fi->fim == NULL){
        fi->ini = novo;
    } else{
        fi->fim->prox = novo;
    }
    fi->fim = novo;
    fi->qtd++;
    return 1;
}

int desenfileirar(Fila* fi){
    if (fi == NULL || fi->ini == NULL)
        return 0;
    NO* aux = fi->ini;
    fi->ini = fi->ini->prox;
    free(aux);
    if (fi->ini == NULL)
        fi->fim = NULL;
    fi->qtd--;
    return 1;
}

int verInicio(Fila* fi, int* p){
    if (fi == NULL || fi->ini == NULL)
        return 0;
    *p = fi->ini->info;
    return 1;
}

void imprime(Fila* fi){
    if (fi == NULL) return;
    if (estaVazia(fi)){
        printf("Fila Vazia!\n");
        return;
    }
    NO* atual = fi->ini;
    printf("Elementos: \n");
    while (atual != NULL){
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}
