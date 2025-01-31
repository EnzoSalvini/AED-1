#include <stdio.h>

int josephus(int, int);

int main(){
    int NC, n, k;
    scanf("%d",&NC);
    for (int i=1;i<=NC;i++){
        scanf("%d %d",&n,&k);
        printf("Case %d: %d\n", i, josephus(n, k));
    }
    return 0;
}

int josephus(int n, int k){
    int result=0;
    for (int i=2;i<=n;i++){
        result=(result+k)%i;
    }
    return result + 1;
}
