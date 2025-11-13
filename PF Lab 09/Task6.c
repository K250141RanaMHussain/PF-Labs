#include <stdio.h>
#include <string.h>

char *formatName(char *first, char *last);

int main() {
    char first[50], last[50];

    printf("Enter your first name: ");
    scanf("%s", first);

    printf("Enter your last name: ");
    scanf("%s", last);

    char *fullName = formatName(first, last);
    printf("Your full name is: %s\n", fullName);

    return 0;
}

char *formatName(char *first, char *last) {
    static char fullName[150];  

    strcpy(fullName, first);   
    strcat(fullName, " ");     
    strcat(fullName, last);    

    return fullName;  
}
