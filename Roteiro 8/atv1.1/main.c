#include <stdio.h>
#include "ABP.h"

int main(){
    ABP* A;
    int escolha, elemento, nivel, resultado;

    printf("-=x Menu x=-\n");
    printf("1 - Criar ABP\n");
    printf("2 - Inserir um elemento\n");
    printf("3 - Buscar um elemento\n");
    printf("4 - Remover um elemento\n");
    printf("5 - Imprimir a ABP em ordem\n");
    printf("6 - Imprimir a ABP em pré-ordem\n");
    printf("7 - Imprimir a ABP em pós-ordem\n");
    printf("8 - Mostrar a quantidade de nós na ABP\n");
    printf("9 - Destruir a ABP\n");
    printf("10 - Sair\n");
    
    do{
        printf("\nInsira sua escolha: ");
        scanf("%d", &escolha);
        if(escolha == 1){
            A = criaABP();
            printf("-> ABP criada com sucesso!");
        }else if(escolha == 2){
            printf("- Insira o elemento a ser adicionado: ");
            scanf("%d", &elemento);
            resultado = insereElem(A, elemento);
            if(resultado){
                printf("-> Elemento adicionado com sucesso!");
            }else{
                printf("-> Elemento não foi adicionado!");
            }
        }else if(escolha == 3){
            printf("- Insira o elemento a ser buscado: ");
            scanf("%d", &elemento);
            resultado = pesquisa(A, elemento);
            if(resultado){
                printf("-> Elemento encontrado!");
            }else{
                printf("-> Elemento não encontrado!");
            }
        }else if(escolha == 4){
            printf("- Insira o elemento a ser removido: ");
            scanf("%d", &elemento);
            resultado = removeElem(A, elemento);
             if(resultado){
                printf("-> Elemento removido com sucesso!!");
            }else{
                printf("-> Elemento não foi removido!");
            }
        }else if(escolha == 5){
            printf("- Insira o nível: ");
            scanf("%d", &nivel);
            em_ordem(*A, nivel);
        }else if(escolha == 6){
            printf("- Insira o nível: ");
            scanf("%d", &nivel);
            pre_ordem(*A, nivel);
        }else if(escolha == 7){
            printf("- Insira o nível: ");
            scanf("%d", &nivel);
            pos_ordem(*A, nivel);
        }else if(escolha == 8){
            resultado = contaNos(A);
            printf("-> Quantidade de nós: %d", resultado);
        }else if(escolha == 9){
            destroiABP(A);
            printf("-> ABP destruida com sucesso!");
        }
    }while (escolha != 10);

    return 0;
}