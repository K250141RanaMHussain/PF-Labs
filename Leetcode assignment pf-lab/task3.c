/*=================Array Shuffling Program====================*/

#include <stdio.h>

int main() {
    int nums[] = {2,5,1,3,4,7};
    int n = 3;
    int result[6];
	int i,j=0; 

    for ( i = 0; i < n; i++) {
        result[j++] = nums[i];    
        result[j++] = nums[i + n]; 
    }

    printf("Output: [");
    for ( i = 0; i < 6; i++) {
        printf("%d", result[i]);
        if (i < 5) printf(",");
    }
    printf("]\n");

    return 0;
}
