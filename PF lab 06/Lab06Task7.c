#include<stdio.h>

int main() {
    int num, original, reverse = 0, remainder;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    original = num; // Store the original number
    
    // Reverse the number using a loop
    while (num != 0) {
        remainder = num % 10;          
        reverse = reverse * 10 + remainder; // Build the reversed number
        num = num / 10;               
    }
    
    // Check if original number equals reversed number
    if (original == reverse) {
        printf("%d is a PALINDROME (Valid Library Code)\n", original);
    } else {
        printf("%d is NOT a palindrome (Invalid Library Code)\n", original);
    }
    
    printf("\nReversed number: %d\n", reverse);
    
    return 0;
}
