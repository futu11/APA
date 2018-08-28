#include <stdio.h>
#include <stdlib.h>
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
void CountSort(int ar[]){

    char organizado[255];
    int count[255], i;
    for (i = 0; i <= 254; i++){
        count[i] = 0;
    }
    for(i = 0; ar[i] ; i++){
        ++count[ar[i]];
    }
    for(i = 1; i<= 254; i++){
        count[i] += count[i - 1];
    }
    for(i = 0; ar[i]; i++){
        organizado[count[ar[i]] - 1] = ar[i];
        --count[ar[i]];
    }
    for(i = 0; ar[i]; i++){
        ar[i] = organizado[i];
    }

}

int main(){
    int i, tam, count;
    count = 0;
    FILE *fp;
    fp = fopen("couting.txt", "r");
    if(fp == NULL){
        puts("Arquivo nao encontrado");
        exit(1);
    }
    tam = NumeroElemento(fp);
    count ++;
    int ar[tam];
    LeArquivo(tam, fp, count, ar);
    fclose(fp);
    CountSort(ar);
    printf("Organizado:\n");
    for(i = 0; i < 6; i++){
        printf("%d", ar[i]);
    }
    return 0;
}
