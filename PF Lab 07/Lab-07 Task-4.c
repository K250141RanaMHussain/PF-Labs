#include <stdio.h>
int main()
{	
    int i, length = 9, temp;
    int arr[9];
    printf("Input values for each position in array 9 times: \n");
    for(i=0; i< length ; i++){
    	scanf("%d \n", &arr[i]);
	}
    printf("Original array:\n");
    for(i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    for(i = 0; i < length / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
    printf("\nReversed array:\n");
    for(i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
