#include <stdio.h>

int main()
{
    int num,linhas=1 ,colunas=1;
    scanf("%d",&num);
    while(colunas<=num)
    {
        while(linhas<=num){
        printf("*");
        linhas++;
        }
        linhas=1;
        printf("\n");
        colunas++;

    }
    }
