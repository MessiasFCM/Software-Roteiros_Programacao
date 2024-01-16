#ifndef MFAIXA_H
#define MFAIXA_H

typedef struct{
    int *diagonal;
    int *superior;
    int *inferior;
    int tam;
}MFaixa;

void zeraMatriz(MFaixa* mf);

MFaixa* criaMatriz(int t);

void destroiMatriz(MFaixa* mf);

int preencheAleatorio(MFaixa* mf, int ini, int fim);

int insereElem(MFaixa* mf, int elem, int i, int j);

int consultaElem(MFaixa* mf, int i, int j);

void imprimeFaixaVetores(MFaixa* mf);

void imprimeFaixa(MFaixa* mf);

#endif