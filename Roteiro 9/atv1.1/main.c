#include <stdio.h>
#include "AVL.h"

int main(){
    AVL* A;
    int escolha, resultado, elemento, nivel;

    printf("-=x Menu x=-\n");
    printf("1 - Criar AVL\n");
    printf("2 - Inserir um elemento\n");
    printf("3 - Buscar um elemento\n");
    printf("4 - Remover um elemento\n");
    printf("5 - Imprimir a AVL em ordem\n");
    printf("6 - Mostrar a quantidade de nós na AVL\n");
    printf("7 - Destruir a AVL\n");
    printf("8 - Sair\n");

    do{
        printf("\nInsira sua escolha: ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1: 
                A = criaAVL();
                printf("-> AVL criada com sucesso!");
                break;
            case 2: 
                printf("- Insira o elemento a ser adicionado: ");
                scanf("%d", &elemento);
                resultado = insereElem(A, elemento);
                if(resultado){
                    printf("-> Elemento adicionado com sucesso!");
                }else{
                    printf("-> Elemento não foi adicionado!");
                }
                break;
            case 3: 
                printf("- Insira o elemento a ser buscado: ");
                scanf("%d", &elemento);
                resultado = pesquisa(A, elemento);
                if(resultado){
                    printf("-> Elemento encontrado!");
                }else{
                    printf("-> Elemento não encontrado!");
                }
                break;
            case 4: 
                printf("- Insira o elemento a ser removido: ");
                scanf("%d", &elemento);
                resultado = removeElem(A, elemento);
                if(resultado){
                    printf("-> Elemento removido com sucesso!!");
                }else{
                    printf("-> Elemento não foi removido!");
                }
                break;
            case 5: 
                printf("- Insira o nível: ");
                scanf("%d", &nivel);
                em_ordem(*A, nivel);
                break;
            case 6: 
                resultado = contaNos(A);
                printf("-> Quantidade de nós: %d", resultado);
                break;
            case 7: 
                destroiAVL(A);
                printf("-> AVL destruida com sucesso!");
                break;
            default: 
                break;
        }
    }while(escolha < 8);

    return 0;
}