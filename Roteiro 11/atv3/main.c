#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int comp, mov;

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
    while(h < n) { h = 3*h+1; comp++; }
    while (h > 0) {
        for(i = h; i < n; i++) {
            atual = v[i];
            j = i;
            while (j > h-1 && atual <= v[j - h]) {
                v[j] = v[j - h];
                j = j - h;
                comp++;
                mov++;
            }
            v[j] = atual;
            mov++;
        }
        h = h/3;
        comp++;
    }
}

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {
        while(v[i] < pivo){ i++; comp++;} 
        
        while(v[j] > pivo){ j--; comp++;} 
        
        if(i<j){
            troca(&v[i], &v[j]); 
            mov++;
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
        if (v[i] < v[j]){ A[k] = v[i]; i++;}
        else { A[k] = v[j]; j++; }
        k++;
        mov++;
        comp+=2;
    }
    while (i<=meio) { A[k] = v[i];  i++;  k++; comp++; mov++;}
    while (j<=fim) { A[k] = v[j];  j++;  k++; comp++; mov++;}
    for(i = ini, k=0; i<=fim; i++, k++) v[i] = A[k]; comp++; mov++;
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
        comp++;
        if(filho < fim)
            comp++;
            if(v[filho] < v[filho+1])
                filho++;
        if(aux < v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = 2*pai + 1;
            mov++;
        }else filho = fim + 1;
        comp++;
    }
    v[pai] = aux;
    mov++;
}

void HeapSort(int *v, int n){
    int i;
    for(i=(n-1)/2; i>=0; i--)
        criaHeap(v, i, n-1);
    for(i=n-1; i>=1; i--){
        troca(&v[0], &v[i]);
        mov++;
        criaHeap(v, 0, i-1);
    }
}

int main(){
    clock_t t;

    FILE *arquivo;
    int quantidade, escolha, i;


    arquivo = fopen("../valores/1000000-quaseordenado.txt", "r");

    if(arquivo == NULL){
        printf("-> Erro ao abrir o arquivo.\n");
        return 1;
    }

    fscanf(arquivo, "%d", &quantidade);
    int *vetor = (int *)malloc(quantidade * sizeof(int));

    if(vetor == NULL){
        printf("-> Erro ao alocar memória.\n");
        return 1;
    }

    for(i = 0; i < quantidade; i++){
        fscanf(arquivo, "%d", &vetor[i]);
    }    
    
    printf("-> Leitura do arquivo com sucesso!\n\n");

    printf("-=x Menu de Ordenação x=-\n");
    printf("1 - ShellSort\n");
    printf("2 - QuickSort\n");
    printf("3 - MergeSort\n");
    printf("4 - HeapSort\n");
    printf("5 - Sair\n");

    do{
        printf("\n-> Qual a sua escolha: ");
        scanf("%d", &escolha);

        comp = 0; mov = 0;
        if(escolha == 1){
            t = clock();
            ShellSort(vetor, quantidade);
            t = clock() - t;
        }else if(escolha == 2){
            t = clock();
            QuickSort(vetor, 0, quantidade-1, quantidade);
            t = clock() - t;
        }else if(escolha == 3){
            t = clock();
            MergeSort(vetor, 0, quantidade-1);
            t = clock() - t;
        }else if(escolha == 4){
            t = clock();
            HeapSort(vetor, quantidade);
            t = clock() - t;
        }else if(escolha == 5){
            break;
        }else{
            printf("-> Escolha Inválida!");
            break;
        }

        printf("-> Informacoes:\n");
        printf("- Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
        printf("- Comparacoes: %d\n", comp);
        printf("- Movimentacoes: %d\n", mov);
        printf("- Memoria (bytes): %ld\n", quantidade*sizeof(int));
    }while(escolha!=5);

    fclose(arquivo);
    free(vetor);
    return 0;
}