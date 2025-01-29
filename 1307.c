#include <stdio.h>
#include <string.h>
#include <math.h>

int convertebinario(char[30]);
int mdc(int, int);
int mdcmaiorque1(int,int);

int main(){
    int n;
    char binario1[30],binario2[30];
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++){
        fgets(binario1,sizeof(binario1),stdin);
        binario1[strlen(binario1)-1]='\0';
        fgets(binario2,sizeof(binario2),stdin);
        binario2[strlen(binario2)-1]='\0';
        if(mdcmaiorque1(convertebinario(binario1),convertebinario(binario2))){
            printf("Pair #%d: All you need is love!\n",i+1);
        }
        else{
            printf("Pair #%d: Love is not all you need!\n",i+1);
        }
    }
    return 0;
}

int convertebinario(char bin[30]){
    int decimal=0;
    int tamanho=strlen(bin);
    for (int i=0;i<tamanho;i++){
        if (bin[i]=='1'){
            decimal+=pow(2,tamanho-i-1);
        } 
    }
    return decimal;
}

int mdc(int a, int b){
    while (b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int mdcmaiorque1(int a,int b){
    return mdc(a,b)>1;
}
