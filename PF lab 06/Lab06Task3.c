#include<stdio.h>

int main() {
    int n, i, j, isPrime;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // Check if the input number is prime
    int isInputPrime = 1;
    
    if (n <= 1) {
        isInputPrime = 0;
    } else {
        for (i = 2; i <= n/2; i++) {
            if (n % i == 0) {
                isInputPrime = 0;
                break;
            }
        }
    }
    
    if (isInputPrime) {
        printf("%d is a PRIME number (Valid Student ID)\n\n", n);
    } else {
        printf("%d is NOT a prime number (Invalid Student ID)\n\n", n);
    }

    printf("Prime numbers from 1 to %d are:\n", n);
    
    for (i = 2; i <= n; i++) {
        isPrime = 1;
        
        for (j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        
        if (isPrime) {
            printf("%d ", i);
        }	
    }
    
    return 0;
}
