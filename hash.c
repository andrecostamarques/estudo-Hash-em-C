#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 11    //define o tamanho da array e o tamanho da hash table

int c1(int x){      //funcao hash de primeira tentativa

    return x%N;
}

int c2(int x){
    return (x%(N-1))+1; //funcao hash de segunda tentativa
}

void hash(int* array, int x) {  //funcao que utiliza o c1 e c2, e envia o int para a hashtable
    int index = c1(x);  //pega o primeiroo indice

    if (array[index] == -1) {
        array[index] = x;   //testa pra ver se o indice é suficiente e ja define
    } else {    //se nao for suficiente vai ter um while que continua até achar, ou se não tiver mai espaço ele quebra
        int i = 1;
        while (i < N) {
            index = (c1(x) + c2(x) * i) % N;    //faz o seguindo index + a multiplicação do i, ou seja, cada teste o c2 é multiplicado

            if (array[index] == -1) {
                array[index] = x;   //testa e coloca
                break;
            }

            i++;
        }
    }
}

void printHash(int* array) {
    printf("indice | valor\n");
    for (int i = 0; i < N; i++) {   //printa o hash
        printf("%d | %d\n",i,array[i]);
    }
}

//retorna o index que ele está, retorna -1 se não tiver
int buscaHash(int* array, int x){
    int index = c1(x);  //testa o primeiro indice
    int retorno = -1;
    
    if (array[index] == x) {
        retorno = index;    //se foi ja vai retornar ele
    } else {
        int i = 1;
        while (i < N) {
            index = (c1(x) + c2(x) * i) % N;

            if (array[index] == x) {
                retorno = index;    //se nao for, ele vai executar o hash de todos até achar, se nao achar retorna -1
                break;
            }

            i++;
        }
    }

    return retorno; //retorna o indice do retorno
}

int main(void){

    int* array;
    array = (int*)malloc(N * sizeof(int));  //declara o malloc do vetor de N
    memset(array, -1, N * sizeof(int)); //seta todos os valores da array p -1

    hash(array, 5);
    hash(array, 28);
    hash(array, 19);
    hash(array, 15);
    hash(array, 20);
    hash(array, 33);    //puxa os valores de hash
    hash(array, 12);
    hash(array, 7);
    hash(array, 10);

    printHash(array);

    printf("\n15 = %d",buscaHash(array, 15));
    printf("\n2 = %d",buscaHash(array, 2)); //printa o indice das buscas, nesse caso foi -1 pq não tem

    free(array);

    return 0;
}