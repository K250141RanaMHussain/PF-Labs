#include <stdio.h>

void countdown(int days){
    if(days < 0) return;
    printf("%d\n", days);
    countdown(days - 1);
}

int main(){
    int n;
    printf("Enter number of events: ");
    scanf("%d", &n);

    int days[n];

    for(int i=0; i<n; i++){
        printf("Enter days remaining for Event %d: ", i+1);
        scanf("%d", &days[i]);
    }

    for(int i=0; i<n; i++){
        printf("\nCountdown for Event %d:\n", i+1);
        countdown(days[i]);
    }

    return 0;
}

