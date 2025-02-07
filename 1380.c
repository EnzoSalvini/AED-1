#include <stdio.h>
#include <string.h>

#define MOD 1000

typedef struct{
    int mat[2][2];
}matriz;

matriz multiplica(matriz a, matriz b){
    matriz resultado={{{0,0},{0,0}}};
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                resultado.mat[i][j]=(resultado.mat[i][j]+a.mat[i][k]*b.mat[k][j])%MOD;
            }
        }
    }
    return resultado;
}

matriz elevamatriz(matriz base,long long exp){
    matriz resultado={{{1,0},{0,1}}};
    while (exp>0){
        if (exp%2==1){
            resultado=multiplica(resultado,base);
        }
        base=multiplica(base,base);
        exp/=2;
    }
    return resultado;
}

int fibonaccimod(long long k){
    if (k==1 || k==2){
        return 1;
    }
    matriz base={{{1,1},{1,0}}};
    matriz resultado=elevamatriz(base,k-1);
    return resultado.mat[0][0];
}

int main(){
    int T;
    char K[1000001];
    scanf("%d",&T);
    while (T--){
        scanf("%s",K);
        long long kreduzido=0;
        for (int i=0;K[i]!='\0';i++){
            kreduzido=(kreduzido*10+(K[i]-'0'))%1500;
        }
        if (kreduzido==0){
            kreduzido=1500;
        }
        int resultado=fibonaccimod(kreduzido);
        printf("%03d\n",resultado);
    }
    return 0;
}
