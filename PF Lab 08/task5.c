#include <stdio.h>

int main() {
    char studentName[5][25];
    int subMarks[5][4];
    float avg[5];
    int highest[4];
    int i, j;

    // Input student names
    printf("Enter names of 5 students:\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d name: ", i + 1);
        scanf("%s", studentName[i]);
    }

    // Input marks for each student
    printf("\nEnter marks of each student (4 subjects):\n");
    for (i = 0; i < 5; i++) {
        printf("\nEnter marks for %s:\n", studentName[i]);
        for (j = 0; j < 4; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%d", &subMarks[i][j]);
        }
    }

    // Calculate average marks of each student
    for (i = 0; i < 5; i++) {
        int sum = 0;
        for (j = 0; j < 4; j++) {
            sum += subMarks[i][j];
        }
        avg[i] = sum / 4.0;
    }

    // Find highest marks in each subject
    for (j = 0; j < 4; j++) {
        highest[j] = subMarks[0][j];
        for (i = 1; i < 5; i++) {
            if (subMarks[i][j] > highest[j]) {
                highest[j] = subMarks[i][j];
            }
        }
    }

    // Display results in matrix format
    printf("\n-------------------------------------------------------------\n");
    printf("Name\tSub1\tSub2\tSub3\tSub4\tAverage\n");
    printf("-------------------------------------------------------------\n");
    for (i = 0; i < 5; i++) {
        printf("%-10s", studentName[i]);  // Left aligned names
        for (j = 0; j < 4; j++) {
            printf("%d\t", subMarks[i][j]);
        }
        printf("%.2f\n", avg[i]);
    }
    printf("-------------------------------------------------------------\n");

    // Display highest marks for each subject
    printf("%-10s", "Highest");
    for (j = 0; j < 4; j++) {
        printf("%d\t", highest[j]);
    }
    printf("\n-------------------------------------------------------------\n");

    return 0;
}

