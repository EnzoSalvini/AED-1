#include <stdio.h>

int main() {
    int S,B,C;
    double tempo;
    scanf("%d %d %d",&S,&B,&C);
    tempo=1.0/((1.0/S)+(1.0/B)+(1.0/C));
    printf("%.3f\n", tempo);
    return 0;
}
