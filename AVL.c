#include "AVL.h"

ArvAVL* CriaArvore()
{
    ArvAVL* raiz = (ArvAVL*)malloc(sizeof(ArvAVL));

    if(raiz != NULL)
        (*raiz) = NULL;

    return raiz;
}

ArvAVL LiberaNO(ArvAVL no)
{
    if(!(ArvoreVazia(&no)))
    {
        LiberaNO(no->esq);
        LiberaNO(no->dir);
        free(no);
    }

    return NULL;
}
void LiberaArvore(ArvAVL* raiz)
{
    if(ArvoreVazia(raiz))
        return;

    (*raiz) = LiberaNO(*raiz);
    free(raiz);
}
int DefineMaior(int x, int y)
{
    return (x > y) ? (x) : (y);
}

int AlturaSubArv(ArvAVL no)
{
    if(ArvoreVazia(&no))
        return -1;

    else
        return no->altura;
}
int FatorBalanceamento(ArvAVL no)
{
    return labs(AlturaSubArv(no->esq) - AlturaSubArv(no->dir));
}

void RotacaoLL(ArvAVL* raiz)
{
    ArvAVL aux = (*raiz)->esq;

    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);

    (*raiz)->altura = DefineMaior(AlturaSubArv((*raiz)->esq), AlturaSubArv((*raiz)->dir)) + 1;
    aux->altura = DefineMaior(AlturaSubArv(aux->esq), (*raiz)->altura) + 1;

    (*raiz) = aux;
}
void RotacaoRR(ArvAVL* raiz)
{
    ArvAVL aux = (*raiz)->dir;

    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);

    (*raiz)->altura = DefineMaior(AlturaSubArv((*raiz)->esq), AlturaSubArv((*raiz)->dir)) + 1;
    aux->altura = DefineMaior(AlturaSubArv(aux->dir), (*raiz)->altura) + 1;

    (*raiz) = aux;
}

void RotacaoLR(ArvAVL* raiz)
{
    RotacaoRR(&(*raiz)->esq);
    RotacaoLL(raiz);
}
void RotacaoRL(ArvAVL* raiz)
{
    RotacaoLL(&(*raiz)->dir);
    RotacaoRR(raiz);
}

short int InsereArvore(ArvAVL* raiz, int info)
{
    short int boleano = 0;

    if(ArvoreVazia(raiz))
    {
        ArvAVL aux = (ArvAVL)malloc(sizeof(ArvAVL));

        if(aux == NULL)
            return 0;

        aux->dado = info;
        aux->esq = NULL;
        aux->dir = NULL;
        aux->altura = 0;
        (*raiz) = aux;

        return 1;
    }

    else
    {
        if((*raiz)->dado < info)
        {
            if((boleano = InsereArvore(&((*raiz)->dir), info)) == 1)
            {
                if(FatorBalanceamento(*raiz) >= 2)
                {
                    if((*raiz)->dir->dado < info)
                        RotacaoRR(raiz);

                    else
                        RotacaoRL(raiz);
                }
            }
        }

        else
            if((*raiz)->dado > info)
            {
                if((boleano = InsereArvore(&((*raiz)->esq), info)) == 1)
                {
                    if(FatorBalanceamento(*raiz) >= 2)
                    {
                        if((*raiz)->esq->dado > info)
                            RotacaoLL(raiz);

                        else
                            RotacaoLR(raiz);
                    }
                }
            }
    }

    (*raiz)->altura = DefineMaior(AlturaSubArv((*raiz)->esq), AlturaSubArv((*raiz)->dir)) + 1;

    return boleano;
}

ArvAVL ProcuraMenor(ArvAVL no)
{
    for(; no->dir != NULL; no = no->dir);

    return no;
}
short int RemoveArvore(ArvAVL* raiz, int info)
{
    short int boleano = 0;
    ArvAVL aux;

    if(ArvoreVazia(raiz))
        return 0;

    else
    {
        if((*raiz)->dado < info)
        {
            if((boleano = RemoveArvore(&((*raiz)->dir), info)) == 1)
                if(FatorBalanceamento(*raiz) >= 2)
                {
                    if(AlturaSubArv((*raiz)->esq->dir) <= AlturaSubArv((*raiz)->esq->esq))
                        RotacaoLL(raiz);

                    else
                        RotacaoLR(raiz);
                }
        }

        else
        {
            if((*raiz)->dado > info)
            {
                if((boleano = RemoveArvore(&((*raiz)->esq), info)) == 1)
                    if(FatorBalanceamento(*raiz) >= 2)
                    {
                        if(AlturaSubArv((*raiz)->dir->esq) <= AlturaSubArv((*raiz)->dir->dir))
                            RotacaoRR(raiz);

                        else
                            RotacaoRL(raiz);
                    }
            }

            else
            {
                if(((*raiz)->dir == NULL) || ((*raiz)->esq == NULL))
                {
                    aux = (*raiz);

                    if((*raiz)->dir != NULL)
                        (*raiz) = (*raiz)->dir;

                    else
                        (*raiz) = (*raiz)->esq;

                    free(aux);
                }

                else
                {
                    aux = ProcuraMenor((*raiz)->esq);
                    (*raiz)->dado = aux->dado;
                    aux->dado = info;
                    RemoveArvore(&((*raiz)->esq), info);

                    if(FatorBalanceamento(*raiz) >= 2)
                    {
                        if(AlturaSubArv((*raiz)->dir->esq) <= AlturaSubArv((*raiz)->dir->dir))
                            RotacaoRR(raiz);

                        else
                            RotacaoRL(raiz);
                    }
                }

                return 1;
            }
        }
    }

    return boleano;
}

short int ArvoreVazia(ArvAVL* raiz)
{
    return ((!raiz) || ((*raiz) == NULL));
}
int AlturaArvore(ArvAVL* raiz)
{
    int Hesq, Hdir;

    if(ArvoreVazia(raiz))
        return -1;

    Hesq = AlturaArvore(&((*raiz)->esq));
    Hdir = AlturaArvore(&((*raiz)->dir));

    return (Hesq > Hdir) ? (++Hesq) : (++Hdir);
}
int TotalSubArv(ArvAVL* raiz)
{
    int count = 0;

    if(ArvoreVazia(raiz))
        return 0;

    count += TotalSubArv(&((*raiz)->esq));
    count += TotalSubArv(&((*raiz)->dir));

    return ++count;
}
short int ConsultaArvore(ArvAVL* raiz, int info)
{
    short int boleano = 0;

    if(ArvoreVazia(raiz))
        return 0;

    else
    {
        if((*raiz)->dado < info)
            boleano = ConsultaArvore(&((*raiz)->dir), info);

        else
        {
            if((*raiz)->dado > info)
                boleano = ConsultaArvore(&((*raiz)->esq), info);

            else
                return 1;
        }
    }

    return boleano;
}

void PreOrdem(ArvAVL* raiz)
{
    if(ArvoreVazia(raiz))
        return;

    printf("%i, ", (*raiz)->dado);
    PreOrdem(&((*raiz)->esq));
    PreOrdem(&((*raiz)->dir));
}
void EmOrdem(ArvAVL* raiz)
{
    if(ArvoreVazia(raiz))
        return;

    EmOrdem(&((*raiz)->esq));
    printf("%i, ", (*raiz)->dado);
    EmOrdem(&((*raiz)->dir));
}
void PosOrdem(ArvAVL* raiz)
{
    if(ArvoreVazia(raiz))
        return;

    PosOrdem(&((*raiz)->esq));
    PosOrdem(&((*raiz)->dir));
    printf("%i, ", (*raiz)->dado);
}
