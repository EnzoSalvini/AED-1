#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char nome[50];
    struct celula *prox;
}no;

no*criar_no(char *);
void adicionafim(no**,char*);
void adicionaantes(no**,char*,no*);
void imprime(no*);

int main() {
    no*lista_amigos=NULL;
    no*nova_lista_amigos=NULL;
    char lista1[200], lista2[200], amigo[50];
    fgets(lista1, sizeof(lista1), stdin);
    lista1[strcspn(lista1, "\n")] = '\0';
    fgets(lista2, sizeof(lista2), stdin);
    lista2[strcspn(lista2, "\n")] = '\0';
    fgets(amigo, sizeof(amigo), stdin);
    amigo[strcspn(amigo, "\n")] = '\0';
    char*token=strtok(lista1, " ");
    while(token!=NULL){
        adicionafim(&lista_amigos, token);
        token=strtok(NULL, " ");
    }
    token=strtok(lista2, " ");
    while(token!=NULL){
        adicionafim(&nova_lista_amigos, token);
        token = strtok(NULL, " ");
    }
    if(strcmp(amigo, "nao")==0){
        no *temp=nova_lista_amigos;
        while(temp != NULL) {
            adicionafim(&lista_amigos, temp->nome);
            temp = temp->prox;
        }
    } 
    else{
        adicionaantes(&lista_amigos, amigo, nova_lista_amigos);
    }
    imprime(lista_amigos);
    return 0;
}

no*criar_no(char *nome){
    no*novo=(no*)malloc(sizeof(no));
    strcpy(novo->nome,nome);
    novo->prox = NULL;
    return novo;
}

void adicionafim(no**inicio,char*nome){
    no *novo=criar_no(nome);
    if (*inicio==NULL){
        *inicio=novo;
    } 
    else{
        no*temp=*inicio;
        while (temp->prox!=NULL){
            temp=temp->prox;
        }
        temp->prox=novo;
    }
}

void adicionaantes(no**inicio,char*nome_indicado,no*nova_lista){
    no *novo_amigo=nova_lista;
    no *anterior=NULL,*atual=*inicio;
    while(atual!=NULL && strcmp(atual->nome,nome_indicado)!=0){
        anterior=atual;
        atual=atual->prox;
    }
    while(novo_amigo!=NULL){
        no *prox_amigo=novo_amigo->prox;
        novo_amigo->prox=atual;
        if(anterior==NULL){
            *inicio=novo_amigo;
        } 
        else{
            anterior->prox=novo_amigo;
        }
        anterior=novo_amigo;
        novo_amigo=prox_amigo;
    }
}

void imprime(no*inicio){
    no*temp=inicio;
    int primeiro=1;
    while(temp!=NULL){
        if(!primeiro){
            printf(" ");
        }
        printf("%s",temp->nome);
        primeiro = 0;
        temp=temp->prox;
    }
    printf("\n");
}
