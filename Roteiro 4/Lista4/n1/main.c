#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

int main() {
    int escolha, elemento;
    Lista l;
    inicializarLista(&l);

    while (true){
        printf("Menu\n");
        printf("1 - Inserir\n");
        printf("2 - Remoção\n");
        printf("3 - Procurar\n");
        printf("4 - Imprimir elementos\n");
        printf("0 - Sair\n");
        printf("Opção : ");
        scanf("%d", &escolha);

        if(escolha == 0){
            break;
        }else if (escolha == 1) {
            printf("Elemento : ");
            scanf("%d", &elemento);
            inserirOrdenado(&l, elemento);
            printf("Elemento inserido na lista\n");
        }else if (escolha == 2) {
            printf("Elemento : ");
            scanf("%d", &elemento);
            remover(&l, elemento);
            printf("Elemento removido da lista\n");
        }else if (escolha == 3) {
            printf("Elemento : ");
            scanf("%d", &elemento);
            int indice = procura(&l, elemento);
            if (indice != -1) {
                printf("Elemento encontrado no índice %d\n", indice);
            }else {
                printf("Elemento não encontrado\n");
            }
        }else if (escolha == 4) {
            printf("Elementos na lista: ");
            for (int i = 0; i < l.tamanho; i++) {
                printf("%d ", l.elementos[i]);
            }
            printf("\n");
        }else{
            printf("Opção inválida\n");
        }
    }
    return 0;
}