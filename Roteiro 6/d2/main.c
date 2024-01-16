#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "deque.h"

int main(){
    Deque *D;
    int elem, escolha;
    printf("-<X Menu X>-\n");
    printf("1 - Criar Deque\n");
    printf("2 - Inserir um item no fim\n");
    printf("3 - Inserir um item no início\n");
    printf("4 - Ver o início do Deque\n");
    printf("5 - Ver o fim do Deque\n");
    printf("6 - Remover um item do fim\n");
    printf("7 - Remover um item do início\n");
    printf("8 - Imprimir o Deque\n");
    printf("9 - Destruir o Deque\n");
    printf("10 - Sair\n");

    while(true){
        printf("Escolha: ");
        scanf("%d", &escolha);

        if(escolha == 1){
            D = criaDeque();
            printf("-> Criado com sucesso!\n");
        }else if(escolha == 2){
            printf("-> Elemento a ser inserido no fim: ");
            scanf("%d",&elem);
            insereFim(D, elem);
            printf("-> Inserido com sucesso!\n");
        }else if(escolha == 3){
            printf("-> Elemento a ser inserido no início: ");
            scanf("%d",&elem);
            insereIni(D, elem);
            printf("-> Inserido com sucesso!\n");
        }else if(escolha == 4){
            verInicio(D, &elem);
            printf("-> Início: %d\n", elem);
        }else if(escolha == 5){
            verFim(D, &elem);
            printf("-> Fim: %d\n", elem);
        }else if(escolha == 6){
            removeFim(D);
            printf("-> Removido item do fim com sucesso!\n");
        }else if(escolha == 7){
            removeIni(D);
            printf("-> Removido item do início com sucesso!\n");
        }else if(escolha == 8){
            imprime(D);
        }else if(escolha == 9){
            destroiDeque(D);
            printf("-> Destruido com sucesso!\n");
        }else if(escolha == 10){
            printf("-> Finalizando!\n");
            break;
        }else{
            printf("-> Número inválido!\n");
        }
    }

    return 0;
}
