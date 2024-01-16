#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

int main() {
    int escolha, elemento;
    Lista l;
    inicializarLista(&l);

    printf("Menu\n");
    printf("1 - Tamanho\n");
    printf("2 - Procura\n");
    printf("3 - Inserir\n");
    printf("4 - Remoção\n");
    printf("5 - Imprimir elementos\n");
    printf("0 - Sair\n");
    while (true){
        printf("Opção : ");
        scanf("%d", &escolha);

        if(escolha == 0){
            break;
        }else if (escolha == 1) {
            int valor = tamanhoLista(&l);
            printf("Tamanho da lista é : %d\n", valor);
        }else if (escolha == 2) {
            printf("Elemento : ");
            scanf("%d", &elemento);
            int indice = procura(&l, elemento);
            if (indice != -1) {
                printf("Elemento encontrado no índice %d\n", indice);
            }else {
                printf("Elemento não encontrado\n");
            }
        }else if (escolha == 3) {
            printf("Elemento : ");
            scanf("%d", &elemento);
            inserirOrdenado(&l, elemento);
            printf("Elemento inserido na lista\n");
        }else if (escolha == 4) {
            printf("Elemento : ");
            scanf("%d", &elemento);
            removerPrimeiraOcorrencia(&l, elemento);
            printf("Elemento removido da lista\n");
        }else if(escolha == 5) {
            printf("Elementos na lista: ");
            imprimirLista(&l);
        }else{
            printf("Opção inválida\n");
        }
    }
    return 0;
}