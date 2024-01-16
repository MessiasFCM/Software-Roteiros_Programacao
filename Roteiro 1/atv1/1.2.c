#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

int maiorElemento(int *vet){
    int numero_maior = 0;
    for(int i = 0; i < TAM; i++){
        if(vet[i] >= numero_maior){
            numero_maior = vet[i];
        }
    }
    return numero_maior;
}

int menorElemento(int *vet){
    int numero_menor = vet[0];
    for(int i = 0; i < TAM; i++){
        if(vet[i] <= numero_menor){
            numero_menor = vet[i];
        }
    }
    return numero_menor;
}

int mediaElementos(int *vet){
    int numero_medio = 0;
    for(int i = 0; i < TAM; i++){
        numero_medio += vet[i];
    }
    return numero_medio/TAM;
}

int main(){
    srand(time(NULL));
    for(int i = 1; i<=2; i++){
        int *vet = (int*)malloc(TAM*sizeof(int));
        for(int j = 0; j<TAM; j++){
            vet[j] = rand()%100;
        }
        int maior = maiorElemento(vet);
        int menor = menorElemento(vet);
        int media = mediaElementos(vet);
        printf("O vetor %d tem o maior número sendo %d, o menor sendo %d e a média sendo %d\n", i, maior, menor, media);
        free(vet);
    }
    return 0;
}
