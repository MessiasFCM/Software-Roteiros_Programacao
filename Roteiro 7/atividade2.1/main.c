#include <stdio.h>
#include <stdbool.h>
#include "mFaixa.h"

int main(){
    MFaixa *M;
    int elemento, linha, coluna, valor, escolha, inicio, fim;

    printf("-<X Menu X>-\n");
    printf("1 - Criar Matriz\n");
    printf("2 - Zerar Matriz\n");
    printf("3 - Preencher Aleatoriamente\n");
    printf("4 - Inserir Elemento\n");
    printf("5 - Consultar Elemento\n");
    printf("6 - Imprimir Matriz de Faixa(Vetores)\n");
    printf("7 - Imprimir Matriz de Faixa \n");
    printf("8 - Sair\n");

    while(true){
        printf("Escolha: ");
        scanf("%d", &escolha);

        if(escolha == 1){
            printf("-> Insira o valor para a matriz: ");
            scanf("%d",&valor);
            M = criaMatriz(valor);
            printf("-> Criado com sucesso!\n");
        }else if(escolha == 2){
            zeraMatriz(M);
            printf("-> Matriz Zerada com sucesso!\n");
        }else if(escolha == 3){
            printf("-> Insira um valor inicial: ");
            scanf("%d",&inicio);
            printf("-> Insira um valor final: ");
            scanf("%d",&fim);
            preencheAleatorio(M, inicio, fim);
            printf("-> Matriz preenchida aleatoriamente!\n");
        }else if(escolha == 4){
            printf("-> Elemento a ser inserido: ");
            scanf("%d",&elemento);
            printf("-> Insira a linha: ");
            scanf("%d",&linha);
            printf("-> Insira a coluna: ");
            scanf("%d",&coluna);
            insereElem(M, elemento, linha, coluna);
            printf("-> Inserido com sucesso!\n");
        }else if(escolha == 5){
            printf("-> Insira a linha: ");
            scanf("%d",&linha);
            printf("-> Insira a coluna: ");
            scanf("%d",&coluna);
            printf("-> Elemento consultado: %d\n", consultaElem(M, linha, coluna));
        }else if(escolha == 6){
            imprimeFaixaVetores(M);
        }else if(escolha == 7){
            imprimeFaixa(M);
        }else if(escolha == 8){
            destroiMatriz(M);
            printf("-> Finalizando!\n");
            break;
        }else{
            printf("-> Número inválido!\n");
        }
    }
    return 0;
}