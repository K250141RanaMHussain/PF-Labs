#include <stdio.h>

int main() {
    int a, b, swap;
    
    printf("Enter value for a: ");
    scanf("%d", &a);
    
    printf("Enter value for b: ");
    scanf("%d", &b);
    
    printf("Before swapping: a = %d, b = %d\n", a, b);
    
    // Swapping logic
    swap = a;
    a = b;
    b = swap;
    
    printf("After swapping: a = %d, b = %d\n", a, b);
    
    return 0;
}
