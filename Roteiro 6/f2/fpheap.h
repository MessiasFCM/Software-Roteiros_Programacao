#ifndef FPHEAP_H
#define FPHEAP_H

#define MAX 100
typedef struct NO{
    int info, prio;
}NO;
typedef struct{
    int qtd;
    NO dados[MAX];
}FilaP;

FilaP* criaFila();

void destroiFila(FilaP* fp);

int tamanhoFila(FilaP *fp);

int estaCheia(FilaP *fp);

int estaVazia(FilaP *fp);

void trocaNO(NO* a, NO* b);

void ajustaHeapInsere(FilaP* fp, int filho);

int inserirPrio(FilaP* fp, int elem, int pri);

void ajustaHeapRemove(FilaP* fp, int pai);

int removeIni(FilaP* fp);

int verIni(FilaP* fp, int* valor, int* pri);

void imprime(FilaP* fp);

#endif