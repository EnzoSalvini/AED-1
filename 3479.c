#include <stdio.h>

typedef struct{
    int dia_inicio;
    int mes_inicio;
    int dia_fim;
    int mes_fim;
    char signo[20];
}signo;

int main(){
    signo signos[]={
        {21, 3, 20, 4,"aries"},
        {21, 4, 20, 5,"touro"},
        {21, 5, 20, 6,"gemeos"},
        {21, 6, 22, 7,"cancer"},
        {23, 7, 22, 8,"leao"},
        {23, 8, 22, 9,"virgem"},
        {23, 9, 22, 10,"libra"},
        {23, 10, 21, 11,"escorpiao"},
        {22, 11, 21, 12,"sagitario"},
        {22, 12, 20, 1,"capricornio"},
        {21, 1, 19, 2,"aquario"},
        {20, 2, 20, 3,"peixes"}
    };
    int dia,mes;
    scanf("%d/%d",&dia,&mes);
    for (int i=0;i<12;i++){
        if ((mes==signos[i].mes_inicio && dia>=signos[i].dia_inicio) || 
            (mes==signos[i].mes_fim && dia<=signos[i].dia_fim) || 
            (mes>signos[i].mes_inicio && mes<signos[i].mes_fim)){
            printf("%s\n",signos[i].signo);
            return 0;
        }
    }
    return 0;
}
