# ifndef LISTA_H
# define LISTA_H

#define TAM 100

typedef struct Lista {
   int elementos[TAM];
   int tamanho;
}Lista;

void inicializarLista(Lista *l);
int procura(Lista *l, int elemento);
void inserirOrdenado(Lista *l, int elemento);
int remover(Lista *l, int elemento);

# endif