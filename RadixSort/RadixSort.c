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

int findLargestNum(int * array, int size){

  int i;
  int largestNum = -1;

  for(i = 0; i < size; i++){
    if(array[i] > largestNum)
      largestNum = array[i];
  }

  return largestNum;
}

void radixSort(int * array, int size){

  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findLargestNum(array, size);

  while (largestNum / significantDigit > 0){


    int bucket[10] = { 0 };

    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;

    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];

    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];


    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];

    significantDigit *= 10;
  }
}

int main(){
    int i = 0;
    int size;
    FILE *fp;
    fp = fopen("couting.txt", "r");
    if(fp == NULL){
        puts("Arquivo nao encontrado");
        exit(1);
    }
    size = NumeroElemento(fp);
    int list[size];
    i++;
    LeArquivo(size, fp, i, list);
    fclose(fp);
    for(i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
    radixSort(&list[0], size);
    printf("\n");
    for(i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
    return 0;
}
