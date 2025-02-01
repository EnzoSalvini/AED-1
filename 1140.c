#include <stdio.h>
#include <string.h>

char convertemaiuscula(char c);

int main(){
    char frase[1000];
    while(1){
        fgets(frase, sizeof(frase), stdin);
        frase[strlen(frase)-1]='\0';
        if (frase[0]=='*'){
            break;
        }
        char letrainicial=convertemaiuscula(frase[0]);
        int tautograma=1;
        for (int i=1;frase[i]!='\0';i++){
            if (frase[i]==' '){
                if (convertemaiuscula(frase[i + 1])!=letrainicial){
                    tautograma=0;
                    break;
                }
            }
        }
        if (tautograma==1){
            printf("Y\n");
        }
        else{
            printf("N\n");
        }
    }
    return 0;
}

char convertemaiuscula(char c){
    if (c>='A' && c<= 'Z'){
        return c+32;
    }
    return c;
}
