#include <stdio.h>
#include <string.h>

int main(){
    char frase[256];
    while(fgets(frase,sizeof(frase),stdin)){
        if (frase[0]=='\n'){
            continue;
        }
        frase[strcspn(frase, "\n")] = '\0';
        for(int i=0;i<strlen(frase);i++){
            switch(frase[i]){
                case '@':
                    frase[i]='a';
                    break;
                case '&':
                    frase[i]='e';
                    break;
                case '!':
                    frase[i]='i';
                    break;
                case '*':
                    frase[i]='o';
                    break;
                case '#':
                    frase[i]='u';
                    break;
                default:
                    break;
            }
        }
        printf("%s\n", frase);
    }
    return 0;
}
