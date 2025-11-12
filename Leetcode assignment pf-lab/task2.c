/* ============Transform Array by Parity============ */

#include <stdio.h>
#define maxSize 6

int main(){
    int arr[]={0,1,2,3,4,5};
	int i,j;
    printf("Original Array: \n");
    for ( i = 0; i < maxSize; i++)
    {
        printf("%d ", arr[i]);      
    }
    

    for ( i = 0; i < maxSize; i++)
    {
        if (arr[i]%2==0)
        {
            arr[i]=0;
        }
        else
        {
            arr[i]=1;
        }
    }

    for ( i = 0; i < maxSize - 1; i++) {
        for ( j = i+1; j < maxSize; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nResulting Array: \n");
    for (i = 0; i < maxSize; i++)
    {
        printf("%d ", arr[i]);
    }
    
    
}
