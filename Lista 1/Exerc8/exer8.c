#include<stdio.h>
int main(){
    double salario, valorpres, total, total2 ;
    printf("digite o salario e depois o valor da prestacao\n");
    scanf("%lf%lf",&salario,&valorpres);
    total= salario*0.30;
    total2= total+salario;
    if(total2>=valorpres)
    printf("Emprestimo aceito servidor publico\n");
    else
        printf("Nao foi aceito o emprestimo servidor publico vai trabalhar\n");


    }
