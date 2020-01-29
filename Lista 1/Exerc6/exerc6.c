#include <stdio.h>
int main()
{
    double x,y,dife;
    printf("Digite dois valores\n");
    scanf("%lf%lf",&x,&y);
    dife = (x-y)*(x-y);
    printf("Quadrado da Diferença e %0.3lf\n",dife);

}
