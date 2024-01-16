/*---------------- File: AVL.h  ------------------------+
|Arvore AVL                                             |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 23/10/2023      |
+-------------------------------------------------------+ */

#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct Funcionario {
    char nome[100];
    double salario;
    int anoDeContratacao;
}Funcionario;

typedef struct NO{
    Funcionario funcionario;
    int fb, alt;
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct NO* AVL;

NO* alocarNO(char nome[], double salario, int anoDeContratacao){
    NO* novoFuncionario = (NO*) malloc (sizeof(NO));
    if(novoFuncionario != NULL){
        strcpy(novoFuncionario->funcionario.nome, nome);
        novoFuncionario->funcionario.salario = salario;
        novoFuncionario->funcionario.anoDeContratacao = anoDeContratacao;
        novoFuncionario->esq = NULL;
        novoFuncionario->dir = NULL;
    }
    return novoFuncionario;
}

void liberarNO(NO* q){
    free(q);
}

AVL* criaAVL(){
    AVL* raiz = (AVL*) malloc (sizeof(AVL));
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

void destroiAVL(AVL* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(AVL* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}

//Calcula FB
int altura(NO* raiz){
    if(raiz == NULL) return 0;
    if(raiz->alt > 0)
        return raiz->alt;
    else{ 
        //printf("Calculando altura do (%d)..\n", raiz->info);
        return MAIOR(altura(raiz->esq), altura(raiz->dir)) + 1;
    }
}

int FB(NO* raiz){
    if(raiz == NULL) return 0;
    printf("- Calculando FB do (%lf)..\n", raiz->funcionario.salario);
    return altura(raiz->esq) - altura(raiz->dir);
}

//Funcoes de Rotacao Simples
void avl_RotDir(NO** raiz){
   printf("- Rotacao Simples a DIREITA!\n");
   NO *aux;
   aux = (*raiz)->esq;
   (*raiz)->esq = aux->dir;
   aux->dir = *raiz;
   
   //Acertando alturas e FB
   //dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);

   *raiz = aux;
}

void avl_RotEsq(NO** raiz){
   printf("- Rotacao Simples a ESQUERDA!\n");
   NO *aux;
   aux = (*raiz)->dir;
   (*raiz)->dir = aux->esq;
   aux->esq = *raiz;
   
   //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);
   
   *raiz = aux;
}


//Funcoes de Rotacao Dupla
void avl_RotEsqDir(NO** raiz){
    printf("- Rotacao Dupla ESQUERDA-DIREITA!\n");
    NO *fe; //filho esquerdo
    NO *ffd; //filho filho direito
    
    fe = (*raiz)->esq;
    ffd = fe->dir;
    
    fe->dir = ffd->esq;
    ffd->esq = fe;
    
    (*raiz)->esq = ffd->dir;
    ffd->dir = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fe->alt = ffd->alt = -1;
    fe->alt = altura(fe); 
    ffd->alt = altura(ffd);
    (*raiz)->alt = altura(*raiz); 
    fe->fb = FB(fe); 
    ffd->fb = FB(ffd);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffd;
}


void avl_RotDirEsq(NO** raiz){
    printf("- Rotacao Dupla DIREITA-ESQUERDA!\n");
    NO* fd; //filho direito
    NO* ffe; //filho filho esquerdo

    fd = (*raiz)->dir;
    ffe = fd->esq;
    
    fd->esq = ffe->dir;
    ffe->dir = fd;
    
    (*raiz)->dir = ffe->esq;
    ffe->esq = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fd->alt = ffe->alt = -1;
    fd->alt = altura(fd); 
    ffe->alt = altura(ffe);
    (*raiz)->alt = altura(*raiz); 
    fd->fb = FB(fd);
    ffe->fb = FB(ffe);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffe;
}

void avl_RotEsqDir2(NO** raiz){
    printf("- Rotacao Dupla 2 ESQUERDA-DIREITA!\n");
    avl_RotEsq(&(*raiz)->esq);
    avl_RotDir(raiz);
}

void avl_RotDirEsq2(NO** raiz){
    printf("- Rotacao Dupla 2 DIREITA-ESQUERDA!\n");
    avl_RotDir(&(*raiz)->dir);
    avl_RotEsq(raiz);
}


//Funcoes Auxiliares referentes a cada filho
void avl_AuxFE(NO **raiz){
   NO* fe;
   fe = (*raiz)->esq;
   if(fe->fb == +1) /* Sinais iguais e positivo*/
     avl_RotDir(raiz);
   else /* Sinais diferentes*/
     avl_RotEsqDir(raiz);
}

void avl_AuxFD(NO **raiz){
   NO* fd;
   fd = (*raiz)->dir;
   if(fd->fb == -1) /* Sinais iguais e negativos*/
     avl_RotEsq(raiz);
   else /* Sinais diferentes*/
     avl_RotDirEsq(raiz);
}

int insereRec(NO** raiz, char nome[], double salario, int anoDeContratacao){
    int ok; //Controle para as chamadas recursivas
    if(*raiz == NULL){
        NO* novo = alocarNO(nome, salario, anoDeContratacao);
        if(novo == NULL) return 0;
        novo->fb = 0, 
        novo->alt = 1;
        novo->esq = NULL; novo->dir = NULL;
        *raiz = novo; return 1;
    }else{
        if((*raiz)->funcionario.salario == salario){
            printf("- Elemento Existente!\n"); ok = 0;
        }
        if(salario < (*raiz)->funcionario.salario){
            ok = insereRec(&(*raiz)->esq, nome, salario, anoDeContratacao);
            if(ok){
                switch((*raiz)->fb){
                    case -1:
                        (*raiz)->fb = 0; ok = 0; break;
                    case 0:
                        (*raiz)->fb = +1; 
                        (*raiz)->alt++; 
                        break;
                    case +1:
                        avl_AuxFE(raiz); ok = 0; break;
                }
            }
        }
        else if(salario > (*raiz)->funcionario.salario){
            ok = insereRec(&(*raiz)->dir, nome, salario, anoDeContratacao);
            if(ok){
                switch((*raiz)->fb){
                    case +1:
                        (*raiz)->fb = 0; ok = 0; break;
                    case 0:
                        (*raiz)->fb = -1; (*raiz)->alt++; break;
                    case -1:
                        avl_AuxFD(raiz); ok = 0; break;
                }
            }
        }
    }
    return ok;
}

int insereFuncionario(AVL* raiz, char nome[], double salario, int anoDeContratacao){
    if(raiz == NULL) return 0;
    return insereRec(raiz, nome, salario, anoDeContratacao);
}

int exibeInfoFuncionario(NO* raiz, double salario){
    if(raiz == NULL) return 0;
    if(raiz->funcionario.salario == salario){
        printf("Funcionário encontrado!\n");
        printf("Nome: %s\n", raiz->funcionario.nome);
        printf("Salário: %.2lf\n", raiz->funcionario.salario);
        printf("Ano de Contratação: %d\n", raiz->funcionario.anoDeContratacao);
        return 1;
    }else{
        if(salario < raiz->funcionario.salario){
            return exibeInfoFuncionario(raiz->esq, salario);
        }else{
            return exibeInfoFuncionario(raiz->dir, salario);
        }
    }
}

int pesquisaRec(NO** raiz, double salario){
    if(*raiz == NULL) return 0;
    if((*raiz)->funcionario.salario == salario) return 1;
    if(salario < (*raiz)->funcionario.salario)
        return pesquisaRec(&(*raiz)->esq, salario);
    else 
        return pesquisaRec(&(*raiz)->dir, salario);
}

int pesquisaFuncionario(AVL* raiz, double salario){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    int encontrado = pesquisaRec(raiz, salario);
    if(encontrado){
        exibeInfoFuncionario(*raiz, salario);
    }else{
        printf("- Funcionário não encontrado!\n");
    }
    return encontrado;
}

int removeRec(NO** raiz, double salario){
    if(*raiz == NULL) return 0;
    int ok;
    if((*raiz)->funcionario.salario == salario){
        NO* aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            //Caso 1 - NO sem filhos
            printf("- Caso 1: Liberando %lf..\n", (*raiz)->funcionario.salario);
            liberarNO(*raiz);
            *raiz = NULL;
        }else if((*raiz)->esq == NULL){
            //Caso 2.1 - Possui apenas uma subarvore direita
            printf("- Caso 2.1: Liberando %lf..\n", (*raiz)->funcionario.salario);
            aux = *raiz;
            *raiz = (*raiz)->dir;
            liberarNO(aux);
        }else if((*raiz)->dir == NULL){
            //Caso 2.2 - Possui apenas uma subarvore esquerda
            printf("- Caso 2.2: Liberando %lf..\n", (*raiz)->funcionario.salario);
            aux = *raiz;
            *raiz = (*raiz)->esq;
            liberarNO(aux);
        }else{
            //Caso 3 - Possui as duas subarvores (esq e dir)
            //Duas estrategias:
            //3.1 - Substituir pelo NO com o MAIOR valor da subarvore esquerda
            //3.2 - Substituir pelo NO com o MENOR valor da subarvore direita
            printf("- Caso 3: Liberando %lf..\n", (*raiz)->funcionario.salario);
            //Estrategia 3.1:
            NO* Filho = (*raiz)->esq;
            while(Filho->dir != NULL)//Localiza o MAIOR valor da subarvore esquerda
                Filho = Filho->dir;
            (*raiz)->funcionario.salario = Filho->funcionario.salario;
            Filho->funcionario.salario = salario;
            return removeRec(&(*raiz)->esq, salario);
        }
        return 1;
    }else if(salario < (*raiz)->funcionario.salario){
        ok = removeRec(&(*raiz)->esq, salario); 
        if(ok){
            switch((*raiz)->fb){
                case +1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case -1:
                    avl_AuxFD(raiz); break;
            }
        }
    }
    else{ 
        ok = removeRec(&(*raiz)->dir, salario);
        if(ok){
            switch((*raiz)->fb){
                case -1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case +1:
                    avl_AuxFE(raiz); break;
            }
        }
    }
    return ok;
}

int removeElem(AVL* raiz, double salario){
    if(pesquisaFuncionario(raiz, salario) == 0){
        printf("- Elemento inexistente!\n");
        return 0;
    }
    return removeRec(raiz, salario);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        //printf("[%d, %d, %d] ", raiz->info, raiz->fb, nivel);
        printf("- [%s, %lf, %d, %d, %d]\n", raiz->funcionario.nome, raiz->funcionario.salario, raiz->fb, nivel, raiz->alt);
        em_ordem(raiz->dir, nivel+1);
    }
}

void pre_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        printf("- [%s, %lf, %d, %d]\n",  raiz->funcionario.nome, raiz->funcionario.salario, raiz->fb, nivel);
        pre_ordem(raiz->esq, nivel+1);
        pre_ordem(raiz->dir, nivel+1);
    }
}

void pos_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        pos_ordem(raiz->esq, nivel+1);
        pos_ordem(raiz->dir, nivel+1);
        printf("- [%s, %lf, %d, %d]\n ",  raiz->funcionario.nome, raiz->funcionario.salario, raiz->fb, nivel);
    }
}

int contaNosRec(NO* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contaNosRec(raiz->esq) + contaNosRec(raiz->dir);
}

int contaNos(AVL* raiz) {
    if (raiz == NULL || estaVazia(raiz)) {
        return 0;
    }
    return contaNosRec(*raiz);
}

NO* encontrarMaiorSalarioRec(NO* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    NO* noMaiorSalario = raiz;
    while (noMaiorSalario->dir != NULL) {
        noMaiorSalario = noMaiorSalario->dir;
    }
    return noMaiorSalario;
}

Funcionario encontrarMaiorSalario(AVL* raiz){
    NO* noMaiorSalario = encontrarMaiorSalarioRec(*raiz);
    return noMaiorSalario->funcionario;
}

NO* encontrarMenorSalarioRec(NO* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    NO* noMenorSalario = raiz;
    while (noMenorSalario->esq != NULL) {
        noMenorSalario = noMenorSalario->esq;
    }
    return noMenorSalario;
}

Funcionario encontrarMenorSalario(AVL* raiz){
    NO* noMenorSalario = encontrarMenorSalarioRec(*raiz);
    return noMenorSalario->funcionario;
}

void imprime(AVL* raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("- Arvore Vazia!\n");
        return;
    }
    //printf("\nEm Ordem: [INFO, FB, NIVEL]\n"); 
    printf("\n- Em Ordem: [INFO, FB, NIVEL, altura]\n"); 
    em_ordem(*raiz, 0);
    //printf("\nPre Ordem: "); pre_ordem(*raiz, 0);
    //printf("\nPos Ordem: "); pos_ordem(*raiz, 0);
    printf("\n");
}


#endif