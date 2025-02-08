#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PARTICIPANTES 100
#define MAX_NOME 100

typedef struct{
    char nome[MAX_NOME];
    int escolha;
    int ordem_inscricao;
}Participante;

int comparar(const void *,const void *);

int main(){
    Participante participantes[MAX_PARTICIPANTES];
    char nome[MAX_NOME], escolha[4];
    int total=0, i;
    Participante amigo_habay;
    amigo_habay.nome[0]='\0';
    int maior_tamanho=-1;
    while (1){
        scanf("%s",nome);
        if (strcmp(nome, "FIM")==0){
            break;
        }
        scanf("%s",escolha);
        int ehduplicado=0;
        if (strcmp(escolha,"YES")==0){
            for (i=0;i<total;i++){
                if (strcmp(participantes[i].nome,nome)==0 && participantes[i].escolha==1){
                    ehduplicado=1;
                    break;
                }
            }
        }
        if (!ehduplicado){
            strcpy(participantes[total].nome,nome);
            participantes[total].escolha=(strcmp(escolha,"YES")==0)?1:0;
            participantes[total].ordem_inscricao=total;
            total++;
        }
    }
    qsort(participantes,total,sizeof(Participante),comparar);
    for (i=0;i<total;i++){
        printf("%s\n",participantes[i].nome);
        if (participantes[i].escolha==1){
            int tamanho_nome=strlen(participantes[i].nome);
            if (tamanho_nome>maior_tamanho || (tamanho_nome==maior_tamanho && participantes[i].ordem_inscricao<amigo_habay.ordem_inscricao)){
                maior_tamanho=tamanho_nome;
                amigo_habay=participantes[i];
            }
        }
    }
    printf("\nAmigo do Habay:\n%s\n",amigo_habay.nome);
    return 0;
}

int comparar(const void *a,const void *b){
    Participante *p1=(Participante*)a;
    Participante *p2=(Participante*)b;
    if (p1->escolha!=p2->escolha){
        return p2->escolha-p1->escolha;
    }
    return strcmp(p1->nome,p2->nome);
}
