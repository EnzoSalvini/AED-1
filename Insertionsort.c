//utilizei parte do programa do calculo de tempo do bubblesort dado em aula
//juntamente com o insertionsort do Feofiloff

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 400000; //tamanho do vetor a ser gerado

void insertion(int, int[]);

int main(){
    clock_t t;
    int vetor[TAM];
    srand((unsigned)time(NULL));
    for(int a = 0; a < TAM; a++){
        vetor[a] = rand() % TAM;
    }
    t = clock();
    insertion(TAM,vetor);
    t = clock() - t;
    printf("Tempo de execucao: %lf s\n", ((double)t)/((CLOCKS_PER_SEC)));
}

void insertion(int n, int v[]){
    int i, j, x;
    for (j=1; j<n; j++) {
        x=v[j];
        for (i=(j-1);i>=0 && v[i]>x;i--){
            v[i+1]=v[i];
        }
        v[i+1]=x;
    }
}
