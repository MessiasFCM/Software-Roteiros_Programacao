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
#include <string.h>

typedef struct Aluno {
    char nome[100];
    int matricula;
    double nota;
} Aluno;

typedef struct NO{
    Aluno aluno;
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct NO* ABP;

NO* alocarNO(char nome[], int matricula, double nota){
    NO* novoAluno = (NO*) malloc (sizeof(NO));
    if(novoAluno != NULL){
        strcpy(novoAluno->aluno.nome, nome);
        novoAluno->aluno.matricula = matricula;
        novoAluno->aluno.nota = nota;
        novoAluno->esq = NULL;
        novoAluno->dir = NULL;
    }
    return novoAluno;
}

void liberarNO(NO* q){
    free(q);
}

ABP* criarABP(){
    ABP* raiz = (ABP*) malloc (sizeof(ABP));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void destroirRec(NO* no){
    if(no == NULL) return;
    destroirRec(no->esq);
    destroirRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroirABP(ABP* raiz){
    if(raiz != NULL){
        destroirRec(*raiz);
        free(raiz);
    }
}

int estaVazia(ABP* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}

int inserirRec(NO** raiz, char nome[], int matricula, double nota){
    if(*raiz == NULL){
        NO* novo = alocarNO(nome, matricula, nota);
        if(novo == NULL) return 0;
        *raiz = novo;
    }else{
        int comparacao = strcmp(nome, (*raiz)->aluno.nome);
        if(comparacao == 0){
            printf("-> Elemento Existente!\n");
            return 0;
        }
        if(comparacao < 0){
            return inserirRec(&(*raiz)->esq, nome, matricula, nota);
        }else if(comparacao > 0){
            return inserirRec(&(*raiz)->dir, nome, matricula, nota);
        }
    }
    return 1;
}

int inserirAluno(ABP* raiz, char nome[], int matricula, double nota){
    if(raiz == NULL) return 0;
    return inserirRec(raiz, nome, matricula, nota);
}

int pesquisarRec(NO** raiz, char nome[]){
    if(*raiz == NULL) return 0;
    int comparar = strcmp(nome, (*raiz)->aluno.nome);
    if (comparar == 0){
        return 1;
    }else if (comparar < 0){
        return pesquisarRec(&(*raiz)->esq, nome);
    }else{
        return pesquisarRec(&(*raiz)->dir, nome);
    }
}

int buscarAluno(ABP* raiz, char nome[]){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisarRec(raiz, nome);
}

NO* encontrarMaiorNotaRec(NO* raiz, double nota){
    if (raiz == NULL){
        return NULL;
    }
    NO* noMaiorNota = NULL;
    if(raiz->aluno.nota <= nota){
        noMaiorNota = encontrarMaiorNotaRec(raiz->dir, nota);
    }else{
        noMaiorNota = encontrarMaiorNotaRec(raiz->esq, nota);
        if(noMaiorNota == NULL || noMaiorNota->aluno.nota < raiz->aluno.nota){
            noMaiorNota = raiz;
        }
    }
    return noMaiorNota;
}

Aluno encontrarMaiorNota(ABP* raiz){
    NO* noMaiorNota = encontrarMaiorNotaRec(*raiz, 0);
    return noMaiorNota->aluno; 
}

NO* encontrarMenorNotaRec(NO* raiz, double nota){
    if(raiz == NULL){
        return NULL;
    }
    NO* noMenorNota = NULL;
    if(raiz->aluno.nota >= nota){
        noMenorNota = encontrarMenorNotaRec(raiz->esq, nota);
    }else{
        noMenorNota = encontrarMenorNotaRec(raiz->dir, nota);
        if(noMenorNota == NULL || noMenorNota->aluno.nota > raiz->aluno.nota){
            noMenorNota = raiz;
        }
    }
    return noMenorNota;
}

Aluno encontrarMenorNota(ABP* raiz){
    NO* noMenorNota = encontrarMenorNotaRec(*raiz, 9999);
    return noMenorNota->aluno;
}

int removerRec(NO** raiz, char nome[]){
    if(*raiz == NULL) return 0;
    int comparar = strcmp(nome, (*raiz)->aluno.nome);
    if(comparar == 0){
        NO* aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            liberarNO(*raiz);
            *raiz = NULL;
        }else if((*raiz)->esq == NULL){
            aux = *raiz;
            *raiz = (*raiz)->dir;
            liberarNO(aux);
        }else if((*raiz)->dir == NULL){
            aux = *raiz;
            *raiz = (*raiz)->esq;
            liberarNO(aux);
        }else{
            NO* Filho = (*raiz)->esq;
            while (Filho->dir != NULL){ 
                Filho = Filho->dir; 
            }
            (*raiz)->aluno = Filho->aluno;
            return removerRec(&(*raiz)->esq, nome);
        }
        return 1;
    }else if(comparar < 0){
        return removerRec(&(*raiz)->esq, nome);
    }
    else{
        return removerRec(&(*raiz)->dir, nome);
    }
}

NO* removerAtual(NO* atual){
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

int removerIte(NO** raiz, char nome[]){
    if(*raiz == NULL) return 0;
    NO* atual = *raiz, *ant = NULL;
    while(atual != NULL){
        int comparar = strcmp(nome, atual->aluno.nome);
        if(comparar == 0){
            if(atual == *raiz){
                *raiz = removerAtual(atual);
            }else if(ant->dir == atual){
                ant->dir = removerAtual(atual);
            }else if(ant->esq == atual){
                ant->esq = removerAtual(atual);
            }
            return 1;
        }
        ant = atual;
        if(comparar < 0){
            atual = atual->esq;
        }else{
            atual = atual->dir;
        }
    }
    return 0;
}

int removerAluno(ABP* raiz, char nome[]){
    if(buscarAluno(raiz, nome) == 0){
        printf("-> Elemento inexistente!\n");
        return 0;
    }
    return removerIte(raiz, nome);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        printf("-> [%s, %d, %.2lf, %d] \n", raiz->aluno.nome, raiz->aluno.matricula, raiz->aluno.nota, nivel);
        em_ordem(raiz->dir, nivel+1);
    }
}

void imprime(ABP* raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("-> Arvore Vazia!\n");
        return;
    }
    em_ordem(*raiz, 0);
}

#endif