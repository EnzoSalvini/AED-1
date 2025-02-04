#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    while (scanf("%d",&N)!=EOF){
        int esq[61]={0},dir[61]={0};
        int M,pares=0;
        char L;
        for (int i=0;i<N;i++){
            scanf("%d %c",&M,&L);
            if (L=='D'){
                dir[M]++;
            }
            else{
                esq[M]++;
            }
        }
        for (int i=30;i<=60;i++){
            if (esq[i]<dir[i]){
                pares+=esq[i];
            }
            else{
                pares+=dir[i];
            }
        }
        printf("%d\n", pares);
    }
    return 0;
}
