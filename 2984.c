#include <stdio.h>
#include <string.h>

int main(){
    char lista[100000];
    int pilha=0;
    fgets(lista,sizeof(lista),stdin);
    lista[strlen(lista)-1]='\0';
    for (int i=0;i<strlen(lista);i++){
        if (lista[i]=='('){
            pilha++;
        } 
        else if (lista[i]==')' && pilha>0){
            pilha--;
        }
    }
    if(pilha>0){
        printf("Ainda temos %d assunto(s) pendente(s)!\n",pilha);
    }
    else{
        printf("Partiu RU!\n");
    }
}
