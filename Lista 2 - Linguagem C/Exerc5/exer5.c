#include <stdio.h>
int main(){
    double peso ,gorda , gordam ;
    printf("Digite o seu peso Atual :\n");
    scanf("%lf",&peso);
    printf("Peso Atual %.1lf\n",peso);
    gorda = peso *1000;
    gordam = gorda*0.12;
    printf("Peso em gramas %.0lf\n",gorda);
    printf("Peso em gramas (mais 12 porcento) = %.2lf",gordam);
}
