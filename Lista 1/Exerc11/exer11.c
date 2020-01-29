#include <stdio.h>
int main(){
    double preco;
    printf("digite o valor da compra\n");
    scanf("%lf" ,&preco);
   if (preco < 20.00)
        printf("Lucro de 45 porcento %.2lf\n" ,preco * 1.45);
    else
        printf("Lucro de 30 porcento %.2lf\n" ,preco * 1.30);

}
