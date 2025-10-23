int main() {
    int i;
    int length = 23;
    float total = 0, average;
    
	printf("energy consumed per each hour for a day(in watts). \n");
    float usage[24]={23,12,27,24,12,23,15,23,12,32,42,16,28,31,27,17,19,16,28,31,27,17,19};
	for(i = 0; i < length; i++) {
        printf("%.0f\n", usage[i]);
    }
    
    for(i = 0; i < 24; i++) {
        total = total + usage[i]; // accumulate sum
    }

    average = total / 24;

    printf("\nTotal power usage: %.2f watts\n", total);
    printf("Average hourly usage: %.2f watts\n", average);

    return 0;
}
