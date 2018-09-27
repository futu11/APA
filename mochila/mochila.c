#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Tamanho(FILE *fp){
    char elemento[6];
    int tam;
    fscanf(fp, "%s", elemento);
    tam = atoi(elemento);
    return tam;
}

int Capacidade(FILE *fp){
    char elemento[6];
    int cap;
    fscanf(fp, "%s", elemento);
    cap = atoi(elemento);
    return cap;
}


int LeArquivo(int tam, FILE *fp, int count, int peso[], int valor[]){
    char elemento[6];

    while(count != tam + 1){
        fscanf(fp, "%s", elemento);
        peso[count - 1] = atoi(elemento);
        fscanf(fp, "%s", elemento);
        valor[count - 1] = atoi(elemento);
        printf("%d, %d\n", peso[count - 1], valor[count - 1]);
        count++;
    }

    return 0;
}


int max(int a, int b) { return (a > b)? a : b; }

int mochila(int cap, int peso[], int valor[], int tam)
{
   int i, w;
   long int K[tam+1][cap+1];


   for (i = 0; i <= tam; i++)
   {
       for (w = 0; w <= cap; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (peso[i-1] <= w)
                 K[i][w] = max(valor[i-1] + K[i-1][w-peso[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[tam][cap];
}

int main()
{
    FILE *fp;
    fp = fopen("mochila01.txt", "r");
    int tam, cap, count;
    count = 0;
    tam = Tamanho(fp);
    cap = Capacidade(fp);
    count++;
    printf("%d, %d\n", tam, cap);
    int peso[tam], valor[tam];
    fgetc(fp);
    LeArquivo(tam, fp, count, peso, valor);
    printf("%d", mochila(cap, peso, valor, tam));
    return 0;
}
