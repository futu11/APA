#include <stdio.h>
#include <stdlib.h>
#include "Insertion_Sort.h"
#include <string.h>


int NumeroElemento(FILE *fp){
    char elemento[6];
    int tam;
    fgets(elemento, 6, fp);
    tam = atoi(elemento);
    return tam;
}

int LeArquivo(int tam, FILE *fp, int count, int valor[]){
    char elemento[6];

    while(count != tam + 1){
        fgets(elemento, 6, fp);
        valor[count - 1] = atoi(elemento);
        printf("%d\n", valor[count - 1]);
        count++;
    }

    return 0;
}

void InsertionSort(int valor[], int tam){
    int i, j, comp;
    i = j = 1;
    while(i < tam){
        comp = valor[i];
        j = i - 1;
        while(j>=0 && valor[j] > comp){
            valor[j + 1] = valor[j];
            j--;
        }
        valor[j + 1] = comp;
        i++;
    }
}

int main(){
    int tam ;
    int count = 0;
    char filename[100];
    FILE *fp;
    puts("Digite o nome do arquivo:");
    scanf("&s", filename);
    fp = fopen(filename, "r");
    if(fp == NULL){
        puts("Arquivo nao encontrado");
        exit(1);
    }
    tam = NumeroElemento(fp);
    count++;
    int valor[tam];
    LeArquivo(tam, fp, count, valor);
    fclose(fp);
    InsertionSort(valor, tam);

}
