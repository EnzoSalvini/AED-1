#include <stdio.h>

void contavai1(int a,int b);

int main(){
    int a,b;
    while (1){
        scanf("%d %d",&a,&b);
        if (a==0 && b==0){
            break;
        }
        contavai1(a,b);
    }
    return 0;
}

void contavai1(int a,int b){
    int vai1=0,cont=0;
    while (a>0 || b>0){
        int soma=(a%10)+(b%10)+vai1;
        if (soma>=10){
            vai1=1;
            cont++;
        } 
        else{
            vai1=0;
        }
        a/=10;
        b/=10;
    }
    if (cont==0){
        printf("No carry operation.\n");
    }
    else if (cont==1){
        printf("1 carry operation.\n");
    }
    else{
        printf("%d carry operations.\n",cont);
    }
}
