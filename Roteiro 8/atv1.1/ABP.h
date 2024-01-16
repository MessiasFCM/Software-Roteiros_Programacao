/*---------------- File: ABP.h  ------------------------+
|Arvore Binaria de Pesquisa (ABP)                       |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 12/10/2023      |
+-------------------------------------------------------+ */

#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct NO* ABP;

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

ABP* criaABP(){
    ABP* raiz = (ABP*) malloc (sizeof(ABP));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void destroiRec(NO* no){
    if(no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiABP(ABP* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(ABP* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}


int insereRec(NO** raiz, int elem){
    if(*raiz == NULL){
        NO* novo = alocarNO();
        if(novo == NULL) return 0;
        novo->info = elem;
        novo->esq = NULL; novo->dir = NULL;
        *raiz = novo;
    }else{
        if((*raiz)->info == elem){
            printf("-> Elemento Existente!\n"); 
            return 0;
        }
        if(elem < (*raiz)->info)
            return insereRec(&(*raiz)->esq, elem);
        else if(elem > (*raiz)->info)
            return insereRec(&(*raiz)->dir, elem);
    }
    return 1;
}

int insereIte(NO** raiz, int elem){
    NO *aux = *raiz, *ant = NULL;
    while (aux != NULL){
        ant = aux;
        if(aux->info == elem){
            printf("-> Elemento Existente!\n"); 
            return 0;
        }
        if(elem < aux->info) aux = aux->esq;
        else aux = aux->dir;
    }
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->esq = NULL; novo->dir = NULL;
    if(ant == NULL){
        *raiz = novo;
    }else{
        if(elem < ant->info) ant->esq = novo;
        else ant->dir = novo;
    }
    return 1;
}

int insereElem(ABP* raiz, int elem){
    if(raiz == NULL) return 0;
    return insereRec(raiz, elem);
}

int pesquisaRec(NO** raiz, int elem){
    if(*raiz == NULL) return 0;
    if((*raiz)->info == elem) return 1;
    if(elem < (*raiz)->info)
        return pesquisaRec(&(*raiz)->esq, elem);
    else 
        return pesquisaRec(&(*raiz)->dir, elem);
}

int pesquisaIte(NO** raiz, int elem){
    NO* aux = *raiz;
    while(aux != NULL){
        if(aux->info == elem) return 1;
        if(elem < aux->info)
            aux = aux->esq;
        else 
            aux = aux->dir;
    }
    return 0;
}

int pesquisa(ABP* raiz, int elem){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, elem);
}

int removeRec(NO** raiz, int elem){
    if(*raiz == NULL) return 0;
    if((*raiz)->info == elem){
        NO* aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            printf("-> Caso 1: Liberando %d..\n", (*raiz)->info);
            liberarNO(*raiz);
            *raiz = NULL;
        }else if((*raiz)->esq == NULL){
            printf("-> Caso 2.1: Liberando %d..\n", (*raiz)->info);
            aux = *raiz;
            *raiz = (*raiz)->dir;
            liberarNO(aux);
        }else if((*raiz)->dir == NULL){
            printf("-> Caso 2.2: Liberando %d..\n", (*raiz)->info);
            aux = *raiz;
            *raiz = (*raiz)->esq;
            liberarNO(aux);
        }else{
            printf("-> Caso 3: Liberando %d..\n", (*raiz)->info);
            NO* Filho = (*raiz)->esq;
            while(Filho->dir != NULL)
                Filho = Filho->dir;
            (*raiz)->info = Filho->info;
            Filho->info = elem;
            return removeRec(&(*raiz)->esq, elem);
        }
        return 1;
    }else if(elem < (*raiz)->info)
        return removeRec(&(*raiz)->esq, elem);
    else 
        return removeRec(&(*raiz)->dir, elem);
}

NO* removeAtual(NO* atual){
    NO* no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        liberarNO(atual);
        return no2;
    }

    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    liberarNO(atual);
    return no2;
}

int removeIte(NO** raiz, int elem){
    if(*raiz == NULL) return 0;
    NO* atual = *raiz, *ant = NULL;
    while(atual != NULL){
        if(elem == atual->info){
            if(atual == *raiz)
                *raiz = removeAtual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = removeAtual(atual);
                else
                    ant->esq = removeAtual(atual);
            }
            return 1;
        }
        ant = atual;
        if(elem < atual->info)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return 0;
}

int removeElem(ABP* raiz, int elem){
    if(pesquisa(raiz, elem) == 0){
        printf("-> Elemento inexistente!\n");
        return 0;
    }
    return removeIte(raiz, elem);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        printf("-> [%d, %d] ", raiz->info,nivel);
        em_ordem(raiz->dir, nivel+1);
    }
}

void pre_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        printf("-> [%d, %d] ", raiz->info,nivel);
        pre_ordem(raiz->esq, nivel+1);
        pre_ordem(raiz->dir, nivel+1);
    }
}

void pos_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        pos_ordem(raiz->esq, nivel+1);
        pos_ordem(raiz->dir, nivel+1);
        printf("-> [%d, %d] ", raiz->info,nivel);
    }
}

int contaNosRec(NO* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contaNosRec(raiz->esq) + contaNosRec(raiz->dir);
}

int contaNos(ABP* raiz) {
    if (raiz == NULL || estaVazia(raiz)) {
        return 0;
    }
    return contaNosRec(*raiz);
}

void imprime(ABP* raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("-> Arvore Vazia!\n");
        return;
    }
    printf("\n- Em Ordem: "); em_ordem(*raiz, 0);
    printf("\n- Pre Ordem: "); pre_ordem(*raiz, 0);
    printf("\n- Pos Ordem: "); pos_ordem(*raiz, 0);
    printf("\n");
}

#endif