#include <stdio.h>

int maiorcollatz(int);

int main(){
    int n=1;
    while(n!=0){
        scanf("%d",&n);
        if(n==0){
            break;
        }
        printf("%d\n",maiorcollatz(n));
    }
}

int maiorcollatz(int n){
    int maiornumero=n;
    while(n!=1){
        if(n%2==0){
            n=n/2;
        }
        else{
            n=3*n+1;
        }
        if(n>maiornumero){
            maiornumero=n;
        }
    }
    return maiornumero;
}
