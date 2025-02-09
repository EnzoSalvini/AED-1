#include <stdio.h>

int calcular_minutos_sono(int,int,int,int);

int main(){
    int h1,m1,h2,m2;
    while (1){
        scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
        if (h1==0 && m1==0 && h2==0 && m2==0){
            break;
        }
        printf("%d\n",calcular_minutos_sono(h1,m1,h2,m2));
    }
    return 0;
}

int calcular_minutos_sono(int h1,int m1,int h2,int m2){
    int minutos_atual=h1*60+m1;
    int minutos_alarme=h2*60+m2;
    if (minutos_alarme>=minutos_atual){
        return minutos_alarme-minutos_atual;
    } 
    else{
        return (1440-minutos_atual)+minutos_alarme;
    }
}
