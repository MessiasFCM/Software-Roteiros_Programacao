# ifndef LISTA_H
# define LISTA_H

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct Lista {
    No* cabeca;
    int tamanho;
} Lista;

void inicializarLista(Lista *l);
int tamanhoLista(Lista* l);
int procura(Lista* l, int elemento);
void inserirOrdenado(Lista* l, int elemento);
void removerPrimeiraOcorrencia(Lista* l, int elemento);
void imprimirLista(Lista* l);

# endif