#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fpse.h"

int main(){
    FilaP* F;
    int elem, escolha, prio;
    printf("-<X Menu X>-\n");
    printf("1 - Criar Fila\n");
    printf("2 - Inserir um item pela prioridade\n");
    printf("3 - Ver o início da Fila\n");
    printf("4 - Remover um item\n");
    printf("5 - Imprimir a Fila\n");
    printf("6 - Mostrar o tamanho da Fila\n");
    printf("7 - Destruir a Fila\n");
    printf("8 - Sair\n");

    while(true){
        printf("Escolha: ");
        scanf("%d", &escolha);

        if(escolha == 1){
            F = criaFila();
            printf("-> Criado com sucesso!\n");
        }else if(escolha == 2){
            printf("-> Elemento a ser inserido: ");
            scanf("%d",&elem);
            printf("-> Prioridade do elemento: ");
            scanf("%d",&prio);
            inserirPrio(F, elem, prio);
            printf("-> Inserido com sucesso!\n");
        }else if(escolha == 3){
            verIni(F, &elem);
            printf("-> Início: %d\n", elem);
        }else if(escolha == 4){
            removeIni(F);
            printf("-> Removido com sucesso!\n");
        }else if(escolha == 5){
            imprime(F);
        }else if(escolha == 6){
            int tamanho = tamanhoFila(F);
            printf("-> O tamanho da fila é: %d\n", tamanho);
        }else if(escolha == 7){
            destroiFila(F);
            printf("-> Destruido com sucesso!\n");
        }else if(escolha == 8){
            printf("-> Finalizando!\n");
            break;
        }else{
            printf("-> Número inválido!\n");
        }
    }

    return 0;
}
