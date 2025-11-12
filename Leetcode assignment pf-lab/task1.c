/* ============Running sum of 1d array============ */

#include <stdio.h>

#define maxSize 6

int main(){
    int nums[maxSize]={0,1,2,3,4,5};
    int runningSum[maxSize];
    int sum=0;
    int i;

    for (i = 0; i < maxSize; i++)
    {
        sum += nums[i];
        runningSum[i] = sum;
    }

    printf("Array after running sum: \n");
    for (i = 0; i < maxSize; i++)
    {
        printf("%d  ", runningSum[i]);
    }
    
    
}
