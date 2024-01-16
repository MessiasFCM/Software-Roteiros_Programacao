#ifndef DDE_H
#define DDE_H

typedef struct NO{
    int info;
    struct NO* prox;
    struct NO* ant;
}NO;

typedef struct{
    int qtd;
    struct NO* ini;
    struct NO* fim;
}Deque;

NO* alocarNO();

void liberarNO(NO* q);

Deque* criaDeque();

void destroiDeque(Deque *dq);

int tamanhoDeque(Deque *dq);

int estaVazio(Deque *dq);

int insereIni(Deque* dq, int elem);

int insereFim(Deque* dq, int elem);

int removeIni(Deque* dq);

int removeFim(Deque* dq);

int verInicio(Deque* dq, int* p);

int verFim(Deque* dq, int* p);

void imprime(Deque* dq);

#endif