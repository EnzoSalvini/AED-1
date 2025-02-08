#include <stdio.h>
#include <string.h>

#define MOD 1000

void multiplica_matriz(int[2][2],int[2][2]);
void potencia_matriz(int[2][2],int);
int fibonacci_mod_1000(int);

int main(){
    int T,i;
    char fileira[10001];
    scanf("%d",&T);
    while (T--){
        scanf("%s",fileira);
        int n=0;
        for (i=0;fileira[i]!='\0';i++){
            n=(n*2)+(fileira[i]-'0');
            n%=1500;
        }
        int resultado=fibonacci_mod_1000(n);
        printf("%03d\n",resultado);
    }
    return 0;
}

void multiplica_matriz(int F[2][2], int M[2][2]){
    int x=(F[0][0] * M[0][0] + F[0][1] * M[1][0])%MOD;
    int y=(F[0][0] * M[0][1] + F[0][1] * M[1][1])%MOD;
    int z=(F[1][0] * M[0][0] + F[1][1] * M[1][0])%MOD;
    int w=(F[1][0] * M[0][1] + F[1][1] * M[1][1])%MOD;
    
    F[0][0]=x;
    F[0][1]=y;
    F[1][0]=z;
    F[1][1]=w;
}

void potencia_matriz(int F[2][2],int n){
    if (n<=1) return;
    int M[2][2]={{1, 1},{1, 0}};
    potencia_matriz(F,n/2);
    multiplica_matriz(F,F);
    if (n%2!=0){
        multiplica_matriz(F, M);
    }
}

int fibonacci_mod_1000(int n){
    if (n==0){ 
        return 0;
    }
    if (n==1){
        return 1;
    }
    int F[2][2]={{1,1},{1,0}};
    potencia_matriz(F,n-1);
    return F[0][0];
}
