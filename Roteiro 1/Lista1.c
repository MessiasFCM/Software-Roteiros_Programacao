#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 10

typedef struct Alunos{
    char nome [30];
    int matricula;
    float nota;
}Aluno;


int main(){
    srand(time(NULL));
    struct Alunos *aluno = (Aluno*)malloc(TAM*sizeof(Aluno));
    for(int i = 0; i<10; i++){
        strncpy(aluno[i].nome, "Wesley", 30);
        aluno[i].matricula = i;
        aluno[i].nota = rand()%11;
    }


    for(int i = 0; i<10; i++){
        if(){
            printf("Nome : %s - Matrícula : %d - Nota : %.2f\n", aluno[i].nome, aluno[i].matricula, aluno[i].nota);
        }
    }
    return 0;
}
