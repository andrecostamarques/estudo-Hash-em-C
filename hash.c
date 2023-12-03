#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 9

int c1(int x){

    return x%N;
}

int c2(int x){
    return (x%(N-1))+1;
}

void hash(int* array, int x) {
    int index = c1(x);

    if (array[index] == -1) {
        array[index] = x;
    } else {
        int i = 1;
        while (i < N) {
            index = (c1(x) + c2(x) * i) % N;

            if (array[index] == -1) {
                array[index] = x;
                break;
            }

            i++;
        }
    }
}

void printHash(int* array) {
    printf("indice | valor\n");
    for (int i = 0; i < N; i++) {
        printf("%d | %d\n",i,array[i]);
    }
}

//retorna o index que ele está, retorna -1 se não tiver
int buscaHash(int* array, int x){
    int index = c1(x);
    int retorno = -1;
    

    if (array[index] == x) {
        retorno = index;
    } else {
        int i = 1;
        while (i < N) {
            index = (c1(x) + c2(x) * i) % N;

            if (array[index] == -1) {
                retorno = index;
                break;
            }

            i++;
        }
    }

    return retorno;
}

int main(void){

    int* array;
    array = (int*)malloc(N * sizeof(int));
    memset(array, -1, N * sizeof(int));

    hash(array, 5);
    hash(array, 28);
    hash(array, 19);
    hash(array, 15);
    hash(array, 20);
    hash(array, 33);
    hash(array, 12);
    hash(array, 7);
    hash(array, 10);

    printHash(array);

    printf("\n12 = %d",buscaHash(array, 12));
    printf("\n2 = %d",buscaHash(array, 2));

    free(array);

    return 0;
}