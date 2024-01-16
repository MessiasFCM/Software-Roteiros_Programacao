#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

int main(){
    Pilha *P;
    int elem, escolha;
    printf("-<X Menu X>-\n");
    printf("1 - Criar pilha\n");
    printf("2 - Empilhar um item\n");
    printf("3 - Ver o topo da pilha\n");
    printf("4 - Desempilhar um item\n");
    printf("5 - Imprimir a pilha\n");
    printf("6 - Destruir a pilha\n");
    printf("7 - Sair\n");

    while(true){
        printf("Escolha: ");
        scanf("%d", &escolha);

        if(escolha == 1){
            P = criaPilha();
            printf("-> Criado com sucesso!\n");
        }else if(escolha == 2){
            printf("-> Elemento a ser empilhado: ");
            scanf("%d",&elem);
            empilhar(P, elem);
            printf("-> Empilhado com sucesso!\n");
        }else if(escolha == 3){
            verTopo(P, &elem);
            printf("-> O topo da pilha é : %d\n", elem);
        }else if(escolha == 4){
            desempilhar(P);
            printf("-> Desempilhado com sucesso!\n");
        }else if(escolha == 5){
            imprime(P);
        }else if(escolha == 6){
            destroiPilha(P);
            printf("-> Destruido com sucesso!\n");
        }else if(escolha == 7){
            printf("-> Finalizando!\n");
            break;
        }else{
            printf("-> Número inválido!\n");
        }
    }
    return 0;
}
