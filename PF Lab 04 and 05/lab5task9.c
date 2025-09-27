#include <stdio.h>

int main() {
    int department, course;
    
    printf("=== UNIVERSITY COURSE REGISTRATION SYSTEM ===\n\n");
    printf("Select your department:\n");
    printf("1. Computer Science (CS)\n");
    printf("2. Electrical Engineering (EE)\n");
    printf("3. Business Administration (BBA)\n");
    printf("Enter your choice: ");
    scanf("%d", &department);
    
    switch(department) {
        case 1:
            printf("\n You selected: Computer Science Department\n");
            printf("\nAvailable CS Courses:\n");
            printf("1. Programming Fundamentals\n");
            printf("2. Data Structures and Algorithms\n");
            printf("3. Calculus and analytical geometry\n");
            printf("4. Computer Networks\n");
            printf("5. Artificial Intelligence\n");
            printf("Select a course: ");
            scanf("%d", &course);
            
            switch(course) {
                case 1:
                    printf("\n Registration Successful!\n");
                    printf("Course: Programming Fundamentals\n");
                    break;
                case 2:
                    printf("\n Registration Successful!\n");
                    printf("Course: Data Structures and Algorithms\n");
                    break;
                case 3:
                    printf("\nRegistration Successful!\n");
                    printf("Course: Calculus and analytical geometry\n");
                    break;
                case 4:
                    printf("\n Registration Successful!\n");
                    printf("Course: Computer Networks\n");
                    break;
                case 5:
                    printf("\n Registration Successful!\n");
                    printf("Course: Artificial Intelligence\n");
                    break;
                default:
                    printf("\n Invalid course selection!\n");
                    break;
            }
            break;
            
        case 2:
            printf("\n You selected: Electrical Engineering Department\n");
            printf("\nAvailable EE Courses:\n");
            printf("1. Circuit Analysis\n");
            printf("2. Digital Electronics\n");
            printf("3. Power Systems\n");
            printf("4. Control Systems\n");
            printf("5. Signal Processing\n");
            printf("Select a course (1-5): ");
            scanf("%d", &course);
            
            switch(course) {
                case 1:
                    printf("\n Registration Successful!\n");
                    printf("Course: Circuit Analysis\n");
                    break;
                case 2:
                    printf("\n Registration Successful!\n");
                    printf("Course: Digital Electronics\n");
                    break;
                case 3:
                    printf("\n Registration Successful!\n");
                    printf("Course: Power Systems\n");
                    break;
                case 4:
                    printf("\n Registration Successful!\n");
                    printf("Course: Control Systems\n");
                    break;
                case 5:
                    printf("\n Registration Successful!\n");
                    printf("Course: Signal Processing\n");
                    break;
                default:
                    printf("\nInvalid course selection!\n");
                    break;
            }
            break;
            
        case 3:
            printf("\n You selected: Business Administration Department\n");
            printf("\nAvailable BBA Courses:\n");
            printf("1. Principles of Management\n");
            printf("2. Financial Accounting\n");
            printf("3. Marketing Management\n");
            printf("4. Business Statistics\n");
            printf("5. Organizational Behavior\n");
            printf("Select a course: ");
            scanf("%d", &course);
            
            switch(course) {
                case 1:
                    printf("\n Registration Successful!\n");
                    printf("Course: Principles of Management\n");
                    break;
                case 2:
                    printf("\n Registration Successful!\n");
                    printf("Course: Financial Accounting\n");
                    break;
                case 3:
                    printf("\n Registration Successful!\n");
                    printf("Course: Marketing Management\n");
                    break;
                case 4:
                    printf("\n Registration Successful!\n");
                    printf("Course: Business Statistics\n");
                    break;
                case 5:
                    printf("\n Registration Successful!\n");
                    printf("Course: Organizational Behavior\n");
                    break;
                default:
                    printf("\n Invalid course selection!\n");
                    break;
            }
            break;
            
        default:
            printf("\n Invalid department selection!\n");
            break;
    }
    
    printf("\nThank you for using the Course Registration System!\n");
    return 0;
}