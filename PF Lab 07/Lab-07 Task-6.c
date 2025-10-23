#include <stdio.h>
int main(int argc, const char * argv[])
{
	int i,j;
    int arr[7];
    printf("Enter the Array\n");
    for (i=0; i<7; i++)
    {
        printf("Enter element %d:",1+i);
        scanf("%d",&arr[i]);
    }
    int temp=arr[6];
    for (j=7; j>0; j--)
    {
        arr[j]=arr[j-1];
    }
    arr[0]=temp;
    printf("---------------------\n");
    for (i=0; i<7; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    return 0;
}
