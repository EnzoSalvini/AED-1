#include <stdio.h>

int main(){
    unsigned int a,b;
    while (scanf("%u %u",&a,&b)!=EOF){
        unsigned int resultado=a^b;
        printf("%u\n", resultado);
    }
    return 0;
}
