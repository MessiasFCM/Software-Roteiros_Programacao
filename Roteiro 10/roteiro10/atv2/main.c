#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

void InsertionSort(int *v, int n){
  int i, j, atual;
  for(i=1; i < n; i++){
    atual = v[i];
    for(j=i; (j>0) && (atual > v[j-1]); j--){
       v[j] = v[j-1];
    }
    v[j] = atual;
  }
}

void SelectionSort(int *v, int n){
  int i, j, menor;
  for(i=0; i < n-1; i++){
    menor = i;
    for(j=i+1; j < n; j++){
       if (v[j] > v[menor]) 
         menor = j;
    }
    if(i != menor){
      troca(&v[i], &v[menor]);
    }
  }
}

void BubbleSort(int *v, int n){
    int i, j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++){
             if (v[j]<v[j+1]) {
                 troca(&v[j], &v[j+1]);
             }
        }
}

int main(){
    int *v;
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    v = (int*) malloc (n*sizeof(int));

    printf("\n-> Digite os valores do vetor(Insertion)\n");
    for(int i = 0; i<n; i++){
        printf("- Digite o valor [%d]: ", i+1);
        scanf("%d", &v[i]);
    }
    printf("\n-> Ordenando e imprimindo como InsertionSort\n");
    InsertionSort(v, n);
    imprimeVetor(v, n);

    printf("\n-> Digite os valores do vetor(Selection)\n");
    for(int i = 0; i<n; i++){
        printf("- Digite o valor [%d]: ", i+1);
        scanf("%d", &v[i]);
    }
    printf("\n-> Ordenando e imprimindo como SelectionSort\n");
    SelectionSort(v, n);
    imprimeVetor(v, n);

    printf("\n-> Digite os valores do vetor(Bubble)\n");
    for(int i = 0; i<n; i++){
        printf("- Digite o valor [%d]: ", i+1);
        scanf("%d", &v[i]);
    }
    printf("\n-> Ordenando e imprimindo como BubbleSort\n");
    BubbleSort(v, n);
    imprimeVetor(v, n);

    free(v);
    return 0;
}