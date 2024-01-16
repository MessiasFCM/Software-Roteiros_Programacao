#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct sPessoa{
    char nome[50];
    int idade;
}Pessoa;

int comp; 
int mov; 

void preencheVetorPessoa(Pessoa* v, int n){
    int i;
    for(i=0; i<n; i++){
        while(getchar() != '\n');
        printf("Digite o nome: ");
        scanf("%s", v[i].nome);
        printf("Digite a idade: ");
        scanf("%d", &v[i].idade);
    }
}

void imprimeVetorPessoa(Pessoa* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("(%s, %d)", v[i].nome, v[i].idade); prim = 0; }
        else printf(", (%s, %d)", v[i].nome, v[i].idade);
    printf("]\n");
}

void trocaPessoa(Pessoa* a, Pessoa *b){
    char auxNome[50];
    int auxIdade;
    strcpy(auxNome, a->nome);
    auxIdade = a->idade;
    strcpy(a->nome, b->nome);
    a->idade = b->idade;
    strcpy(b->nome, auxNome);
    b->idade = auxIdade;
}

int comparaPessoa(Pessoa* a, Pessoa* b){
    if(strcmp(a->nome, b->nome) < 0) return 1;
    else if(strcmp(a->nome, b->nome) > 0) return 0;
    else{ 
        if(a->idade < b->idade) return 1;
        else return 0;
    }
}

void SelectionSortPessoa(Pessoa *v, int n, int crescente){
    int i, j, min_idx;
    for(i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            comp++;
            if (crescente ? comparaPessoa(&v[j], &v[min_idx]) : !comparaPessoa(&v[j], &v[min_idx]))
                min_idx = j;
        }
        trocaPessoa(&v[min_idx], &v[i]);
        mov++;
    }
}

void InsertionSortPessoa(Pessoa *v, int n, int crescente){
    int i, j;
    Pessoa key;

    for(i = 1; i < n; i++){
        key = v[i];
        j = i - 1;
        while(j >= 0 && (crescente ? comparaPessoa(&v[j], &key) : !comparaPessoa(&v[j], &key))){
            comp++;
            v[j + 1] = v[j];
            j = j - 1;
            mov++;
        }
        v[j + 1] = key;
        mov++;
    }
}

int main(){
    clock_t t;
    Pessoa *v;
    int n, escolha;

    printf("-> Digite o tamanho do vetor: ");
    scanf("%d", &n);
    v = (Pessoa*) malloc (n*sizeof(Pessoa));

    preencheVetorPessoa(v, n);

    do{
        printf("-=x Menu de Ordenação x=-\n");
        printf("1 - InsertionSort (Crescente)\n");
        printf("2 - InsertionSort (Decrescente)\n");
        printf("3 - SelectionSort (Crescente)\n");
        printf("4 - SelectionSort (Decrescente)\n");
        printf("5 - Sair\n\n");
        printf("-> Qual a sua escolha: ");
        scanf("%d", &escolha);

        comp = 0; mov = 0;
        if(escolha == 1){
            t = clock();
            InsertionSortPessoa(v, n, 0);
            t = clock() - t;
        }else if(escolha == 2){
            t = clock();
            InsertionSortPessoa(v, n, 1);
            t = clock() - t;
        }else if(escolha == 3){
            t = clock();
            SelectionSortPessoa(v, n, 1);
            t = clock() - t;
        }else if(escolha == 4){
            t = clock();
            SelectionSortPessoa(v, n, 0);
            t = clock() - t;
        }else{
            printf("-> Escolha Inválida!");
            break;
        }

        printf("-> Informacoes:\n");
        printf("- Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
        printf("- Comparacoes: %d\n", comp);
        printf("- Movimentacoes: %d\n", mov);
        printf("- Memoria (bytes): %ld\n", n*sizeof(int));
        printf("- Valores do vetor: ");
        imprimeVetorPessoa(v, n);
    }while(escolha!=5);

    free(v);
    return 0;
}
