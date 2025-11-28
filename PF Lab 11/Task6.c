#include <stdio.h>
#include <string.h>

struct Item {
    char name[50];
    char category[50];
    int quantity;
};

int main(){
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    struct Item *ptr = items;

    for(int i=0; i<n; i++){
        printf("\nItem %d name: ", i+1);
        scanf("%s", (ptr+i)->name);
        printf("Category: ");
        scanf("%s", (ptr+i)->category);
        printf("Quantity: ");
        scanf("%d", &(ptr+i)->quantity);
    }

    char searchCat[50];
    int minQty;

    printf("\nEnter category to filter: ");
    scanf("%s", searchCat);
    printf("Enter minimum quantity: ");
    scanf("%d", &minQty);

    printf("\nFiltered items:\n");
    for(int i=0; i<n; i++){
        if(strcmp((ptr+i)->category, searchCat) == 0 || (ptr+i)->quantity >= minQty){
            printf("%s (%s) Qty: %d\n",
                   (ptr+i)->name, (ptr+i)->category, (ptr+i)->quantity);
        }
    }

    return 0;
}

