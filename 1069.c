#include <stdio.h>
#include <string.h>

int contadiamante(char*);

int main(){
    int n;
    char caso[1001];
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%s", caso);
        printf("%d\n", contadiamante(caso));
    }
    return 0;
}

int contadiamante(char*caso){
    int soma=0;
    int i, j;
    int tamanho=strlen(caso);
    for (i=0;i<tamanho;i++){
        if (caso[i]=='<'){
            for (j=i+1;j<tamanho;j++){
                if (caso[j]=='>'){
                    soma++;
                    caso[j] = '.';
                    break;
                }
            }
        }
    }
    return soma;
}
