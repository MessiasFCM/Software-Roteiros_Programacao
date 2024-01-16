#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int comp, mov;

int* copiaVetor(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}
void imprimeVetor(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void preencheAleatorio(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++)
        v[i] = ini + rand() % (fim-ini + 1); 
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
    comp++;
    for(j=i; (j>0) && (atual < v[j-1]); j--){
       v[j] = v[j-1];
       comp++;
       mov++;
    }
    v[j] = atual;
  }
}

void SelectionSort(int *v, int n){
  int i, j, menor;
  for(i=0; i < n-1; i++){
    menor = i;
    for(j=i+1; j < n; j++){
       comp++;
       if (v[j] < v[menor]) 
         menor = j;
    }
    if(i != menor){
      troca(&v[i], &v[menor]);
      mov++;
    }
  }
}

void BubbleSort(int *v, int n){
    int i, j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++){
			 comp++;
             if (v[j]>v[j+1]) {
                 troca(&v[j], &v[j+1]);
				 mov++;
             }
        }
}

int main(){
    clock_t t;

    FILE *arquivo;
    int quantidade, escolha, i;


    arquivo = fopen("../valores/1000000-contrario.txt", "r");

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

    do{
        printf("-=x Menu de Ordenação x=-\n");
        printf("1 - InsertionSort\n");
        printf("2 - SelectionSort\n");
        printf("3 - BubbleSort\n");
        printf("4 - Sair\n\n");
        printf("-> Qual a sua escolha: ");
        scanf("%d", &escolha);

        comp = 0; mov = 0;
        if(escolha == 1){
            t = clock();
            InsertionSort(vetor, quantidade);
            t = clock() - t;
        }else if(escolha == 2){
            t = clock();
            SelectionSort(vetor, quantidade);
            t = clock() - t;
        }else if(escolha == 3){
            t = clock();
            BubbleSort(vetor, quantidade);
            t = clock() - t;
        }else{
            printf("-> Escolha Inválida!");
            break;
        }

        printf("-> Informacoes:\n");
        printf("- Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
        printf("- Comparacoes: %d\n", comp);
        printf("- Movimentacoes: %d\n", mov);
        printf("- Memoria (bytes): %ld\n", quantidade*sizeof(int));
    }while(escolha!=4);

    fclose(arquivo);
    free(vetor);
    return 0;
}