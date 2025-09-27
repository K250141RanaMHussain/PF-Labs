#include<stdio.h>

int main(){
    int Category, fastfood, drink;

    printf("\"Online Food Ordering System\" \n");
    printf("Select category \n");
    printf("Enter 1 for Fast Food \n");
    printf("Enter 2 for Drinks \n");
    scanf("%d", &Category);

    switch(Category){
        case 1:
        printf("You selected Fast Food. \n");
        printf("Enter number for food you want to order. \n");
        printf("1 for zinger burger \n");
        printf("2 for Club Sandwich \n");
        printf("3 for qtr broast leg \n");
        printf("4 for qtr broast chest \n");
        printf("5 for chicken burger \n");
        scanf("%d", &fastfood);
         switch (fastfood)
        {
        case 1:
            printf("You ordered zinger burger.");
            break;
        case 2:
            printf("You ordered club sandwich.");
            break;
        case 3:
            printf("You ordered qtr broast leg.");
            break;
        case 4:
           printf("You ordered qtr broast chest.");
            break;
        case 5:
            printf("You ordered chicken burger.");
            break;
        
        default:
        printf("Invalid number.");
            break;
        }
        break;
        case 2:
        printf("You selected Drinks. \n");
        printf("Enter number for drink you want to order. \n");
        printf("1 for pepsi \n");
        printf("2 for coca cola \n");
        printf("3 for seven up \n");
        printf("4 for sprite \n");
        printf("5 for dew \n");
        scanf("%d", &drink);
        switch (drink)
        {
        case 1:
            printf("You ordered pepsi.");
            break;
        case 2:
            printf("You ordered coca cola.");
            break;
        case 3:
            printf("You ordered seven up.");
            break;
        case 4:
            printf("You ordered sprite.");
            break;
        case 5:
            printf("You ordered dew.");
            break;
        
        default:
        printf("Invalid number");
            break;
        }
        break;
        default:
        printf("Invalid Category.");
    }
    return 0;
}