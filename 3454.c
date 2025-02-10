#include <stdio.h>

int main() {
    char jogo[4];
    scanf("%s",jogo);
    int contX=0,contO=0;
    for (int i=0;i<3;i++){
        if (jogo[i]=='X') contX++;
        if (jogo[i]=='O') contO++;
    }
    if (contO>contX || contX>contO+1){
        printf("?\n");
        return 0;
    }
    int ganhoualice=(jogo[0]=='X' && jogo[1]=='X') || (jogo[1]=='X' && jogo[2]=='X');
    int ganhoubob=(jogo[0]=='O' && jogo[1]=='O') || (jogo[1]=='O' && jogo[2]=='O');
    if ((ganhoualice && ganhoubob) || (ganhoubob && contX>contO)){
        printf("?\n");
        return 0;
    }
    if (ganhoualice){
        printf("Alice\n");
    }
    else if (ganhoubob){
        printf("Bob\n");
    }
    else{
        if (contX+contO==3){
            printf("*\n");
        }
        else{
            printf("?\n");
        }
    }
    return 0;
}
