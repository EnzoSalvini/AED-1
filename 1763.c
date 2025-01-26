#include <stdio.h>
#include <string.h>

char* paises[24]={
    "brasil", "alemanha", "austria","coreia","espanha","grecia","estados-unidos","inglaterra","australia","portugal","suecia",
    "turquia","argentina","chile","mexico","antardida","canada","irlanda","belgica","italia","libia","siria","marrocos","japao"
};

char* frases[24]={
    "Feliz Natal!","Frohliche Weihnachten!","Frohe Weihnacht!","Chuk Sung Tan!","Feliz Navidad!","Kala Christougena!",
    "Merry Christmas!","Merry Christmas!","Merry Christmas!","Feliz Natal!"," God Jul!","Mutlu Noeller",
    "Feliz Navidad!","Feliz Navidad!","Feliz Navidad!","Merry Christmas!","Merry Christmas!","Nollaig Shona Dhuit!"," Zalig Kerstfeest!",
    "Buon Natale!","Buon Natale!","Milad Mubarak!","Milad Mubarak!","Merii Kurisumasu!"
};

typedef struct{
    char pais[50];
    char frase[100];
}tradutor;

tradutor traducao[24];
int posicao;

void preenchetradutor();
int pesquisapais(char*);

int main(){
    preenchetradutor();
    char pais[100];
    while(fgets(pais,sizeof(pais),stdin)){
        pais[strcspn(pais, "\r\n")]='\0';
        if (pesquisapais(pais)==1){
            printf("%s\n",traducao[posicao].frase);
        }
        else{
            printf("--- NOT FOUND ---\n");
        }
    }
    return 0;
}

void preenchetradutor(){
    for(int i=0;i<24;i++){
        strcpy(traducao[i].pais,paises[i]);
        strcpy(traducao[i].frase,frases[i]);
    }
}

int pesquisapais(char*pais){
    for(int i=0;i<24;i++){
        if(strcmp(traducao[i].pais,pais)==0){
            posicao=i;
            return 1;
        }
    }
    return 0;
}
