#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordemalfabetica(char**, int);

int main(){
    int n, k, x=0;
    char nome[50], **lista;
    scanf("%d",&n);
    scanf("%d",&k);
    getchar(); //usado pra remover o "\n" deixado após usar scanf, o que gerava um problema no código
    lista=(char**)malloc(n*sizeof(char*));
    for (int i=0;i<n;i++){
        fgets(nome, sizeof(nome),stdin);
        nome[strlen(nome)-1]='\0';
        lista[i]=strdup(nome);
    }
    ordemalfabetica(lista, n);
    for (int i=0;i<k;i++){
        x++;
    }
    printf("%s\n",lista[x-1]);
    for (int i=0;i<n;i++){
        free(lista[i]);
    }
    return 0;
}

void ordemalfabetica(char *str[50], int n) { //bubblesort
    char *aux;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (strcmp(str[j],str[j+1])>0) {
                aux=str[j];
                str[j]=str[j+1];
                str[j+1]=aux;
            }
        }
    }
}
