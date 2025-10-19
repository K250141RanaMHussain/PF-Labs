#include<stdio.h>

int main() {
    int n, i, j;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    if(n>=0){
	printf("\nFirst %d Catalan numbers:\n", n);
    
    for (i = 0; i < n; i++) {
        // Compute (2n)! using loop
        long long factorial_2n = 1;
        for (j = 1; j <= 2*i; j++) {
            factorial_2n *= j;
        }
        
        // Compute (n+1)! using loop
        long long factorial_n1 = 1;
        for (j = 1; j <= i+1; j++) {
            factorial_n1 *= j;
        }
        
        // Compute n! using loop
        long long factorial_n = 1;
        for (j = 1; j <= i; j++) {
            factorial_n *= j;
        }
        
        // Calculate Catalan number: C_n = (2n)! / ((n+1)! * n!)
        long long catalan = factorial_2n / (factorial_n1 * factorial_n);
        
        printf("C%d = %lld\n", i, catalan);
    }
	}else{
		printf("Catalan numbers are not defined for negative integers.");
	}
    
    
    return 0;
}
