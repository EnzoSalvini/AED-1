#include <stdio.h>
#include <math.h>

int main (){
  unsigned int x,n;
  double resultado;
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    scanf("%d",&x);
    resultado=pow(2, x);
    printf("%.lf kg\n", trunc(resultado/12000));
  }
}
