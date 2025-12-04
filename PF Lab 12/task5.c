#include <stdio.h>
#include <stdlib.h>
int main(){
    int category;
    float total=0.0;
    int low,ind=1;
    char choice;

    printf("Enter catogry of movie:");
    scanf("%d",&category);

    int *arr=calloc(category,sizeof(int));

    for (int i = 0; i < category; i++)
    {
        printf("Enter rating count for category %d :",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Do you want to update category? (y/n)\n");
    scanf(" %c",&choice);
    while (choice=='y'||choice=='Y'){
        int updCat,newStock;
        printf("Enter category to update : ");
        scanf("%d",&updCat);

        if (updCat<1||updCat>category)
        {
            printf("Invalid category!");
        }
        else{
            printf("Enter new rating :");
            scanf("%d",&newStock);

            arr[updCat-1]=newStock;
        }        
        printf("Do you want to update category? (y/n)\n");
        scanf(" %c",&choice);
    }
    


    for (int i = 0; i < category; i++)
    {
        total+=arr[i];
    }
    low=arr[0];
    for (int i = 0; i < category; i++)
    {
        if(arr[i]>low){
            low=arr[i];
            ind=i+1;
        }
    }

    printf("The Total rating is = %.2f\n",total);
    printf("The averege rating is = %.2f\n",total/category);
    printf("The highest rating of index %d is %d\n",ind,low);
    
    free(arr);
    return 0;
}