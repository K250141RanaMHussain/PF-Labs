#include <stdio.h>
#include <string.h>

struct Zodiac {
    char sign[20];
    char luckyColor[20];
    int luckyNumber;
    char advice[200];
};

struct User {
    char name[50];
    int day, month;
    char zodiac[20];
};

void assignZodiac(struct User *u);
void inputUser(struct User *u);
void showForecast(struct User *u, struct Zodiac z[], int zCount);
void updateForecast(struct Zodiac z[], int zCount);

void assignZodiac(struct User *u) {
    int d = u->day, m = u->month;

    if ((m==3 && d>=21) || (m==4 && d<=19)) strcpy(u->zodiac, "Aries");
    else if ((m==4 && d>=20) || (m==5 && d<=20)) strcpy(u->zodiac, "Taurus");
    else if ((m==5 && d>=21) || (m==6 && d<=20)) strcpy(u->zodiac, "Gemini");
    else if ((m==6 && d>=21) || (m==7 && d<=22)) strcpy(u->zodiac, "Cancer");
    else if ((m==7 && d>=23) || (m==8 && d<=22)) strcpy(u->zodiac, "Leo");
    else if ((m==8 && d>=23) || (m==9 && d<=22)) strcpy(u->zodiac, "Virgo");
    else if ((m==9 && d>=23) || (m==10 && d<=22)) strcpy(u->zodiac, "Libra");
    else if ((m==10 && d>=23) || (m==11 && d<=21)) strcpy(u->zodiac, "Scorpio");
    else if ((m==11 && d>=22) || (m==12 && d<=21)) strcpy(u->zodiac, "Sagittarius");
    else if ((m==12 && d>=22) || (m==1 && d<=19)) strcpy(u->zodiac, "Capricorn");
    else if ((m==1 && d>=20) || (m==2 && d<=18)) strcpy(u->zodiac, "Aquarius");
    else if ((m==2 && d>=19) || (m==3 && d<=20)) strcpy(u->zodiac, "Pisces");
    else strcpy(u->zodiac, "Unknown");
}

void inputUser(struct User *u) {
    printf("\nEnter user name: ");
    scanf("%s", u->name);

    printf("Enter birth day: ");
    scanf("%d", &u->day);

    printf("Enter birth month: ");
    scanf("%d", &u->month);

    assignZodiac(u);
}

void showForecast(struct User *u, struct Zodiac z[], int zCount) {
    int found = 0;

    for (int i = 0; i < zCount; i++) {
        if (strcmp(u->zodiac, z[i].sign) == 0) {
            printf("\n----- Horoscope for %s -----\n", u->name);
            printf("Zodiac Sign: %s\n", z[i].sign);
            printf("Lucky Color: %s\n", z[i].luckyColor);
            printf("Lucky Number: %d\n", z[i].luckyNumber);
            printf("Advice: %s\n", z[i].advice);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo forecast available for zodiac sign: %s\n", u->zodiac);
    }
}

void updateForecast(struct Zodiac z[], int zCount) {
    char search[20];
    printf("\nEnter zodiac sign to update: ");
    scanf("%s", search);

    for (int i = 0; i < zCount; i++) {
        if (strcmp(z[i].sign, search) == 0) {
            printf("\nEnter new lucky color: ");
            scanf("%s", z[i].luckyColor);

            printf("Enter new lucky number: ");
            scanf("%d", &z[i].luckyNumber);

            printf("Enter new advice: ");
            scanf(" %[^\n]s", z[i].advice);

            printf("\nForecast updated successfully!\n");
            return;
        }
    }

    printf("\nZodiac sign not found.\n");
}

int main() {
    int userCount, zodiacCount;

    printf("Enter number of users: ");
    scanf("%d", &userCount);

    struct User users[userCount];

    for (int i = 0; i < userCount; i++) {
        printf("\n--- User %d ---\n", i + 1);
        inputUser(&users[i]);
    }

    printf("\nEnter number of zodiac signs to store forecast: ");
    scanf("%d", &zodiacCount);

    struct Zodiac z[zodiacCount];

    for (int i = 0; i < zodiacCount; i++) {
        printf("\n--- Zodiac Entry %d ---\n", i + 1);
        printf("Sign: ");
        scanf("%s", z[i].sign);
        printf("Lucky Color: ");
        scanf("%s", z[i].luckyColor);
        printf("Lucky Number: ");
        scanf("%d", &z[i].luckyNumber);
        printf("Advice: ");
        scanf(" %[^\n]s", z[i].advice);
    }

    int choice;

    while (1) {
        printf("\n\n----------- MENU -----------\n");
        printf("1. Show horoscope for a user\n");
        printf("2. Update zodiac forecast\n");
        printf("3. List all users\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int un;
            printf("Enter user number (1-%d): ", userCount);
            scanf("%d", &un);

            if (un < 1 || un > userCount) {
                printf("Invalid user number.\n");
            } else {
                showForecast(&users[un-1], z, zodiacCount);
            }
        }

        else if (choice == 2) {
            updateForecast(z, zodiacCount);
        }

        else if (choice == 3) {
            printf("\nAll Users:\n");
            for (int i = 0; i < userCount; i++) {
                printf("%d. %s (Zodiac: %s)\n", i+1, users[i].name, users[i].zodiac);
            }
        }

        else if (choice == 4) {
            break;
        }

        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

