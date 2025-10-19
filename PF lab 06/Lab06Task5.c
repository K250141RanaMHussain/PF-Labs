#include<stdio.h>

int main(){
    int num,digit;
    int factorial=1;
    printf("Enter a digit:");
    scanf("%d", &num);
    
    if(num>0){
        digit=num;
        while(digit){
            factorial= factorial * digit;
            digit--;
        }
        printf("The factorial of %d is %d.", num, factorial);  // Fixed: removed 'digit' and added 'num'
    }else if(num==0){
        printf("The factorial of %d is 1.", num);
    }else if(num<0){
        printf("The factorial for negative integer does not exist.");
    }
    return 0;
}
