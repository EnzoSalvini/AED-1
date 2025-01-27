#include <stdio.h>
#include <math.h>

int main(){
    int r=1,w,l,cont=1;
    float raiz;
    while(r!=0){
        scanf("%d",&r);
        if(r==0){
            return 0;
        }
        scanf("%d",&w);
        scanf("%d",&l);
        raiz=sqrt(pow(w,2)+pow(l,2));
        if((2*r)>=raiz){
            printf("Pizza %d fits on the table.\n",cont);
        }
        else{
            printf("Pizza %d does not fit on the table.\n",cont);
        }
        cont++;
    }
    return 0;
}
