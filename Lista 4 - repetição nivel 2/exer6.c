#include<stdio.h>
int main()
        {
    int num,maior,i;
    printf("DIGITE O PRIMEIRO VALOR\n");
    scanf("%d",&num);
            maior=num;
        for(i=0;num>0;i++){
        if (num>maior)
            maior=num;
            printf("DIGITE OUTRO VALOR\n");
                scanf("%d",&num);
        }
        printf("O maior %d",maior);
        }
