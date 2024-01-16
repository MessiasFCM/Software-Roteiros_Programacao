#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int escolha, elemento, conjuntoNumero, conjuntoNumero2, resultado;
    listadeConjuntos c;
    c.tamanho = 0;
    c.conjuntos = NULL;

    printf("--- MENU ---\n");
    printf("1 - Criar um conjunto vazio\n");
    printf("2 - União de dois conjuntos\n");
    printf("3 - Inserir elemento\n");
    printf("4 - Remover elemento\n");
    printf("5 - Intersecção entre dois conjuntos\n");
    printf("6 - Diferença de dois conjuntos\n");
    printf("7 - Número pertence ao conjunto\n");
    printf("8 - Menor valor do conjunto\n");
    printf("9 - Maior valor do conjunto\n");
    printf("10 - Testar se dois conjuntos são iguais\n");
    printf("11 - Tamanho do conjunto\n");
    printf("12 - Testar se o conjunto é vazio\n");
    printf("0 - Finalizar\n");

    while (true) {
        printf("Valor de escolha : ");
        scanf("%d", &escolha);

        switch (escolha) {
        case 1:
            criarConjunto(&c);
            printf("Novo conjunto criado\n");
            break;
        case 2:
            printf("Insira o número do primeiro conjunto : ");
            scanf("%d", &conjuntoNumero);
            printf("Insira o número do segundo conjunto : ");
            scanf("%d", &conjuntoNumero2);
            Conjunto uniao = uniaoConjuntos(c.conjuntos[conjuntoNumero - 1], c.conjuntos[conjuntoNumero2 - 1]);
            printf("União dos conjuntos é : ");
            for(int i = 0; i<uniao.quantidadeElementos; i++){
                printf("%d ", uniao.elementos[i]);
            }
            limpar(&uniao);
            printf("\n");
            break;
        case 3:
            printf("Insira qual o número do conjunto : ");
            scanf("%d", &conjuntoNumero);
            printf("Insira o número a ser adicionado : ");
            scanf("%d", &elemento);
            inserirElemento(&c.conjuntos[conjuntoNumero-1], elemento);
            break;
        case 4:
            printf("Insira qual o número do conjunto : ");
            scanf("%d", &conjuntoNumero);
            printf("Insira o número a ser removido : ");
            scanf("%d", &elemento);
            removerElemento(&c.conjuntos[conjuntoNumero-1], elemento);
            break;
        case 5:
            printf("Insira o número do primeiro conjunto : ");
            scanf("%d", &conjuntoNumero);
            printf("Insira o número do segundo conjunto : ");
            scanf("%d", &conjuntoNumero2);
            Conjunto intersecao = intersecaoConjuntos(c.conjuntos[conjuntoNumero - 1], c.conjuntos[conjuntoNumero2 - 1]);
            printf("Intersecção dos conjuntos é : ");
            for(int i = 0; i<intersecao.quantidadeElementos; i++){
                printf("%d ", intersecao.elementos[i]);
            }
            limpar(&intersecao);
            printf("\n");
            break;
        case 6:
            printf("Insira o número do primeiro conjunto : ");
            scanf("%d", &conjuntoNumero);
            printf("Insira o número do segundo conjunto : ");
            scanf("%d", &conjuntoNumero2);
            Conjunto diferenca = diferencaConjuntos(c.conjuntos[conjuntoNumero - 1], c.conjuntos[conjuntoNumero2 - 1]);
            printf("Diferença dos conjuntos é : ");
            for(int i = 0; i<diferenca.quantidadeElementos; i++){
                printf("%d ", diferenca.elementos[i]);
            }
            limpar(&diferenca);
            printf("\n");
            break;
        case 7:
            printf("Insira qual o número do conjunto : ");
            scanf("%d", &conjuntoNumero);
            printf("Insira o número a ser verificado : ");
            scanf("%d", &elemento);
            resultado = pertence(c.conjuntos[conjuntoNumero-1], elemento);
            if(resultado){
                printf("Pertence\n");
            }else{
                printf("Não pertence\n");
            }
            break;
        case 8:
            printf("Insira qual o número do conjunto : ");
            scanf("%d", &conjuntoNumero);
            resultado = menorValor(c.conjuntos[conjuntoNumero-1]);
            printf("O menor elemeno é : %d\n", resultado);
            break;
        case 9:
            printf("Insira qual o número do conjunto : ");
            scanf("%d", &conjuntoNumero);
            resultado = maiorValor(c.conjuntos[conjuntoNumero-1]);
            printf("O maior elemeno é : %d\n", resultado);
            break;
        case 10:
            printf("Insira o número do primeiro conjunto : ");
            scanf("%d", &conjuntoNumero);
            printf("Insira o número do segundo conjunto : ");
            scanf("%d", &conjuntoNumero2);
            resultado = saoIguais(c.conjuntos[conjuntoNumero-1], c.conjuntos[conjuntoNumero2-1]);
            if(resultado){
                printf("São iguais\n");
            }else{
                printf("Não são iguais\n");
            }
            break;
        case 11:
            printf("Insira qual o número do conjunto : ");
            scanf("%d", &conjuntoNumero);
            resultado = tamanho(c.conjuntos[conjuntoNumero-1]);
            printf("O tamanho é : %d\n", resultado);
            break;
        case 12:
            printf("Insira qual o número do conjunto : ");
            scanf("%d", &conjuntoNumero);
            resultado = eVazio(c.conjuntos[conjuntoNumero-1]);
            if(resultado){
                printf("É vazio\n");
            }else{
                printf("Não é vazio\n");
            }
            break;
        case 0:
            break;
        default:
            printf("Escolha inválida\n");
            break;
        }
        if(escolha == 0){ 
            for(int i = 0; i < c.tamanho; i++){
                limpar(&c.conjuntos[i]);
            }
            break; 
        }
    }
    
    return 0;
}