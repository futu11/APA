#include <stdio.h>
#include <stdlib.h>
#include "Selection_Sort.h"
#include <string.h>

tNo *getNo(int elemento){
    tNo *n;
    n = malloc(sizeof(tNo));
    if(n != NULL){
        n->elemento = elemento;
        n->prox = NULL;
    }
    return n;
}

void IniciaLista(tNo **no){
    *no = NULL;
}

int LeArquivo(int tam, FILE *fp, int count, tNo **no){
    char elemento[6];
    int valor;

    if(tam == 0 ){
        fgets(elemento, 6, fp);
        tam = atoi(elemento);
        printf("%d\n", tam);

    }
    count++;
    if(count == tam + 1){
        return 0;
    }
    if(tam != 0){
        fgets(elemento, 6, fp);
        valor = atoi(elemento);
        printf("%d\n", valor);
        InsereElemento(no, valor);
    }

    LeArquivo(tam, fp, count, no);
    return 0;
}

void InsereElemento(tNo **no, int valor){
    tNo *novo = getNo(valor);
    if(*no == NULL){
        *no = novo;
    }else{
        novo->prox = *no;
        *no = novo;
    }
}

int SelectionSort(tNo **no){
    tNo *menor, *perco;
    menor = *no;
    perco = *no;
    while(perco != NULL){
        if(perco->elemento < menor->elemento)
            menor = perco;
        perco = perco->prox;
    }
    perco = *no;
    if(perco == menor)
        return 0;
    while(perco->prox != menor){
        perco = perco->prox;
    }
    perco->prox = menor->prox;
    menor->prox = *no;
    *no = menor;
    return 0;
}

int main(){
    int tam = 0;
    int count = 0;
    tNo *no;
    IniciaLista(&no);
    puts("Digite o nome do arquivo:");
    char filename[100];
    scanf("%s", filename);
    FILE *fp;
    fp = fopen(filename, "r");
        if(fp == NULL){
        puts("arquivo nao encontrado");
        exit(1);
    }
    LeArquivo(tam, fp, count, &no);
    fclose(fp);
    tNo *ordenado;
    IniciaLista(&ordenado);
    ordenado = no;
    count = 0;
    while(ordenado != NULL){
        SelectionSort(&ordenado);
        if(count == 0)
            no = ordenado;
        printf("\n%d", ordenado->elemento);
        ordenado = ordenado->prox;
        count++;
    }
    printf("\n%d", count);
}
