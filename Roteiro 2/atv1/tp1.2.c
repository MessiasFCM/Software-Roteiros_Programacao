#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Produto{
    char nome[30];
    double preco;
    int quantidade;
}Produto;

typedef struct CatalogoProduto{
    Produto produtos[100];
    int numeroDeProdutos;
}CatalogoProduto;

void criarCatalogo(CatalogoProduto *c){
    c->numeroDeProdutos = 0;
    printf("Criado com sucesso!\n");
}

void adicionarProduto(CatalogoProduto *c, char *nome, double preco, int quantidade){
    if (c->numeroDeProdutos < 100) {
        strcpy(c->produtos[c->numeroDeProdutos].nome, nome);
        c->produtos[c->numeroDeProdutos].preco = preco;
        c->produtos[c->numeroDeProdutos].quantidade = quantidade;
        c->numeroDeProdutos++;
    }else{
        printf("Máximo de produtos alcançado\n");
    }
}

int verificarEstoque(CatalogoProduto *c, char *nome) {
    for (int i = 0; i < c->numeroDeProdutos; i++) {
        if (strcmp(c->produtos[i].nome, nome) == 0) {
            return c->produtos[i].quantidade;
        }
    }
    return 0;
}

void imprimirCatalogo(CatalogoProduto *c) {
    for (int i = 0; i < c->numeroDeProdutos; i++) {
        printf("Produto %d\n", i + 1);
        printf("Nome : %s\n", c->produtos[i].nome);
        printf("Preço : %.2lf reais\n", c->produtos[i].preco);
        printf("Quantidade : %d\n", c->produtos[i].quantidade);
    }
}

int main(){
    int escolha, quantidade;
    char nome[30];
    double preco;
    CatalogoProduto *c = (CatalogoProduto *)malloc(sizeof(CatalogoProduto));
    while (true){
        printf("1 - Criar Catálogo\n");
        printf("2 - Adicionar Produto\n");
        printf("3 - Verificar Estoque\n");
        printf("4 - Imprimir Catálogo\n");
        printf("0 - Sair\n");
        printf("Escolha : ");
        scanf("%d", &escolha);

        if (escolha == 1){
            criarCatalogo(c);
        }else if (escolha == 2){
            printf("Nome : ");
            scanf("%s", nome);
            printf("Preço : ");
            scanf("%lf", &preco);
            printf("Quantidade : ");
            scanf("%d", &quantidade);
            adicionarProduto(c, nome, preco, quantidade);
        }else if (escolha == 3){
            printf("Nome : ");
            scanf("%s", nome);
            int quant = verificarEstoque(c, nome);
            printf("Quantidade em estoque : %d\n", quant);
        }else if (escolha == 4){
            imprimirCatalogo(c);
        }else if (escolha == 0){
            break;
        }else{
            printf("Escolha inválida\n");
        }
    }
    free(c);
    return 0;
}