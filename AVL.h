#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct SubArv
{
    int dado, altura;
    struct SubArv* dir,* esq;
}*ArvAVL;

ArvAVL* CriaArvore();
void LiberaArvore(ArvAVL* raiz);

short int InsereArvore(ArvAVL* raiz, int info);
short int RemoveArvore(ArvAVL* raiz, int info);

short int ArvoreVazia(ArvAVL* raiz);
int AlturaArvore(ArvAVL* raiz);
int TotalSubArv(ArvAVL* raiz);
short int ConsultaArvore(ArvAVL* raiz, int info);

void PreOrdem(ArvAVL* raiz);
void EmOrdem(ArvAVL* raiz);
void PosOrdem(ArvAVL* raiz);

#endif
