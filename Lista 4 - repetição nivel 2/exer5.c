#include<stdio.h>
int main(){
    int num,soma=0,contador=0,i,x;
    printf("DIGITE UM NUMERO");
    scanf("%d",&num);
    for (i=0;num>1;i++){
        if(num%3==0){
            soma=soma+num;
            contador++;
        }
        printf("DIGITE UM NUMERO");
        scanf("%d",&num);
    }
            x=soma/contador;
            printf("Media %d",x);
}
