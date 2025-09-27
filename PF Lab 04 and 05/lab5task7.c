#include <stdio.h>
#include <string.h>

int main() {
    char user[50];
    char password[50];
    
    printf("=== LOGIN SYSTEM ===\n");
    
    printf("Enter username: ");
    scanf("%s", user);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    printf("\n");
    
    if (strcmp(user, "admin") == 0) {
        if (strcmp(password, "1234") == 0) {
            printf("Login Successful!\n");
            printf("Welcome, admin!\n");
        } else {
            printf("Login Failed.\n");
            printf("Error: Incorrect password.\n");
        }
    } else {
        printf("Login Failed.\n");
        printf("Error: Username not found.\n");
    }
    
    return 0;
}