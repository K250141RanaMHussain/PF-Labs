#include <stdio.h>

int sum(int arr[], int size){
    if(size == 0) return 0;
    return arr[size-1] + sum(arr, size-1);
}

int main(){
    int teams, rounds;

    printf("Enter number of teams: ");
    scanf("%d", &teams);

    printf("Enter number of rounds: ");
    scanf("%d", &rounds);

    int scores[teams][rounds];

    for(int t=0; t<teams; t++){
        printf("\nEnter scores for Team %d:\n", t+1);
        for(int r=0; r<rounds; r++){
            scanf("%d", &scores[t][r]);
        }
    }

    int threshold;
    printf("\nEnter score threshold: ");
    scanf("%d", &threshold);

    for(int t=0; t<teams; t++){
        int total = sum(scores[t], rounds);
        printf("Team %d Total = %d", t+1, total);

        if(total >= threshold) printf("  (Above Threshold)");
        printf("\n");
    }

    return 0;
}

