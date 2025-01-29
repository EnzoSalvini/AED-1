#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
    int topo;
    char itens[300];
}pilha;

void inicializapilha(struct pilha*);
int pilhavazia(struct pilha*);
void empilhar(struct pilha*,char);
char desempilhar(struct pilha*);
int prioridade(char);
int operando(char);
int espaco(char);
void converte(char*);

int main() {
    int n;
    char expressao[300];
    scanf("%d", &n);
    getchar();
    for (int i=0;i<n;i++){
        fgets(expressao,sizeof(expressao),stdin);
        expressao[strlen(expressao)-1]='\0';
        converte(expressao);
        printf("%s\n", expressao);
    }
}

void inicializapilha(struct pilha *pilha){
    pilha->topo=-1;
}

int pilhavazia(struct pilha *pilha){
    return pilha->topo == -1;
}

void empilhar(struct pilha *pilha, char item){
    if (pilha->topo<299){
        pilha->itens[++pilha->topo]=item;
    }
}

char desempilhar(struct pilha *pilha){
    if (!pilhavazia(pilha)){
        return pilha->itens[pilha->topo--];
    }
    return -1;
}

int prioridade(char op){
    if (op=='+' || op=='-'){
        return 1;
    }
    if (op=='*' || op=='/'){
        return 2;
    }
    if (op=='^') {
        return 3;
    }
    return 0;
}

int operando(char c){
    return (c>='0' && c<='9') || (c >='a' && c<='z') || (c>='A' && c<='Z');
}

int espaco(char c){
    return c==' ' || c=='\t';
}

void converte(char *expressao){
    struct pilha pilha;
    inicializapilha(&pilha);
    int j=0;
    int len=strlen(expressao);
    char resultado[300];
    for (int i=0;i<len;i++){
        char c=expressao[i];
        if (espaco(c)){
            continue;
        }
        if (operando(c)){
            resultado[j++]=c;
        }
        else if (c=='('){
            empilhar(&pilha, c);
        }
        else if (c==')'){
            while (!pilhavazia(&pilha) && pilha.itens[pilha.topo]!='('){
                resultado[j++]=desempilhar(&pilha);
            }
            desempilhar(&pilha);
        }
        else if (c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
            while (!pilhavazia(&pilha) && prioridade(pilha.itens[pilha.topo])>=prioridade(c)){
                resultado[j++]=desempilhar(&pilha);
            }
            empilhar(&pilha, c);
        }
    }
    while (!pilhavazia(&pilha)){
        resultado[j++]=desempilhar(&pilha);
    }
    resultado[j] = '\0';
    strcpy(expressao, resultado);
}
