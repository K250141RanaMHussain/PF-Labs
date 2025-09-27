#include<stdio.h>

int main() {
    int age, movie;
    
    printf("====Movie Ticket Booking====\n");
    
    // Get age from user
    printf("Enter your age: ");
    scanf("%d", &age);
    
    // Check age category using if-else
    if(age < 12) {
        printf("Ticket Type: Child Ticket\n");
    }
    else if(age >= 12 && age <= 60) {
        printf("Ticket Type: Adult Ticket\n");
    }
    else {
        printf("Ticket Type: Senior Citizen Ticket\n");
    }
    
    // Movie selection
    printf("\nSelect Movie Type:\n");
    printf("1. Action Movie\n");
    printf("2. Comedy Movie\n");
    printf("3. Horror Movie\n");
    printf("Enter number for the movie type above: ");
    scanf("%d", &movie);
    
    // Use switch-case for movie selection
    switch(movie) {
        case 1:
            printf("Action movie is booked.\n");
            break;
        case 2:
            printf("Comedy movie is booked.\n");
            break;
        case 3:
            printf("Horrow movie is booked.\n");
            break;
        default:
            printf("Invalid movie selection!\n");
            break;
    }
    
    printf("\nThank you for booking!\n");
    
    return 0;
}