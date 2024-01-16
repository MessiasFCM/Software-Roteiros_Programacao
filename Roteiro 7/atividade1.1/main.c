#include <stdio.h>
#include <stdbool.h>
#include "matriz.h"

int main(){
    Matriz *M, *TS, *TI, *D, *T;
    int elemento, linha, coluna, escolha, inicio, fim;

    printf("-<X Menu X>-\n");
    printf("1 - Criar Matriz\n");
    printf("2 - Zerar Matriz\n");
    printf("3 - Preencher Aleatoriamente\n");
    printf("4 - Inserir Elemento\n");
    printf("5 - Consultar Elemento\n");
    printf("6 - É Matriz quadrada?\n");
    printf("7 - Criar Triangulo Sup\n");
    printf("8 - Criar Triangulo Inf\n");
    printf("9 - Criar Diagonal\n");
    printf("10 - Criar Transposta\n");
    printf("11 - É Simetrica?\n");
    printf("12 - Imprimir Matriz\n");
    printf("13 - Sair\n");

    while(true){
        printf("Escolha: ");
        scanf("%d", &escolha);

        if(escolha == 1){
            printf("-> Insira a quantidade de linha: ");
            scanf("%d",&linha);
            printf("-> Insira a quantidade de coluna: ");
            scanf("%d",&coluna);
            M = criaMatriz(linha, coluna);
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
            consultaElem(M, &elemento, linha, coluna);
            printf("-> Elemento consultado: %d\n", elemento);
        }else if(escolha == 6){
            if(e_matrizQuadrada(M)){
                printf("-> Matriz Quadrada!\n");
            }else{
                printf("-> Matriz não é Quadrada!\n");
            }
        }else if(escolha == 7){
            TS = criaTriangularSup(M); 
            imprime(TS);
        }else if(escolha == 8){
            TI = criaTriangularInf(M); 
            imprime(TI);
        }else if(escolha == 9){
            D = criaDiagonal(M);
            imprime(D);
        }else if(escolha == 10){
            T = criaTransposta(M);
            imprime(T);
        }else if(escolha == 11){
            if(e_Simetrica(M)){
                printf("-> Matriz Simétrica!\n");
            }else{
                printf("-> Matriz não Simétrica!\n");
            }
        }else if(escolha == 12){
            imprime(M);
        }else if(escolha == 13){
            destroiMatriz(M);
            printf("-> Finalizando!\n");
            break;
        }else{
            printf("-> Número inválido!\n");
        }
    }
    return 0;
}