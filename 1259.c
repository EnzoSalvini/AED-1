#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int valor;
    struct celula *prox;
}cel;

void imprimelista(cel*);
void pushpar(cel**,int);
void pushimpar(cel**,int);
void juntalistas(cel**,cel*);

int main(){
    int n,x;
    cel* cabecapar;
    cel* cabecaimpar;
    cabecapar=NULL,cabecaimpar=NULL;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&x);
        if(x%2==0){
            pushpar(&cabecapar, x);
        }
        else{
            pushimpar(&cabecaimpar, x);
        }
    }
    juntalistas(&cabecapar,cabecaimpar);
    imprimelista(cabecapar);
}

void imprimelista(cel* cabeca) {
    cel* atual=cabeca;
    while(atual!=NULL) {
        printf("%d\n",atual->valor);
        atual=atual->prox;
    }
}

void pushpar(cel** cabeca, int x){
    cel* novo=(cel*)malloc(sizeof(cel));
    novo->valor=x;
    novo->prox=NULL;
    if (*cabeca==NULL || (*cabeca)->valor>=x) {
        novo->prox=*cabeca;
        *cabeca=novo;
        return;
    }
    cel* atual=*cabeca;
    while(atual->prox!=NULL && atual->prox->valor<x) {
        atual=atual->prox;
    }
    novo->prox=atual->prox;
    atual->prox=novo;
}

void pushimpar(cel** cabeca, int x){
    cel* novo=(cel*)malloc(sizeof(cel));
    novo->valor=x;
    novo->prox=NULL;
    if (*cabeca==NULL || (*cabeca)->valor<=x) {
        novo->prox=*cabeca;
        *cabeca=novo;
        return;
    }
    cel* atual=*cabeca;
    while(atual->prox!=NULL && atual->prox->valor>x) {
        atual=atual->prox;
    }
    novo->prox=atual->prox;
    atual->prox=novo;
}

void juntalistas(cel** cabeca1, cel* cabeca2) {
    if (*cabeca1==NULL) {
        *cabeca1=cabeca2;
        return;
    }
    cel* aux=*cabeca1;
    while(aux->prox!=NULL) {
        aux=aux->prox;
    }
    aux->prox=cabeca2;
}
