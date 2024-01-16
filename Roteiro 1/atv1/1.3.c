#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 10

typedef struct Alunos{
    char nome[30];
    int matricula;
    float nota;
} Aluno;

int main(){
    srand(time(NULL));
    struct Alunos *aluno = (Aluno*)malloc(TAM * sizeof(Aluno));
    for (int i = 0; i < 10; i++){
        scanf("%s", aluno[i].nome);
        aluno[i].matricula = i; 
        aluno[i].nota = rand() % 11;
    }

    int maior = 0, menor = 0;
    float verificarMaior = aluno[0].nota;
    float verificarMenor = aluno[0].nota;
    for (int i = 0; i < 10; i++){
        if(verificarMaior >= aluno[i].nota){
            verificarMaior = aluno[i].nota;
            menor = i;
        }
    }
    for (int i = 0; i < 10; i++){
        if(verificarMenor <= aluno[i].nota){
            verificarMenor = aluno[i].nota;
            maior = i;
        }
    }
    printf("Nome : %s - Matrícula : %d - Nota : %.2f\n", aluno[maior].nome, aluno[maior].matricula, aluno[maior].nota);
    printf("Nome : %s - Matrícula : %d - Nota : %.2f\n", aluno[menor].nome, aluno[menor].matricula, aluno[menor].nota);

    free(aluno);

    return 0;
}
