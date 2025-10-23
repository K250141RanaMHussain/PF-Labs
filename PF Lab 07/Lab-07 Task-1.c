#include <stdio.h>

int main() {
    int i;
    int temp[10];
    
    printf("Enter temperature readings for each day 10 times:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &temp[i]);
    }
    
    int max = temp[0];
    int min = temp[0];
    
    // Traverse once to find max and min
    for(i = 1; i < 10; i++) {
        if(temp[i] > max)
            max = temp[i];
        if(temp[i] < min)
            min = temp[i];
    }
    
    printf("\nHottest temperature: %d Celsius\n", max);
    printf("Coldest temperature: %d Celsius\n", min);
    
    return 0;
}
