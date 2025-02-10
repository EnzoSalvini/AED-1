#include <stdio.h>
#include <string.h>

char decodifica(char c);

int main(){
    char linha[1000];
    while (fgets(linha, sizeof(linha), stdin)){
        for (int i=0;linha[i]!='\0';i++){
            printf("%c", decodifica(linha[i]));
        }
    }
    return 0;
}

char decodifica(char c){
    char *original="1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
    char *arrumado ="`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
    for (int i=0;original[i]!='\0';i++){
        if (c==original[i]){
            return arrumado[i];
        }
    }
    return c;
}
