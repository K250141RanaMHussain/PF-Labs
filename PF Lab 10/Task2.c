#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEVELS 10
#define MAX_DESC 200   // enough for 7 words comfortably

int loadLevels(char levels[][MAX_DESC]);
void saveLevels(char levels[][MAX_DESC], int count);
int countWords(char *str);
void addLevel(char levels[][MAX_DESC], int *count);
void searchLevel(char levels[][MAX_DESC], int count);
void updateLevel(char levels[][MAX_DESC], int count);
void deleteLevel(char levels[][MAX_DESC], int *count);

int main() {
    char levels[MAX_LEVELS][MAX_DESC];
    int count = loadLevels(levels);

    int choice;

    while (1) {
        printf("\n--- Level Manager ---\n");
        printf("1. Add Level\n");
        printf("2. Search Level\n");
        printf("3. Update Level\n");
        printf("4. Delete Level\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addLevel(levels, &count); break;
            case 2: searchLevel(levels, count); break;
            case 3: updateLevel(levels, count); break;
            case 4: deleteLevel(levels, &count); break;
            case 5: saveLevels(levels, count); 
                    printf("All changes saved. Exiting...\n");
                    return 0;
            default: printf("Invalid option.\n");
        }
    }
}


// ---------------------------------------------------------
// Load all levels from levels.txt into array
// ---------------------------------------------------------
int loadLevels(char levels[][MAX_DESC]) {
    FILE *file = fopen("levels.txt", "r");
    if (!file) return 0;

    int count = 0;
    while (count < MAX_LEVELS && fgets(levels[count], MAX_DESC, file)) {
        levels[count][strcspn(levels[count], "\n")] = '\0';
        count++;
    }

    fclose(file);
    return count;
}


// ---------------------------------------------------------
// Save updated levels back to levels.txt
// ---------------------------------------------------------
void saveLevels(char levels[][MAX_DESC], int count) {
    FILE *file = fopen("levels.txt", "w");
    if (!file) {
        printf("Error saving file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", levels[i]);
    }

    fclose(file);
}


// ---------------------------------------------------------
// Count words (to enforce max 7 words)
// ---------------------------------------------------------
int countWords(char *str) {
    int words = 0;
    char temp[300];
    strcpy(temp, str);

    char *token = strtok(temp, " ");
    while (token != NULL) {
        words++;
        token = strtok(NULL, " ");
    }

    return words;
}


void addLevel(char levels[][MAX_DESC], int *count) {
    if (*count == MAX_LEVELS) {
        printf("Cannot add more levels. Maximum reached.\n");
        return;
    }

    char input[MAX_DESC];
    printf("Enter new level description (max 7 words):\n");
    fgets(input, MAX_DESC, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (countWords(input) > 7) {
        printf("Error: Level description must be no more than 7 words.\n");
        return;
    }

    strcpy(levels[*count], input);
    (*count)++;

    printf("Level added.\n");
}

void searchLevel(char levels[][MAX_DESC], int count) {
    char search[MAX_DESC];
    printf("Enter level to search: ");
    fgets(search, MAX_DESC, stdin);
    search[strcspn(search, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(levels[i], search) == 0) {
            printf("Level found at index %d.\n", i);
            return;
        }
    }

    printf("Level not found.\n");
}


void updateLevel(char levels[][MAX_DESC], int count) {
    char oldDesc[MAX_DESC];
    printf("Enter level description to update: ");
    fgets(oldDesc, MAX_DESC, stdin);
    oldDesc[strcspn(oldDesc, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(levels[i], oldDesc) == 0) {
            char newDesc[MAX_DESC];
            printf("Enter new description (max 7 words):\n");
            fgets(newDesc, MAX_DESC, stdin);
            newDesc[strcspn(newDesc, "\n")] = '\0';

            if (countWords(newDesc) > 7) {
                printf("Error: More than 7 words.\n");
                return;
            }

            strcpy(levels[i], newDesc);
            printf("Level updated.\n");
            return;
        }
    }

    printf("Level not found.\n");
}


void deleteLevel(char levels[][MAX_DESC], int *count) {
    char del[MAX_DESC];
    printf("Enter level to delete: ");
    fgets(del, MAX_DESC, stdin);
    del[strcspn(del, "\n")] = '\0';

    for (int i = 0; i < *count; i++) {
        if (strcmp(levels[i], del) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(levels[j], levels[j + 1]);
            }
            (*count)--;
            printf("Level deleted.\n");
            return;
        }
    }

    printf("Level not found.\n");
}
