#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    int daysPresent;
};

int totalAttendance(struct Employee e[], int size){
    if(size == 0) return 0;
    return e[size-1].daysPresent + totalAttendance(e, size-1);
}

int main(){
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee e[n];

    for(int i=0; i<n; i++){
        printf("\nEnter employee %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", e[i].name);
        printf("ID: ");
        scanf("%d", &e[i].id);
        printf("Days Present: ");
        scanf("%d", &e[i].daysPresent);
    }

    int minReq;
    printf("\nEnter minimum required days: ");
    scanf("%d", &minReq);

    printf("\nEmployees with low attendance:\n");
    for(int i=0; i<n; i++){
        if(e[i].daysPresent < minReq)
            printf("%s (ID %d)\n", e[i].name, e[i].id);
    }

    printf("\nTotal Attendance = %d\n", totalAttendance(e, n));

    return 0;
}

