#include<stdio.h>

int main()
{
    int sec_num,guess_num;
    scanf("%d",&sec_num);
    scanf("%d",&guess_num);
    if(guess_num==sec_num){
        printf("you have guessed it right!");
    }
    else if(guess_num > sec_num){
        printf("your guess is too high!");
    }
    else{
        printf("your guess is too low!");
    }
}