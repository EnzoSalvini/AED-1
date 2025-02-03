#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[101];
    int poder;
    int kills;
    int mortes;
}candidato;

int comparar(const void *,const void *);

int main() {
    int N;
    scanf("%d", &N);
    candidato candidatos[N];
    for (int i=0;i<N;i++){
        scanf("%s %d %d %d",candidatos[i].nome,&candidatos[i].poder,&candidatos[i].kills,&candidatos[i].mortes);
    }
    qsort(candidatos, N, sizeof(candidato), comparar);
    printf("%s\n", candidatos[0].nome);
    return 0;
}

int comparar(const void *a, const void *b){
    candidato *c1=(candidato*)a;
    candidato *c2=(candidato*)b;
    if (c2->poder!=c1->poder){
        return c2->poder-c1->poder;
    }
    if (c2->kills != c1->kills){
        return c2->kills-c1->kills;
    }
    if (c1->mortes!=c2->mortes) {
        return c1->mortes-c2->mortes;
    }
    return strcmp(c1->nome,c2->nome);
}
