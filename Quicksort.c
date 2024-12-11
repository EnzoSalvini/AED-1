#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 400000;

void troca(int*, int*);
int separa(int[], int, int);
void quicksort(int[], int, int);

int main(){
    clock_t t;
    int vetor[TAM];
    srand((unsigned)time(NULL));
    for(int a = 0; a < TAM; a++){
        vetor[a] = rand() % TAM;
    }
    t = clock();
    quicksort(vetor,0,TAM);
    t = clock() - t;
    printf("Tempo de execucao: %lf s\n", ((double)t)/((CLOCKS_PER_SEC)));
}

void troca(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int separa(int vet[], int p, int r){
    int pivot = vet[r];
    int i=(p-1); 
    for (int j=p;j<r;j++) {
        if (vet[j]<=pivot) {
            i++;
            troca(&vet[i], &vet[j]);
        }
    }
    troca(&vet[i+1], &vet[r]);
    return (i+1);
}

void quicksort(int vet[], int p, int r){
    if (p<r) {
        int pivot = separa(vet, p, r);
        quicksort(vet, p, pivot - 1);
        quicksort(vet, pivot + 1, r);
    }
}
