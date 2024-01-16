#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raizes(float A, float B, float C, float* X1, float * X2){
    int delta = ((B*B) - (4*A*C));
    if(delta > 0){
        *X1 = ((-B + sqrt(delta)) / 2*A);
        *X2 = ((-B - sqrt(delta)) / 2*A);
        return 2;
    }else if(delta == 0){
        *X1 = ((-B + sqrt(delta)) / 2*A);
        return 1;
    }else{
        return 0;
    }

}

int main(){
    float A, B, C;
    float *X1 = (float*)malloc(sizeof(float));
    float *X2 = (float*)malloc(sizeof(float));

    printf("Digite os valores de A, B e C: ");
    scanf("%f %f %f", &A, &B, &C);

    int qtd = raizes(A, B, C, X1, X2);

    if(qtd == 2){
        printf("As raízes são: %.2f e %.2f\n", *X1, *X2);
    }else if (qtd == 1){
        printf("A raíze é: %.2f\n", *X1);
    }else{
        printf("Não existe raíze\n");    
    }

    free(X1);
    free(X2);
    
    return 0;
}
