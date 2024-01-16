#include <stdio.h>
#include <stdlib.h>

int negativos(float *vet, int N){
    int numeros_negativos = 0;
    for(int i = 0; i < N; i++){
        if(vet[i] < 0){
            numeros_negativos++;
        }
    }
    return numeros_negativos;
}

int main(){
    int N;
    scanf("%d", &N);

    float *vet = (float*)malloc(N*sizeof(float));
    for(int i = 0; i<N; i++){
        scanf("%f", &vet[i]);
    }

    int resultado = negativos(vet, 8);
    printf("Existem %d número(s) negativos no array\n", resultado);
    free(vet);

    return 0;
}
