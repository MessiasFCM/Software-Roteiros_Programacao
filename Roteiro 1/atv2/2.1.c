#include <stdio.h>
#include <stdlib.h>

int crescente(int N){
    if(N > 0){
        crescente(N - 1);
        printf("%d ", N);
    }
}

int decrescente(int N){
    if(N > 0){
        printf("%d ", N);
        decrescente(N - 1);
    }
}

int main(){
    crescente(5);
    printf("\n");
    decrescente(5);
    printf("\n");

    return 0;
}
