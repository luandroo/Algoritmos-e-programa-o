#include <stdio.h>
int main()
{
int i=1,k=1;
    while(i<=3){
        while(k<=10){
        printf(" %d x %d = %d\n",i,k,i*k);
        k++;
        }
        printf("\n");
        k=1;
        i++;
    }




}
