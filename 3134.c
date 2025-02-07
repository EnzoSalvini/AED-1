#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

int podeequilibrar(double,double,double,double);

int main(){
    double p1,p2,p3,p4;
    scanf("%lf %lf %lf %lf",&p1,&p2,&p3,&p4);
    if (podeequilibrar(p1,p2,p3,p4)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}

int podeequilibrar(double p1,double p2,double p3,double p4){
    double pesos[4]={p1,p2,p3,p4};
    for (int i=0;i<16;i++){
        double peso_esquerda=0.0,peso_direita=0.0;
        for (int j=0;j<4;j++){
            if (i & (1<<j)){
                peso_esquerda+=pesos[j];
            }
            else{
                peso_direita+=pesos[j];
            }
        }
        if (fabs(peso_esquerda-peso_direita)<EPSILON){
            return 1;
        }
    }
    return 0;
}
