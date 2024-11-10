//fiz o codigo junto com um amigo de outra turma
//o codigo funciona no vscode, exceto por \n printado a mais
//porem, ao passar para o beecrowd ele nao é executado, por isso não consegui subir la

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char *info;
    struct No *prox;
}No, Cabeca;

No * inicializa();

Cabeca * insere(Cabeca *, char [20]);
void print_lista(Cabeca *);
void junta_lista(Cabeca *, Cabeca *, char *);
void limpa_lista(Cabeca *);


int main(){

    char vetor_1[100];
    char vetor_2[100];
    char cond[20];
    //
    Cabeca *lista_1 = inicializa();
    Cabeca *lista_2 = inicializa();
    //

    fgets(vetor_1, sizeof(vetor_1), stdin);
    fgets(vetor_2, sizeof(vetor_2), stdin);

    int count = 0;

    char *tokens_1[10];
    char *tokens_2[10]; 
    
    char *token = strtok(vetor_1, " ");
    while (token != NULL) {
        tokens_1[count++] = token;  
        token = strtok(NULL, " ");
    }

    for (int i = count - 1; i >= 0; i--) {
        lista_1 = insere(lista_1, tokens_1[i]);
    }

    count = 0; 

    

    token = strtok(vetor_2, " ");
    while (token != NULL) {
        tokens_2[count++] = token;  
        token = strtok(NULL, " ");
    }

    for (int i = count - 1; i >= 0; i--) {
        lista_2 = insere(lista_2, tokens_2[i]);
    }


    fgets(cond, sizeof(cond), stdin);


    if(strcmp(cond, "nao\n") == 0){
        print_lista(lista_1);
        print_lista(lista_2);
        limpa_lista(lista_1);
        limpa_lista(lista_2);   
    }
    else{
        junta_lista(lista_1, lista_2, cond);
        print_lista(lista_1);
        limpa_lista(lista_1);
    }
    
}


No * inicializa(){
    return NULL;
}

Cabeca * insere(Cabeca * C, char *info){
    No *no = malloc(sizeof(No));

    no->info = info;
    no->prox = C;

    return no;
}

void print_lista(Cabeca * C){
    Cabeca *p = C;

    while(p != NULL){
        printf("%s ", p->info);
        p = p->prox;
    }
}

void junta_lista(Cabeca * lista_1, Cabeca * lista_2, char * item){
    No * ant1 = NULL;
    No * p1 = lista_1;


    while(strcmp(p1->info, item) != 0) {
        ant1 = p1;
        p1 = p1->prox;
    }

    
    ant1->prox = lista_2;
   
   
    No * ant2 = NULL;
    No * p2 = lista_2;

    while (p2 != NULL) {
        ant2 = p2;
        p2 = p2->prox;
    }

    ant2->prox = p1;
}

void limpa_lista(Cabeca* C){
    No * p = C;

    while(p != NULL){
        No *t = p->prox;
        free(p);
        p = t;
    }
}
