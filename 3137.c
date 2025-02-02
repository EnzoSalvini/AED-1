#include <stdio.h>
#include <math.h>

int main(){
    int P;
    scanf("%d",&P);
    int totaldigitos=0;
    int i=1;
    while (i<=P){
        int proximolimite=i*10-1;
        if (proximolimite>P){
            proximolimite=P;
        }
        totaldigitos+=(proximolimite-i+1)*(1+(int)log10(i));
        i*=10;
    }
    printf("%d\n",totaldigitos);
    return 0;
}
