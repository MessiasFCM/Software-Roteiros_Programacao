#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Dados do Aluno
typedef struct {
    char nome[50];
    int matricula;
    float notas[3];
} Aluno;

// Dados Gerais
int comp;

void troca(Aluno *a, Aluno *b){
    Aluno aux = *a;
    *a = *b;
    *b = aux;
}

Aluno* copiaVetor(Aluno *v, int n){
    int i;
    Aluno *v2;
    v2 = (Aluno*)malloc(n * sizeof(Aluno));
    for(i = 0; i < n; i++)
        v2[i] = v[i];
    return v2;
}

void imprimeVetor(Aluno *v, int n){
    int i, prim = 1;
    printf("\n");
    for(i = 0; i < n; i++){
        if(prim) {
            printf("-> Nome: %s - Matricula: %d - Notas: [%f, %f, %f]", v[i].nome, v[i].matricula, v[i].notas[0], v[i].notas[1], v[i].notas[2]);
            prim = 0;
        }else
            printf("\n-> Nome: %s - Matricula: %d - Notas: [%f, %f, %f]", v[i].nome, v[i].matricula, v[i].notas[0], v[i].notas[1], v[i].notas[2]);
    }
    printf("\n\n");
}

void preencheAleatorio(Aluno *v, int n){
    int i, j;
    for(i = 0; i < n; i++){
        sprintf(v[i].nome, "aluno%d", i + 1);
        v[i].matricula = 20230000 + i;
        for (j = 0; j < 3; j++)
            v[i].notas[j] = 0 + (rand() % 101) / 10.0; 
    }
}

// Pesquisa Binária
int particao(Aluno *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini + fim) / 2].matricula;
    while(1){
        while(v[i].matricula < pivo){
            i++;
        }
        while(v[j].matricula > pivo){
            j--;
        } 

        if(i < j){
            troca(&v[i], &v[j]); 
            i++;
            j--;
        }else
            return j; 
    }
}

void QuickSort(Aluno *v, int ini, int fim){
    if(ini < fim){
        int q = particao(v, ini, fim);
        QuickSort(v, ini, q);
        QuickSort(v, q + 1, fim);
    }
}

int rec_buscaBinariaNome(Aluno *v, int ini, int fim, char *nome){
    if(ini > fim)
        return -1;
    int meio = (ini + fim) / 2;
    comp++;
    if(strcmp(v[meio].nome, nome) == 0)
        return meio;
    else if(strcmp(nome, v[meio].nome) < 0)
        return rec_buscaBinariaNome(v, ini, meio - 1, nome);
    else
        return rec_buscaBinariaNome(v, meio + 1, fim, nome);
}

int rec_buscaBinariaMatricula(Aluno *v, int ini, int fim, int matricula){
    if(ini > fim)
        return -1;
    int meio = (ini + fim) / 2;
    comp++;
    if(v[meio].matricula == matricula)
        return meio;
    else if(matricula < v[meio].matricula)
        return rec_buscaBinariaMatricula(v, ini, meio - 1, matricula);
    else
        return rec_buscaBinariaMatricula(v, meio + 1, fim, matricula);
}

int main(){
    srand(time(NULL));
    comp = 0;
    clock_t t;

    Aluno *v;
    int n;
    char nome[50];
    int matricula;

    printf("-> Digite o tamanho do vetor: ");
    scanf("%d", &n);
    v = (Aluno *)malloc(n * sizeof(Aluno));

    preencheAleatorio(v, n);
    QuickSort(v, 0, n - 1);

    printf("\n-> Vetor Ordenado:");
    imprimeVetor(v, n);

    printf("\n-> Digite um nome para busca: ");
    scanf("%s", nome);

    int indNome;

    comp = 0;
    t = clock();
    indNome = rec_buscaBinariaNome(v, 0, n - 1, nome);
    t = clock() - t;
    printf("\n-> Informacoes Busca Binaria por Nome:\n");
    printf("- Tempo Execucao:  %f seconds.\n", ((float)t) / CLOCKS_PER_SEC);
    printf("- Comparacoes: %d\n", comp);

    if(indNome != -1)
        printf("\n-> O aluno %s foi encontrado na pos %d.\n", nome, indNome);
    else
        printf("\n-> O aluno %s NAO foi encontrado!\n", nome);

    printf("\n-> Digite uma matricula para busca: ");
    scanf("%d", &matricula);

    int indMatricula;

    comp = 0;
    t = clock();
    indMatricula = rec_buscaBinariaMatricula(v, 0, n - 1, matricula);
    t = clock() - t;
    printf("\n-> Informacoes Busca Binaria por Matricula:\n");
    printf("- Tempo Execucao:  %f seconds.\n", ((float)t) / CLOCKS_PER_SEC);
    printf("- Comparacoes: %d\n", comp);

    if(indMatricula != -1)
        printf("\n-> O aluno com matricula %d foi encontrado na pos %d.\n", matricula, indMatricula);
    else
        printf("\n-> O aluno com matricula %d NAO foi encontrado!\n", matricula);

    free(v);
    return 0;
}
