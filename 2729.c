#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char item[21];
    struct celula *prox;
} celula;

celula* criacelula(const char*);
void push(celula **, const char*);
void ordena(celula *);
void imprime(celula *);
void libera(celula* cabeca);

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++){
        char lista[10000];
        fgets(lista, sizeof(lista), stdin);
        lista[strcspn(lista, "\n")] = 0;
        celula* cabeca = NULL;
        char* token=strtok(lista, " ");
        while (token!=NULL){
            push(&cabeca, token);
            token=strtok(NULL, " ");
        }
        ordena(cabeca);
        imprime(cabeca);
        libera(cabeca);
    }
    return 0;
}

celula* criacelula(const char* item){
    celula* novo=(celula*)malloc(sizeof(celula));
    strcpy(novo->item,item);
    novo->prox=NULL;
    return novo;
}

void push(celula **cabeca, const char* item){
    celula* temp=(*cabeca);
    while (temp!=NULL){
        if (strcmp(temp->item, item)==0){
            return;
        }
        temp=temp->prox;
    }
    celula* novo=criacelula(item);
    novo->prox=(*cabeca);
    *cabeca=novo;
}

void ordena(celula *cabeca){
    if (cabeca==NULL) return;
    celula *i, *j;
    char temp[21];
    for (i=cabeca;i!=NULL;i=i->prox){
        for (j=i->prox;j!=NULL;j=j->prox){
            if (strcmp(i->item, j->item)>0){
                strcpy(temp, i->item);
                strcpy(i->item, j->item);
                strcpy(j->item, temp);
            }
        }
    }
}

void imprime(celula *cabeca){
    celula* temp=cabeca;
    while (temp!=NULL){
        printf("%s",temp->item);
        if (temp->prox!=NULL){
            printf(" ");
        }
        temp=temp->prox;
    }
    printf("\n");
}

void libera(celula* cabeca){
    celula* temp;
    while (cabeca!=NULL){
        temp=cabeca;
        cabeca=cabeca->prox;
        free(temp);
    }
}
