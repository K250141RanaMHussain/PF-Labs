#include <stdio.h>

int main() {
    int num;
    
    printf("Enter an integer between 65 and 80: ");
    scanf("%d", &num);
    
    if (num >= 65 && num <= 80) {
        printf("%d - %c\n", num, num);
    } 
	else {
        printf("Invalid input! Please enter a number between 65 and 80.\n");
    }
    
    return 0;
}
