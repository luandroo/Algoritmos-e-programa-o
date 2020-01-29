#include<stdio.h>
int main(){
        int nud ,i=0,soma=0;
        printf("DIGITE UM NUMERO\n");
          scanf("%d",&nud);
            for (i=0;nud>=0;i++){
            soma=soma+nud;
            printf("DIGITE UM NUMERO\n");
            scanf("%d",&nud);
        }
       printf("soma dos valores %d\n",soma);
}



