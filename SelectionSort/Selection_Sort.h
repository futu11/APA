#ifndef SELECTION_SORT_H_INCLUDED
#define SELECTION_SORT_H_INCLUDED

typedef struct no{
    int elemento;
    struct no *prox;
}tNo;

extern tNo *getNo(int elemento);
extern void IniciaLista(tNo **no);
extern int SelectionSort(tNo **no);
extern void InsereElemento(tNo **no, int valor);
extern int LeArquivo(int tam, FILE *fp, int count, tNo **no);

#endif // SELECTION_SORT_H_INCLUDED
