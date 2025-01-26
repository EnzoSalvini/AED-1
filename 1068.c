#include <stdio.h>
#include <string.h>

int verificaparenteses(char*);

int main() {
    char caso[1001];
    while (fgets(caso, sizeof(caso), stdin)) {
        caso[strcspn(caso, "\n")]='\0';
        if (verificaparenteses(caso)){
            printf("correct\n");
        } 
        else{
            printf("incorrect\n");
        }
    }
    return 0;
}

int verificaparenteses(char *caso){
    int pilha=0;
    for (int i=0;caso[i]!='\0';i++){
        if (caso[i]=='('){
            pilha++;
        } 
        else if (caso[i]==')'){
            if (pilha==0){
                return 0;
            }
            pilha--;
        }
    }
    return pilha==0;
}
