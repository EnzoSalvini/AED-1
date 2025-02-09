#include <stdio.h>
#include <stdlib.h>

int main() {
    int N,X;
    int *contagem=(int *)calloc(2001,sizeof(int));
    if (contagem==NULL){
        return 1;
    }
    scanf("%d",&N);
    for (int i=0;i<N;i++){
        scanf("%d",&X);
        if (X>=1 && X<=2000){
            contagem[X]++; 
        }
    }
    for (int i=1;i<=2000;i++){
        if (contagem[i]>0){
            printf("%d aparece %d vez(es)\n",i,contagem[i]);
        }
    }
    free(contagem);
    return 0;
}
