#include <stdio.h>

long long mdc(long long,long long);
long long mmc(long long, long long);

int main(){
    long long N,A,B;
    while (1){
        scanf("%lld %lld %lld", &N, &A, &B);
        if (N==0 && A==0 && B==0){
            break;
        }
        long long contA=N/A;
        long long contB=N/B;
        long long uniaoAB=N/mmc(A,B);
        printf("%lld\n",contA+contB-uniaoAB);
    }
    return 0;
}

long long mdc(long long a,long long b){
    while (b!=0) {
        long long temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

long long mmc(long long a, long long b){
    return (a*b)/mdc(a,b);
}
