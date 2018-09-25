#include <stdio.h>
#include <limits.h>


void heapify(int * arr, int n, int i, int * key){
    int menor = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && key[arr[l]] < key[arr[menor]])
        menor = l;

    if (r < n && key[arr[r]] < key[arr[menor]])
        menor = r;

    if (menor != i)
    {
        int aux = arr[menor];
        arr[menor] = arr[i];
        arr[i] = aux;

        heapify(arr, n, menor, key);
    }
}

void BuildMinHeap(int * heap, int size, int * key){
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(heap, size, i, key);
}

int HeapExtMin(int * heap, int * size, int * key){
    int min = heap[0];

    heap[0] = heap[*(size) -1];
    *size = *size-1;

    heapify(heap, *size, 0, key);
    return min;
}

void HeapDecrease(int * heap, int a, int dec, int size, int * key){

    int i;
    for(i = 0; i < size; i++){
        if(heap[i]==a)
            break;
    }


    if(key[a] < dec){
        ;
    }else{
        key[a] = dec;
        int parent = (i-1)/2;

        while(i > 0 && (key[heap[parent]] > key[heap[i]])){
            int aux = heap[i];
            heap[i] = heap[parent];
            heap[parent] = aux;
            i = parent;
            parent = (i-1)/2;
        }
    }
}

int GetV(char * str){

    FILE *f;
    f = fopen(str, "r");
    int aux;
    fscanf(f, "%d", &aux);

    fclose(f);

    return aux;


}

void FillTable(char * str, int * table){

    FILE *f;
    f = fopen(str, "r");

    int aux;
    int v;
    fscanf(f, "%d", &v);


    int i;
    for(i = 0; i < v; i++){

        int j;
        for(j = i; j < v; j++){

            if(j == i){
                *((table+j*v)+i) = 0;
            }else{

                fscanf(f,"%d", &aux);

                *((table+j*v)+i) = aux;
                *((table+i*v)+j) = aux;
            }
        }
    }
fclose(f);
}

void PrimMST(int * w, int size, int r){

    int i;
    int key[size];
    int father[size];
    int inmst[size];
    for(i = 0; i < size; i++){

        key[i] = INT_MAX;
        father[i] = -1;
        inmst[i] = 0;
    }
    key[r] = 0;
    inmst[r] = 1;

    int qsize = size;
    int q[size];
    //Preenchendo a queue
    for(i = 0; i<size; i++)
        q[i] = i;

    BuildMinHeap(&q[0], size, &key[0]);

    //Enquanto a fila não estiver vazia
    i = 0;
    while(qsize > 0){

        int u = HeapExtMin(&q[0], &qsize, &key[0]);

        inmst[u] = 1;

        int v;
        for(v = 0; v < size; v++){

            if(u == v){
                ;
            }else{
                if((inmst[v]==0) && (  (*((w+u*size)+v))  < (key[v]))){;
                    father[v] = u;
                    HeapDecrease(&q[0], v, (*((w+u*size)+v))  , size, &key[0]);
                }
            }

        }
    }

    int sum = 0;
    printf("Aresta          Custo\n\n");
    for(i = 1; i<size; i++){
        printf("%d ---- %d      %d\n", father[i], i, key[i]);
        sum = sum + key[i];
    }
    printf("\nCusto Total: %d\n\n", sum);
}


int main(){

    int size = GetV("dij20.txt");

    int table[size][size];

    FillTable("dij20.txt", &table[0][0]);

    printf("\n\n");

    PrimMST(&table[0][0], size, 0);

    return 0;
}
