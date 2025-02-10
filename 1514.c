#include <stdio.h>

int main(){
    int N,M;
    while (1){
        scanf("%d %d",&N,&M);
        if (N==0 && M==0){
            break;
        }
        int competidores[N][M];
        int i,j;
        for (i=0;i<N;i++){
            for (j=0;j<M;j++){
                scanf("%d",&competidores[i][j]);
            }
        }
        int caracteristicas=0;
        int caracteristica1=1;
        for (i=0;i<N;i++){
            int resolveutodos=1;
            for (j=0;j<M;j++){
                if (competidores[i][j]==0){
                    resolveutodos=0;
                    break;
                }
            }
            if (resolveutodos){
                caracteristica1=0;
                break;
            }
        }
        int caracteristica2=1;
        for (j=0;j<M;j++){
            int alguemresolveu=0;
            for (i=0;i<N;i++){
                if (competidores[i][j]==1){
                    alguemresolveu=1;
                    break;
                }
            }
            if (!alguemresolveu){
                caracteristica2=0;
                break;
            }
        }
        int caracteristica3=1;
        for (j=0;j<M;j++){
            int resolvidoportodos=1;
            for (i=0;i<N;i++){
                if (competidores[i][j]==0){
                    resolvidoportodos=0;
                    break;
                }
            }
            if (resolvidoportodos){
                caracteristica3=0;
                break;
            }
        }
        int caracteristica4=1;
        for (i=0;i<N;i++){
            int resolveu1=0;
            for (j=0;j<M;j++){
                if (competidores[i][j]==1){
                    resolveu1=1;
                    break;
                }
            }
            if (!resolveu1){
                caracteristica4=0;
                break;
            }
        }
        caracteristicas=caracteristica1+caracteristica2+caracteristica3+caracteristica4;
        printf("%d\n", caracteristicas);
    }
    return 0;
}
