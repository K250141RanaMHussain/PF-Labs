#include <stdio.h>

void analyzeData(int *arr, int n, int *max, int *min, float *avg);

int main() {
    int data[] = {30, 45, 65, 80, 90};
    int n = 5;
    int max, min;
    float avg;

    analyzeData(data, n, &max, &min, &avg);

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
    printf("Average = %.2f\n", avg);

    return 0;
}

void analyzeData(int *arr, int n, int *max, int *min, float *avg) {
    int sum = 0;
    *max = *min = arr[0]; 
	int i;
    for ( i = 0; i < n; i++) {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
        sum += arr[i];
    }

    *avg = (float)sum / n;  
}
