#include<stdio.h>
int main(){
int num,i,a;
    printf("DIGITE UM NUMERO\n");
    scanf("%d",&num);
    for(i=0, a = 0;i*i<=num;i++)
        if (num==i*i)
            a = 1;
        if(a==1)
            printf("O numero é quadrado perfeito \n");
        else
            printf("O numero nao é quadrado perfeito\n");

    }


