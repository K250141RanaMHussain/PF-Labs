#include <stdio.h>

void updateValue(int num);

void updateReference(int *num);

int main() {
    int value = 80;

    printf("Before updateValue: %d\n", value);
    updateValue(value);
    printf("After updateValue: %d (no change)\n", value);

    printf("\nBefore updateReference: %d\n", value);
    updateReference(&value);
    printf("After updateReference: %d (updated successfully)\n", value);

    return 0;
}

void updateValue(int num) {
    num = num + 5; 
}

void updateReference(int *num) {
    *num = *num + 5; 
}