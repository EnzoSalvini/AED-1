#include <stdio.h>
#include <math.h>

int ehprimo(int);

int main() {
    int n, X;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&X);
        if (ehprimo(X)==0){
            printf("Not Prime\n");
        } 
        else{
            printf("Prime\n");
        }
    }
    return 0;
}

int ehprimo(int x){
    if (x<=1) return 0;
    if (x==2) return 1;
    if (x%2==0) return 0;
    int raiz=(int)sqrt(x);
    for (int i=3;i<=raiz;i+=2){
        if (x%i==0){
            return 0;
        }
    }
    return 1;
}
