#include <stdio.h>
#include <string.h>

void ordenadecrescente(char[][51], int);

int main(){
    int N;
    scanf("%d", &N);
    getchar();
    char linha[2550];
    char palavras[50][51];
    for (int i=0;i<N;i++){
        fgets(linha, sizeof(linha), stdin);
        int count=0;
        char *token=strtok(linha," \n");
        while (token!=NULL){
            strcpy(palavras[count++], token);
            token=strtok(NULL," \n");
        }
        ordenadecrescente(palavras, count);
        for (int j=0;j<count;j++){
            if (j>0) printf(" ");
            printf("%s", palavras[j]);
        }
        printf("\n");
    }
    return 0;
}

void ordenadecrescente(char palavras[][51], int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (strlen(palavras[j])<strlen(palavras[j+1])){
                char temp[50+1];
                strcpy(temp, palavras[j]);
                strcpy(palavras[j],palavras[j+1]);
                strcpy(palavras[j+1],temp);
            }
        }
    }
}
