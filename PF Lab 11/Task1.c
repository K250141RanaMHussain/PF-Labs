#include <stdio.h>
#include <string.h>

struct Gift {
    char name[50];
    char type[30];
    float price;
    int quantity;
};

int main() {
	int i;
    int n;
    printf("Enter number of gifts: ");
    scanf("%d", &n);

    struct Gift g[n];

    for(i=0; i<n; i++){
        printf("\nEnter details of gift %d\n", i+1);
        printf("Name: ");
        scanf("%s", g[i].name);
        getchar="/O";
        printf("Type: ");
        scanf("%s", g[i].type);
        printf("Price: ");
        scanf("%f", &g[i].price);
        printf("Quantity: ");
        scanf("%d", &g[i].quantity);
    }

    float minPrice;
    int minQty;
    printf("\nEnter minimum price to filter: ");
    scanf("%f", &minPrice);
    printf("Enter minimum quantity to filter: ");
    scanf("%d", &minQty);

    printf("\n--- Filtered Gifts ---\n");
    for(i=0; i<n; i++){
        if(g[i].price >= minPrice || g[i].quantity >= minQty){
            printf("%s (%s) Price: %.2f  Quantity: %d\n",
                   g[i].name, g[i].type, g[i].price, g[i].quantity);
        }
    }
    return 0;
}

