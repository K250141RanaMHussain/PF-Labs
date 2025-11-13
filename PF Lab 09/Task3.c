#include <stdio.h>

void findRoads(int traffic[], int n, int target);

int main() {
    int n, target;
    printf("\n==============================================\n");
    printf("==The City Traffic Department monitor System==\n");
    printf("==============================================\n\n");
    int i;
    printf("Enter number of roads: ");
    scanf("%d", &n);
    int traffic[n];
    printf("Enter daily vehicle count for each road\n");
    for ( i = 0; i < n; i++) {
        printf("Road %d: ", i+1);
        scanf("%d", &traffic[i]);
    }

    printf("\nEnter target vehicle count: ");
    scanf("%d", &target);

    findRoads(traffic, n, target);

    return 0;
}

void findRoads(int traffic[], int n, int target) {
	int i,j;
    for ( i = 0; i < n; i++) {
        for ( j = i + 1; j < n; j++) {  
            if (traffic[i] + traffic[j] == target) {
                printf("\nRoad %d and Road %d have a combined traffic of %d.\n", i+1, j+1, target);
                return;  
            }
        }
    }
}
