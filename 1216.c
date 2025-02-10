#include <stdio.h>
#include <string.h>

int main() {
    char nome[100];
    int distancia,soma=0,cont=0;
    while (fgets(nome,sizeof(nome),stdin)!=NULL){ 
        nome[strcspn(nome,"\n")]=0;
        if (scanf("%d",&distancia)!=1) break;
        getchar();
        soma+=distancia;
        cont++;
    }
    if (cont>0){
        printf("%.1f\n",(double)soma/cont);
    }
    return 0;
}
