#include <stdio.h>
#include <stdlib.h>

int preencherPosicoes(int *vetor, int N, int cont){
    if(cont < N){
        printf("Posição %d : ", cont + 1);
        scanf("%d", &vetor[cont]);
        preencherPosicoes(vetor, N, cont + 1);
    }
}

int vetorCrescente(int *vetor, int N, int cont){
    if(cont < N){
        printf("%d ", vetor[cont]);
        vetorCrescente(vetor, N, cont + 1);
    }
}

int vetorDecrescente(int *vetor, int N, int cont){
    if(cont < N){
        vetorDecrescente(vetor, N, cont + 1);
        printf("%d ", vetor[cont]);
    }
}

int maiorElemento(int *vetor, int N, int cont, int maior){
     if(cont < N){
        if(vetor[cont] >= maior){
            maior = vetor[cont];
        }
        maior = maiorElemento(vetor, N, cont + 1, maior);
    }
    return maior;
}

int main(){
    int N;
    printf("Valor do N : ");
    scanf("%d", &N);
    int *vetor = (int*)malloc(N*sizeof(int));
    preencherPosicoes(vetor, N, 0);

    printf("Vetor Crescente : ");
    vetorCrescente(vetor, N, 0);
    printf("\n");

    printf("Vetor Decrescente : ");
    vetorDecrescente(vetor, N, 0);
    printf("\n");

    printf("Maior Elemento: ");
    int maior = maiorElemento(vetor, N, 0, vetor[0]);
    printf("%d", maior);
    printf("\n");

    free(vetor);

    return 0;
}
