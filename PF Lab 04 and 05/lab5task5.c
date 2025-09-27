#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    float discriminant, r1, r2, realPart, imagPart;

    printf("=== QUADRATIC EQUATION SOLVER ===\n");
    printf("Equation: ax^2 + bx + c = 0\n\n");
    
    printf("Enter coefficient of a: ");
    scanf("%d", &a);
    printf("Enter coefficient of b: ");
    scanf("%d", &b);
    printf("Enter coefficient of c: ");
    scanf("%d", &c);
    
    // Check for quadratic equation
    if (a == 0) {
        printf("This is not a quadratic equation (a cannot be 0).\n");
        printf("This becomes a linear equation: %dx + %d = 0\n", b, c);
        
        if (b == 0) {
            if (c == 0) {
                printf("Infinite solutions (0 = 0).\n");
            } else {
                printf("No solution (%d = 0 is false).\n", c);
            }
        } else {
            float linearRoot = (float)-c / b;
            printf("Root of linear equation: x = %.2f\n", linearRoot);
        }
    } else {
        // Calculate discriminant
        discriminant = b * b - 4 * a * c;
        
        printf("\nEquation: %dx^2 + %dx + %d = 0\n", a, b, c);
        printf("Discriminant (D) = %.2f\n", discriminant);
        
        if (discriminant > 0) {
            r1 = (-b + sqrt(discriminant)) / (2 * a);
            r2 = (-b - sqrt(discriminant)) / (2 * a);
            
            printf("Roots are REAL and DISTINCT.\n");
            printf("Root 1 = %.2f\n", r1);
            printf("Root 2 = %.2f\n", r2);
            
        } else if (discriminant == 0) {
            r1 = r2 = (float)-b / (2 * a);
            
            printf("Roots are REAL and EQUAL.\n");
            printf("Root 1 = Root 2 = %.2f\n", r1);
            
        } else {
            // Imaginary roots
            realPart = (float)-b / (2 * a);
            imagPart = sqrt(-discriminant) / (2 * a);
            
            printf("Roots are IMAGINARY.\n");
            printf("Root 1 = %.2f + %.2fi\n", realPart, imagPart);
            printf("Root 2 = %.2f - %.2fi\n", realPart, imagPart);
        }
    }
    
    return 0;
}