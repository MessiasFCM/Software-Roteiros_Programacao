#include "lista.h"
#include <stdio.h> 
#include <stdlib.h>

void inicializarLista(Lista *l) {
   l->tamanho = 0;
}

int procura(Lista *l, int elemento) {
   for (int i = 0; i < l->tamanho; i++) {
       if (l->elementos[i] == elemento) {
           return i;
       }
   }
   return -1;
}

void inserirOrdenado(Lista *l, int elemento) {
   if (l->tamanho == TAM) {
       return;
   }
   int i = l->tamanho - 1;
   while (i >= 0 && l->elementos[i] > elemento) {
       l->elementos[i + 1] = l->elementos[i];
       i--;
   }
   l->elementos[i + 1] = elemento;
   l->tamanho++;
}

int remover(Lista *l, int elemento) {
   int indice = procura(l, elemento);
   if (indice != -1) {
       for (int i = indice; i < l->tamanho - 1; i++) {
           l->elementos[i] = l->elementos[i + 1];
       }
       l->tamanho--;
   }
   return indice;
}