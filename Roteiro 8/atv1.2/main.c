#include <stdio.h>
#include "ABP.h"

int main(){
    ABP* A;
    char nome[100];
    int escolha, matricula, resultado;
    double nota;

    printf("-=x Menu x=-\n");
    printf("1 - Criar ABP\n");
    printf("2 - Inserir um Aluno\n");
    printf("3 - Buscar um Aluno pelo nome e imprimir suas informações\n");
    printf("4 - Remover um Aluno pelo nome\n");
    printf("5 - Imprimir a ABP em ordem\n");
    printf("6 - Imprimir as informações do aluno com a maior nota\n");
    printf("7 - Imprimir as informações do aluno com a menor nota\n");
    printf("8 - Destruir a ABP\n");
    printf("9 - Sair");
    
    do{
        printf("\n\nInsira sua escolha: ");
        scanf("%d", &escolha);
        if(escolha == 1){
            A = criarABP();
            printf("-> ABP criada com sucesso!");
        }else if(escolha == 2){
           printf("Insira o nome do aluno: ");
           scanf("%s", nome);
           printf("Insira a matrícula do aluno: ");
           scanf("%d", &matricula);
           printf("Insira a nota do aluno: ");
           scanf("%lf", &nota);
           resultado = inserirAluno(A, nome, matricula, nota);
           if(resultado){
                printf("-> Aluno adicionado com sucesso!");
            }else{
                printf("-> Aluno não foi adicionado!");
            }
        }else if(escolha == 3){
            printf("Insira o nome do aluno a ser buscado: ");
            scanf("%s", nome);
            resultado = buscarAluno(A, nome);
            if(resultado){
                printf("-> Aluno encontrado!");
            }else{
                printf("-> Aluno não encontrado!");
            }
        }else if(escolha == 4){
            printf("Insira o nome do aluno a ser removido: ");
            scanf("%s", nome);
            resultado = removerAluno(A, nome);
            if(resultado){
                printf("-> Aluno removido com sucesso!");
            }else{
                printf("-> Aluno não foi removido!");
            }
        }else if(escolha == 5){
            printf("- Árvore em Ordem:\n");
            imprime(A);
        }else if(escolha == 6){
            Aluno maiorNota = encontrarMaiorNota(A);
            printf("- Aluno com a maior nota:\n");
            printf("-> Nome: %s\n", maiorNota.nome);
            printf("-> Matrícula: %d\n", maiorNota.matricula);
            printf("-> Nota: %.2lf\n", maiorNota.nota);
        }else if(escolha == 7){
            Aluno menorNota = encontrarMenorNota(A);
            printf("- Aluno com a menor nota:\n");
            printf("-> Nome: %s\n", menorNota.nome);
            printf("-> Matrícula: %d\n", menorNota.matricula);
            printf("-> Nota: %.2lf\n", menorNota.nota);
        }else if(escolha == 8){
            destroirABP(A);
            printf("-> ABP destruida com sucesso!");
        }
    }while (escolha != 9);

    return 0;
}