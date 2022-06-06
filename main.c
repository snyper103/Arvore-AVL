#include "AVL.h"

int main()
{
    register int i;
    ArvAVL* raiz = CriaArvore();

    for(i = 0; i <= 10; ++i)
        InsereArvore(raiz,i);

    printf("\nH = %i\n", AlturaArvore(raiz));
    printf("\nTotal = %i\n", TotalSubArv(raiz));

    printf("\nconsulta(9) = %hi\n", ConsultaArvore(raiz, 9));
    printf("\nconsulta(11) = %hi\n", ConsultaArvore(raiz, 11));

    printf("\n");
    PreOrdem(raiz);
    printf("\n");
    EmOrdem(raiz);
    printf("\n");
    PosOrdem(raiz);
    printf("\n");

    RemoveArvore(raiz, 4);
    RemoveArvore(raiz, 2);
    RemoveArvore(raiz, 1);

    printf("\n");
    PreOrdem(raiz);
    printf("\n");
    EmOrdem(raiz);
    printf("\n");
    PosOrdem(raiz);
    printf("\n");

    LiberaArvore(raiz);

    return 0;
}
