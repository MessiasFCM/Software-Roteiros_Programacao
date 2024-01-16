#include <stdio.h>
#include <stdlib.h>

int multiplicacaoRecursiva(int N, int M){
    if(N == 0){
        return 0;
    }else if(N > 0){
        return M + multiplicacaoRecursiva(N-1, M);
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int resultado = multiplicacaoRecursiva(N, M);
    printf("A multiplicação de %d por %d é %d\n", N, M, resultado);

    return 0;
}
