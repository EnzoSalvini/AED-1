#include <stdio.h>

int main(){
    float x,y,z;
    scanf("%f %f %f",&x,&y,&z);
    if(x*x!=(z*z)+(y*y)){
        printf("Nao eh retangulo!\n");
    }
    else{
        printf("AREA = %.0f\n",(y*z/2)+3*z*z/8);
    }
}
