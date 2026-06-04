#include<stdio.h>
#include<string.h>

int main()
{
    int n,i;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(int i=1;i<=10;i++){
        printf("%d X %d = %d\n",n,i,n*i);
    }
}