#include <stdio.h>

int main(){
    float N, L, D, O;
    scanf("%f %f %f",&N,&L,&D);
    O=L;
    if(N*D/1000<=L){
        printf("%.0f",L);
    }
    else{
        while(L<N*D/1000){
            L=L+O;
        }
        printf("%.0f",L);
    }
}
