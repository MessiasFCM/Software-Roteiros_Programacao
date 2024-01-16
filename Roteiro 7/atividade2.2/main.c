#include <stdio.h>
#include <stdbool.h>
#include "matrizDin.h"
#include "mEsparsaCSR.h"

int main(){
    Matriz *M, *TS, *TI, *D, *T;
    MEsparsaCSR *MS;
    int elemento, linha, coluna, escolha, inicio, fim, qnn;

    printf("-<X Menu Matriz Din X>-\n");
    printf("1 - Criar Matriz Din\n");
    printf("2 - Zerar Matriz Din\n");
    printf("3 - Preencher Aleatoriamente\n");
    printf("4 - Inserir Elemento\n");
    printf("5 - Consultar Elemento\n");
    printf("6 - É Matriz quadrada?\n");
    printf("7 - Criar Triangulo Sup\n");
    printf("8 - Criar Triangulo Inf\n");
    printf("9 - Criar Diagonal\n");
    printf("10 - Criar Transposta\n");
    printf("11 - É Simetrica?\n");
    printf("12 - Imprimir Matriz Din\n\n");
    // --------------------------------------------------------------------------
    printf("-<X Menu Matriz Esparsa X>-\n");
    printf("13 - Criar Matriz Esparsa\n");
    printf("14 - Inserir Elemento\n");
    printf("15 - Remover Elemento\n");
    printf("16 - Transformar em CSR\n");
    printf("17 - Consultar Elemento\n");
    printf("18 - Imprimir Matriz Esparsa(Vetores)\n");
    printf("19 - Imprimir Matriz Esparsa\n");
    printf("20 - Finalizar\n");

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
        // --------------------------------------------------------------------------
        }else if(escolha == 13){
            printf("-> Insira a quantidade de linha: ");
            scanf("%d",&linha);
            printf("-> Insira a quantidade de coluna: ");
            scanf("%d",&coluna);
            printf("-> Insira a quantidade de não nulos: ");
            scanf("%d",&qnn);
            MS = criaMatrizEsparsa(linha, coluna, qnn);
        }else if(escolha == 14){
            printf("-> Insira o elemento: ");
            scanf("%d",&elemento);
            printf("-> Insira a linha: ");
            scanf("%d",&linha);
            printf("-> Insira a coluna: ");
            scanf("%d",&coluna);
            insereElemEsparsa(MS, elemento, linha, coluna);
        }else if(escolha == 15){
            printf("-> Insira a linha: ");
            scanf("%d",&linha);
            printf("-> Insira a coluna: ");
            scanf("%d",&coluna);
            removeElemEsparsa(MS, linha, coluna);
        }else if(escolha == 16){
            MS = transformarEmCSR(M);
            printf("-> Matriz tranformada com sucesso");
        }else if(escolha == 17){
            printf("-> Insira a linha: ");
            scanf("%d",&linha);
            printf("-> Insira a coluna: ");
            scanf("%d",&coluna);
            printf("-> Elemento consultado: %d\n", consultaElemEsparsa(MS, linha, coluna));
        }else if(escolha == 18){
            imprimeEsparsaVetores(MS);
        }else if(escolha == 19){
            imprimeEsparsa(MS);
        }else if(escolha == 20){
            destroiMatriz(M);
            destroiMatrizEsparsa(MS);
            printf("-> Finalizando!\n");
            break;
        }else{
            printf("-> Número inválido!\n");
        }
    }
    return 0;
}