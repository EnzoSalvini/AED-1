#include <stdio.h>
#include <math.h>

int mdc(int,int);
void simplificar(int*,int *);

int main(){
    int n;
    scanf("%d",&n);
    while (n--){
        int N1,D1,N2,D2;
        char op;
        scanf("%d / %d %c %d / %d", &N1, &D1, &op, &N2, &D2);
        int numerador_resultado, denominador_resultado;
        if (op=='+'){
            numerador_resultado=N1*D2+N2*D1;
            denominador_resultado=D1*D2;
        } 
        else if (op=='-'){
            numerador_resultado=N1*D2-N2*D1;
            denominador_resultado=D1*D2;
        } 
        else if (op=='*'){
            numerador_resultado=N1*N2;
            denominador_resultado=D1*D2;
        } else if (op=='/'){
            numerador_resultado=N1*D2;
            denominador_resultado=N2*D1;
        }
        printf("%d/%d = ",numerador_resultado,denominador_resultado);
        simplificar(&numerador_resultado,&denominador_resultado);
        printf("%d/%d\n",numerador_resultado,denominador_resultado);
    }
    return 0;
}

int mdc(int a,int b){
    while (b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

void simplificar(int *numerador, int *denominador){
    int divisor=mdc(*numerador,*denominador);
    *numerador/=divisor;
    *denominador/=divisor;
    if (*denominador<0){
        *numerador=-(*numerador);
        *denominador=-(*denominador);
    }
}
