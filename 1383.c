/*tentativa não funcional, as funções repetelinha e repetecoluna em algum momento comparam o valor de uma casa com ela mesma 
retornando 1, indicando um problema na logica principal do meu programa, alem dele nao estar completamente adaptado para "k" instancias*/
//não sei se é possível resolver utilizando somente conhecimentos de L.P
#include <stdio.h>

int repetelinha(int, int, int[9][9]);
int repetecoluna(int, int, int[9][9]);

int main(){
    int k,x=0,y=0;
    scanf("%i",&k);
    int grade[k*9][9];
    for (int i=0;i<k*9;i++){
        for (int j=0;j<9;j++){
            scanf("%i",&grade[i][j]);
        }
    }
    for (int l=0;l<k;l++){
        printf("instancia %i\n",l+1);
        if (repetelinha (x,grade[x][y],grade) || repetecoluna (y, grade[x][y], grade)==1){
            printf("NAO\n");
        }
        else{
            printf("SIM\n");
        }
        printf("\n");
    }
}

int repetelinha(int x, int n, int grade[9][9]){
    for (int i=0;i<9;i++){
        if (grade[x][i]==n){
            return 1;
        }
    }
    return 0;    
}

int repetecoluna (int y, int n, int grade[9][9]){
    for (int j=0;j<9;j++){
        if (grade[j][y]==n){
            return 1;
        }
    }
    return 0;
}
