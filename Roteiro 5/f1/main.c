#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

int main(){
    Fila *F;
    int elem, escolha;
    printf("-<X Menu X>-\n");
    printf("1 - Criar fila\n");
    printf("2 - Enfileirar um item\n");
    printf("3 - Ver o inı́cio da fila\n");
    printf("4 - Desenfileirar um item\n");
    printf("5 - Imprimir a fila\n");
    printf("6 - Destruir a fila\n");
    printf("7 - Sair\n");

    while(true){
        printf("Escolha: ");
        scanf("%d", &escolha);

        if(escolha == 1){
            F = criaFila();
            printf("-> Criado com sucesso!\n");
        }else if(escolha == 2){
            printf("-> Elemento a ser enfileirado: ");
            scanf("%d",&elem);
            enfileirar(F, elem);
            printf("-> Efileirado com sucesso!\n");
        }else if(escolha == 3){
            verInicio(F, &elem);
            printf("-> Frente: %d\n", elem);
        }else if(escolha == 4){
            printf("-> Desenfileirado primeiro elemento\n");
            desenfileirar(F);
            printf("-> Desenfileirado com sucesso!\n");
        }else if(escolha == 5){
            imprime(F);
        }else if(escolha == 6){
            destroiFila(F);
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
