#include <stdio.h>
#include <string.h>

const char* quem_venceu(const char* rajesh, const char* sheldon);

int main(){
    int C;
    scanf("%d",&C);
    while (C--){
        char rajesh[10],sheldon[10];
        scanf("%s %s",rajesh,sheldon);
        const char* resultado=quem_venceu(rajesh,sheldon);
        printf("%s\n", resultado);
    }
    return 0;
}

const char* quem_venceu(const char* rajesh, const char* sheldon){
    if (strcmp(rajesh,sheldon)==0){
        return "empate";
    }
    else if ((strcmp(rajesh,"tesoura")==0 && (strcmp(sheldon,"papel")==0 || strcmp(sheldon,"lagarto")==0)) ||
        (strcmp(rajesh,"papel")==0 && (strcmp(sheldon,"pedra")==0 || strcmp(sheldon,"spock")==0)) ||
        (strcmp(rajesh,"pedra")==0 && (strcmp(sheldon,"lagarto")==0 || strcmp(sheldon,"tesoura")==0)) ||
        (strcmp(rajesh,"lagarto")==0 && (strcmp(sheldon,"spock")==0 || strcmp(sheldon,"papel")==0)) ||
        (strcmp(rajesh,"spock")==0 && (strcmp(sheldon,"tesoura")==0 || strcmp(sheldon,"pedra")==0))){
        return "rajesh";
    } 
    else{
        return "sheldon";
    }
}
