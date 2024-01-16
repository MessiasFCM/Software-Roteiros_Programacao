#include <stdio.h>
#include <stdlib.h>

char ordemDecrescente(char* letras, int N){
    if(N >= 0){
        printf("%c ", letras[N-1]);
        ordemDecrescente(letras, N -1);
    }
}

int main(){
    char letras[] = {'M', 'E', 'S', 'S', 'I', 'A', 'S'};
    int N = sizeof(letras);

    ordemDecrescente(letras, N);
    printf("\n");

    return 0;
}
