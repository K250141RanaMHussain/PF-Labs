#include<stdio.h>
int main(){
	int l;
	int arr1[5]={1,3,5,7,9};
    int arr2[5]={2,4,6,8,10};
    printf("Array 1: \n");
    for(l = 0; l < 5; l++) {
        printf("%d ", arr1[l]);
    }printf("\n");
    printf("Array 2: \n");
    for(l = 0; l < 5; l++) {
        printf("%d ", arr2[l]);
    }printf("\n");
    int arr3[10];
    int i, j=0, k=0;
    for(i=0; i<10; i++)
    {
        if(i%2==0)
        {
            arr3[i]=arr1[j];
            j++;
        }
        else
        {
            arr3[i]=arr2[k];
            k++;
        }
    }
    printf("Merged array:\n");
    for(i=0; i<10; i++)
    {
        printf("%d ", arr3[i]);
    }
	return 0;
}
