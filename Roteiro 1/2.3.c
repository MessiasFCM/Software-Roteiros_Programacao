#include <stdio.h>
#include <stdlib.h>

int somaNumero(int maior, int menor){
    if(maior > menor){
        return maior + somaNumero(maior - 1, menor);
    }
}

int main(){
    int menor, maior;
    scanf("%d %d", &menor, &maior);
    int resultado = somaNumero(maior, menor);
    printf("%d\n", resultado);
    return 0;
}
