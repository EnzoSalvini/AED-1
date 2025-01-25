#include <stdio.h>

int verificar_linha(int[9][9],int);
int verificar_coluna(int[9][9],int);
int verificar_subgrade(int[9][9], int, int);
int verificar_sudoku(int[9][9]);

int main(){
    int n;
    scanf("%d", &n);
    int matrizes[n][9][9];
    for(int k=0;k<n;k++){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                scanf("%d", &matrizes[k][i][j]);
            }
        }
    }
    for (int k = 0; k < n; k++) {
        printf("Instancia %d\n",k+1);
        if(verificar_sudoku(matrizes[k])){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
        if(k<n-1){
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}

int verificar_linha(int matriz[9][9],int linha){
    int numeros[9+1]={0};
    for(int j=0;j<9;j++){
        int num=matriz[linha][j];
        if(num<1 || num>9 || numeros[num]==1){
            return 0;
        }
        numeros[num]=1;
    }
    return 1;
}

int verificar_coluna(int matriz[9][9],int coluna){
    int numeros[9+1]={0};
    for(int i=0;i<9;i++){
        int num=matriz[i][coluna];
        if(num<1 || num>9 || numeros[num]==1){
            return 0;
        }
        numeros[num]=1;
    }
    return 1;
}

int verificar_subgrade(int matriz[9][9], int inicio_linha, int inicio_coluna){
    int numeros[9+1]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int num=matriz[inicio_linha+i][inicio_coluna+j];
            if(num<1 || num>9 || numeros[num]==1){
                return 0;
            }
            numeros[num]=1;
        }
    }
    return 1;
}

int verificar_sudoku(int matriz[9][9]){
    for(int i=0;i<9;i++) {
        if(verificar_linha(matriz, i)==0 || verificar_coluna(matriz, i)==0){
            return 0;
        }
    }
    for(int i=0;i<9;i=i+3){
        for(int j=0; j<9; j=j+3){
            if(verificar_subgrade(matriz,i,j)==0){
                return 0;
            }
        }
    }
    return 1;
}
