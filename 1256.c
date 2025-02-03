#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int valor;
    struct celula* prox;
}cel;

void pushlista(cel**, int);
void imprimelista(cel*);
void liberamemoria(cel**,int);

int main(){
    int N,M,C,X;
    scanf("%d",&N);
    for (int i=0;i<N;i++){
        scanf("%d %d",&M,&C);
        cel** vetorlista=(cel**)calloc(M, sizeof(cel*));
        for (int j=0;j<C;j++){
            scanf("%d",&X);
            pushlista(&vetorlista[X%M],X);
        }
        for (int j=0;j<M;j++){
            printf("%d",j);
            imprimelista(vetorlista[j]);
        }
        if (i<N-1){
            printf("\n");
        }
        liberamemoria(vetorlista, M);
    }
    return 0;
}

void pushlista(cel** cabeca, int x){
    cel* novo=(cel*)malloc(sizeof(cel));
    novo->valor=x;
    novo->prox=NULL;
    if (*cabeca==NULL){
        *cabeca=novo;
    } 
    else{
        cel* atual=*cabeca;
        while (atual->prox!=NULL){
            atual=atual->prox;
        }
        atual->prox=novo;
    }
}

void imprimelista(cel* cabeca){
    cel* atual=cabeca;
    while (atual!=NULL){
        printf(" -> %d",atual->valor);
        atual=atual->prox;
    }
    printf(" -> \\");
    printf("\n");
}

void liberamemoria(cel** vetorlista, int M){
    for (int i=0;i<M;i++){
        cel* atual=vetorlista[i];
        while (atual!=NULL){
            cel* temp=atual;
            atual=atual->prox;
            free(temp);
        }
    }
    free(vetorlista);
}
