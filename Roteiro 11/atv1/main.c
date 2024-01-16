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

void ShellSort(int *v, int n) {
  int i, j, atual;
  int h = 1;
  while(h < n) h = 3*h+1;
  while (h > 0) {
    for(i = h; i < n; i++) {
      atual = v[i];
      j = i;
      while (j > h-1 && atual <= v[j - h]) {
        v[j] = v[j - h];
        j = j - h;
      }
      v[j] = atual;
    }
    h = h/3;
  }
}

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {
        while(v[i] < pivo){ i++;} 
        
        while(v[j] > pivo){ j--;} 
        
        if(i<j){
            troca(&v[i], &v[j]); 
            i++;
            j--;
        }else
            return j; 
    }    
}

void QuickSort(int *v, int ini, int fim, int n){
    if(ini < fim ){
        int q = particao(v, ini, fim);
        QuickSort(v, ini, q, n);
        QuickSort(v, q+1, fim, n);
    }
}

void Merge(int *v, int ini, int meio, int fim){
    int tam = fim-ini+1;
    int *A = (int*) malloc (tam*sizeof(int));
    int i = ini, j = meio+1, k = 0;
    while (i<=meio && j<=fim) {
        if (v[i] < v[j]){ A[k] = v[i]; i++; }
        else { A[k] = v[j]; j++; }
        k++;
    }
    while (i<=meio) { A[k] = v[i];  i++;  k++; }
    while (j<=fim) { A[k] = v[j];  j++;  k++; }
    for(i = ini, k=0; i<=fim; i++, k++) v[i] = A[k];
    free(A);
}

void MergeSort(int *v, int ini, int fim){
    if(ini < fim ){
        int meio = (ini + fim)/2;
        MergeSort(v, ini, meio);
        MergeSort(v, meio+1, fim);
        Merge(v, ini, meio, fim);
    }
}

void criaHeap(int *v, int pai, int fim){
    int aux = v[pai];
    int filho = 2*pai + 1;
    while(filho <= fim){
        if(filho < fim)
            if(v[filho] < v[filho+1])
                filho++;
        if(aux < v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = 2*pai + 1;
        }else filho = fim + 1;
    }
    v[pai] = aux;
}

void HeapSort(int *v, int n){
    int i;
    for(i=(n-1)/2; i>=0; i--)
        criaHeap(v, i, n-1);
    for(i=n-1; i>=1; i--){
        troca(&v[0], &v[i]);
        criaHeap(v, 0, i-1);
    }
}

int main(){
    int *v;
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    v = (int*) malloc (n*sizeof(int));

    printf("\n-> Digite os valores do vetor(ShellSort)\n");
    for(int i = 0; i<n; i++){
        printf("- Digite o valor [%d]: ", i+1);
        scanf("%d", &v[i]);
    }
    printf("\n-> Ordenando e imprimindo como ShellSort\n");
    ShellSort(v, n);
    imprimeVetor(v, n);

    printf("\n-> Digite os valores do vetor(QuickSort)\n");
    for(int i = 0; i<n; i++){
        printf("- Digite o valor [%d]: ", i+1);
        scanf("%d", &v[i]);
    }
    printf("\n-> Ordenando e imprimindo como QuickSort\n");
    QuickSort(v, 0, n-1, n);
    imprimeVetor(v, n);

    printf("\n-> Digite os valores do vetor(MergeSort)\n");
    for(int i = 0; i<n; i++){
        printf("- Digite o valor [%d]: ", i+1);
        scanf("%d", &v[i]);
    }
    printf("\n-> Ordenando e imprimindo como MergeSort\n");
    MergeSort(v, 0, n-1);
    imprimeVetor(v, n);

    printf("\n-> Digite os valores do vetor(HeapSort)\n");
    for(int i = 0; i<n; i++){
        printf("- Digite o valor [%d]: ", i+1);
        scanf("%d", &v[i]);
    }
    printf("\n-> Ordenando e imprimindo como HeapSort\n");
    HeapSort(v, n);
    imprimeVetor(v, n);

    free(v);
    return 0;
}