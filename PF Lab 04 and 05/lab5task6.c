#include<stdio.h>

int main(){
    
    int a,b,c,shape,calculation;
    float area, perimeter;
    printf("===Geometry Calculator=== \n");
    printf("Select shapes in the following: \n");
    printf("1 for circle: \n");
    printf("2 for trianle: \n");
    printf("3 for rectangle: \n");
    scanf("%d", &shape);

    switch (shape)
    {
    case 1:
        printf("You selected circle \n");
        printf("What do you want to calculate? \n 1.Area? \n 2.Perimeter? \n");
        scanf("%d", &calculation);
        switch (calculation)
        {
        case 1:
            printf("You selected Area. \n");
            printf("Enter value for radius in inch:");
            scanf("%d",&a);
            
            area = (float) 3.142*a*a;
            printf("The area of circle is %.2f inches squared.", area); 

            break;
        case 2:
            printf("You selected circum meter. \n");
            printf("Enter value for radius in inch:");
            scanf("%d",&a);
            

            perimeter = (float) 2 * 3.142 * a;
            printf("The circum meter of circle is %.2f inches.", perimeter); 

            break;
        
        default:
        printf("Invalid input.");
            break;
        }
        break;
        
     case 2:
        printf("You selected triangle \n");
        printf("What do you want to calculate? \n 1.Area? \n 2.Perimeter? \n");
        scanf("%d", &calculation);
        switch (calculation)
        {
        case 1:
            printf("You selected Area. \n");
            printf("Enter value for side 1 of triangle in inch:");
            scanf("%d",&a);
            printf("Enter value for side 2 of triangle in inch:");
            scanf("%d",&b);


            area = (float) 0.5* a * b;
            printf("The area of triangle is %.2f inches.", area); 

            break;
        case 2:
            printf("You selected perimeter. \n");
            printf("Enter value for side 1 of triangle in inch:");
            scanf("%d",&a);
            printf("Enter value for side 2 of triangle in inch:");
            scanf("%d",&b);
            printf("Enter value for side 3 of triangle in inch:");
            scanf("%d",&c);

            perimeter = (float)a + b + c;
            printf("The perimeter of triangle is %.2f inches.", perimeter); 

            break;
        
        default:
        printf("Invalid input.");
            break;
        }
        break;
    case 3:
        printf("You selected rectangle \n");
        printf("What do you want to calculate? \n 1.Area? \n 2.Perimeter? \n");
        scanf("%d", &calculation);
        switch (calculation)
        {
        case 1:
            printf("You selected Area. \n");
            printf("Enter value for length in inch:");
            scanf("%d",&a);
            printf("Enter value for height in inch:");
            scanf("%d",&b);

            area = (float)a*b;
            printf("The area of rectangle is %.2f inches squared.", area); 

            break;
        case 2:
            printf("You selected perimeter. \n");
            printf("Enter value for length in inch:");
            scanf("%d",&a);
            printf("Enter value for height in inch:");
            scanf("%d",&b);

            perimeter = (float)2*(a + b);
            printf("The perimeter of rectangle is %.2f inches.", perimeter); 

            break;
        
        default:
        printf("Invalid input.");
            break;
        }
        break;
    
    default:
    printf("Invalid shape.");
        break;
    }

    return 0;
}
