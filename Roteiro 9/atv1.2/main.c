#include <stdio.h>
#include "AVL.h"

int main(){
    AVL* A;
    char nome[100];
    int escolha, resultado, anoDeContratacao, nivel;
    double salario;

    printf("-=x Menu x=-\n");
    printf("1 - Criar AVL\n");
    printf("2 - Inserir um Funcionário pelo salário\n");
    printf("3 - Buscar um Funcionário pelo salario e imprimir suas informações\n");
    printf("4 - Remover um Funcionário pelo nome\n");
    printf("5 - Imprimir a AVL em ordem\n");
    printf("6 - Imprimir as informações do Funcionário com o maior salário\n");
    printf("--> Qual a complexidade dessa operação?\n");
    printf("7 - Imprimir as informações do Funcionário com o menor salário\n");
    printf("--> Qual a complexidade dessa operação?\n");
    printf("8 - Destruir a AVL\n");
    printf("9 - Sair\n");

    do{
        printf("\nInsira sua escolha: ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1: 
                A = criaAVL();
                printf("-> AVL criada com sucesso!");
                break;
            case 2: 
                printf("Insira o nome do funcionário: ");
                scanf("%s", nome);
                printf("Insira o salário do funcionário: ");
                scanf("%lf", &salario);
                printf("Insira o ano de contratação do funcionário: ");
                scanf("%d", &anoDeContratacao);
                resultado = insereFuncionario(A, nome, salario, anoDeContratacao);
                if(resultado){
                    printf("-> Elemento adicionado com sucesso!");
                }else{
                    printf("-> Elemento não foi adicionado!");
                }
                break;
            case 3: 
                printf("- Insira o salário a ser buscado: ");
                scanf("%lf", &salario);
                resultado = pesquisaFuncionario(A, salario);
                if(resultado){
                    printf("-> Elemento encontrado!");
                }else{
                    printf("-> Elemento não encontrado!");
                }
                break;
            case 4: 
                printf("- Insira o salário do funcionário a ser removido: ");
                scanf("%lf", &salario);
                resultado = removeElem(A, salario);
                if(resultado){
                    printf("-> Elemento removido com sucesso!!");
                }else{
                    printf("-> Elemento não foi removido!");
                }
                break;
            case 5: 
                printf("- Insira o nível: ");
                scanf("%d", &nivel);
                em_ordem(*A, nivel);
                break;
            case 6: 
                Funcionario maiorSalario = encontrarMaiorSalario(A);
                printf("- Funcionário com o maior salário:\n");
                printf("-> Nome: %s\n", maiorSalario.nome);
                printf("-> Salário: %.2lf reais\n", maiorSalario.salario);
                printf("-> Ano de Contratação: %d\n", maiorSalario.anoDeContratacao);
                break;
            case 7: 
                Funcionario menorSalario = encontrarMenorSalario(A);
                printf("- Funcionário com o menor salário:\n");
                printf("-> Nome: %s\n", menorSalario.nome);
                printf("-> Salário: %.2lf reais\n", menorSalario.salario);
                printf("-> Ano de Contratação: %d\n", menorSalario.anoDeContratacao);
                break;
            case 8: 
                destroiAVL(A);
                printf("-> AVL destruida com sucesso!");
                break;
            default: 
                break;
        }
    }while(escolha < 9);

    return 0;
}