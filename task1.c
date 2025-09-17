#include <stdio.h>

int main() {
    int num1, num2, num3, total;
    float percentage;
    
    printf("Enter marks for subject 1 between 0 to 100: ");
    scanf("%d", &num1);
    
    printf("Enter marks for subject 2 between 0 to 100: ");
    scanf("%d", &num2);
    
    printf("Enter marks for subject 3 between 0 to 100: ");
    scanf("%d", &num3);
    
    if( num1 >= 0 && num1 <= 100 && num2 >= 0 && num2 <= 100 && num3 >= 0 && num3 <= 100 ){
	
    total = num1 + num2 + num3;
    percentage = (total / 300.0) * 100;
    
    printf("Total marks: %d\n", total);
    printf("Result: %.2f%%\n", percentage);
	}
	else{
	printf("Invalid input! Please enter marks correctly");
	}
    return 0;
}
