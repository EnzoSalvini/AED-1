#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct celula{
    char *palavra;
    struct celula *prox;
}cel;

cel* criacel(const char *palavra){
    cel*novo=(cel*)malloc(sizeof(cel));
    novo->palavra=strdup(palavra);
    novo->prox=NULL;
    return novo;
}

int ehletra(char c){
    return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

char minusculo(char c){
    if (c>='A' && c<='Z'){
        return c+('a'-'A');
    }
    return c;
}

void libera(cel*cabeca){
    cel*atual=cabeca;
    while (atual!=NULL){
        cel*prox=atual->prox;
        free(atual->palavra);
        free(atual);
        atual=prox;
    }
}

int jaexiste(cel*cabeca,const char *palavra){
    cel*atual=cabeca;
    while (atual!=NULL){
        if (strcmp(atual->palavra,palavra)==0){
            return 1;
        }
        atual=atual->prox;
    }
    return 0;
}

int dicionario(cel*cabeca,char *palavras[]){
    int i=0;
    cel*atual=cabeca;
    while (atual!=NULL && i<5000){
        palavras[i++]=atual->palavra;
        atual=atual->prox;
    }
    return i;
}

int compara(const void *a,const void *b){
    return strcmp(*(const char**)a, *(const char**)b);
}

int main(){
    char linha[200];
    cel*cabeca=NULL;
    char*palavras[5000];
    int contpalavra=0;
    while (fgets(linha,sizeof(linha),stdin)){
        int len=strlen(linha);
        char palavra[200];
        int indicepalavra=0;
        for (int i=0;i<=len;i++){
            char c=linha[i];
            if (ehletra(c)){
                palavra[indicepalavra++]=minusculo(c);
            }
            else{
                if (indicepalavra>0){
                    palavra[indicepalavra]='\0';
                    if (!jaexiste(cabeca,palavra)){
                        cel*novo=criacel(palavra);
                        novo->prox=cabeca;
                        cabeca=novo;
                        contpalavra++;
                    }
                    indicepalavra=0;
                }
            }
        }
    }
    int numeropalavras=dicionario(cabeca,palavras);
    qsort(palavras,numeropalavras,sizeof(char*),compara);
    for (int i=0;i<numeropalavras;i++){
        printf("%s\n", palavras[i]);
    }
    libera(cabeca);
    return 0;
}
