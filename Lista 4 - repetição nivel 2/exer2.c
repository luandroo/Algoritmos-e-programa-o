#include<stdio.h>
int main(){
	int n1,n2,soma;
	printf("DIGITE DOIS NUMEROS\n");
	scanf("%d%d",&n1,&n2);
		printf("Limite inferior: %d\n",n1);
   		printf("Limite superior: %d\n",n2);
        printf("Saida:");
		for(n1++;n1<n2;n1++){
			if(n1 % 2==0){
                printf(" %d",n1);
                soma = soma + n1;
            }
            }
			printf("\nSoma: %d\n",soma);
}
