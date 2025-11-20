#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECIPES 40
#define MAX_LEN 200   // enough for long recipe names

int loadRecipes(char recipes[][MAX_LEN]);
void saveRecipes(char recipes[][MAX_LEN], int count);
void sortRecipes(char recipes[][MAX_LEN], int count);
void addRecipe(char recipes[][MAX_LEN], int *count);
void modifyRecipe(char recipes[][MAX_LEN], int count);
void deleteRecipe(char recipes[][MAX_LEN], int *count);
void searchRecipe(char recipes[][MAX_LEN], int count);

int main() {
    char recipes[MAX_RECIPES][MAX_LEN];
    int count = loadRecipes(recipes);

    printf("Loaded %d recipes.\n", count);

    while (1) {
        printf("\n--- Cooking Assistant Recipe Manager ---\n");
        printf("1. Add Recipe\n");
        printf("2. Modify Recipe\n");
        printf("3. Delete Recipe\n");
        printf("4. Search Recipe\n");
        printf("5. Exit\n");
        printf("Choose: ");

        char choiceStr[10];
        fgets(choiceStr, 10, stdin);

        if (strcmp(choiceStr, "-1\n") == 0) {
            break;
        }

        int choice = atoi(choiceStr);

        switch (choice) {
            case 1: addRecipe(recipes, &count); break;
            case 2: modifyRecipe(recipes, count); break;
            case 3: deleteRecipe(recipes, &count); break;
            case 4: searchRecipe(recipes, count); break;
            case 5: goto exit_program;
            default: printf("Invalid choice.\n");
        }
    }

exit_program:
    sortRecipes(recipes, count);
    saveRecipes(recipes, count);
    printf("Recipes saved and sorted. Program ended.\n");
    return 0;
}


// -------------------------------------------------------------
// Load recipes from recipes.txt
// -------------------------------------------------------------
int loadRecipes(char recipes[][MAX_LEN]) {
    FILE *file = fopen("recipes.txt", "r");
    if (!file) return 0;

    int count = 0;
    while (count < MAX_RECIPES && fgets(recipes[count], MAX_LEN, file)) {
        recipes[count][strcspn(recipes[count], "\n")] = '\0';
        count++;
    }
    fclose(file);
    return count;
}


// -------------------------------------------------------------
// Save recipes back to file
// -------------------------------------------------------------
void saveRecipes(char recipes[][MAX_LEN], int count) {
    FILE *file = fopen("recipes.txt", "w");
    if (!file) {
        printf("Error writing to file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
        fprintf(file, "%s\n", recipes[i]);

    fclose(file);
}


// -------------------------------------------------------------
// Sort recipes alphabetically
// -------------------------------------------------------------
void sortRecipes(char recipes[][MAX_LEN], int count) {
    char temp[MAX_LEN];

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(recipes[i], recipes[j]) > 0) {
                strcpy(temp, recipes[i]);
                strcpy(recipes[i], recipes[j]);
                strcpy(recipes[j], temp);
            }
        }
    }
}


// -------------------------------------------------------------
// Add a new recipe
// -------------------------------------------------------------
void addRecipe(char recipes[][MAX_LEN], int *count) {
    if (*count >= MAX_RECIPES) {
        printf("Cannot add more recipes.\n");
        return;
    }

    char input[MAX_LEN];
    printf("Enter new recipe name: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0';

    strcpy(recipes[*count], input);
    (*count)++;

    printf("Recipe added.\n");
}


// -------------------------------------------------------------
// Modify existing recipe
// -------------------------------------------------------------
void modifyRecipe(char recipes[][MAX_LEN], int count) {
    char oldName[MAX_LEN];
    printf("Enter recipe name to modify: ");
    fgets(oldName, MAX_LEN, stdin);
    oldName[strcspn(oldName, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(recipes[i], oldName) == 0) {
            char newName[MAX_LEN];
            printf("Enter new recipe name: ");
            fgets(newName, MAX_LEN, stdin);
            newName[strcspn(newName, "\n")] = '\0';

            strcpy(recipes[i], newName);
            printf("Recipe updated.\n");
            return;
        }
    }

    printf("Recipe not found.\n");
}


// -------------------------------------------------------------
// Delete a recipe
// -------------------------------------------------------------
void deleteRecipe(char recipes[][MAX_LEN], int *count) {
    char name[MAX_LEN];
    printf("Enter recipe to delete: ");
    fgets(name, MAX_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < *count; i++) {
        if (strcmp(recipes[i], name) == 0) {

            for (int j = i; j < *count - 1; j++) {
                strcpy(recipes[j], recipes[j + 1]);
            }

            (*count)--;
            printf("Recipe deleted.\n");
            return;
        }
    }

    printf("Recipe not found.\n");
}


// -------------------------------------------------------------
// Search (partial or full match)
// -------------------------------------------------------------
void searchRecipe(char recipes[][MAX_LEN], int count) {
    char key[MAX_LEN];
    printf("Enter search text: ");
    fgets(key, MAX_LEN, stdin);
    key[strcspn(key, "\n")] = '\0';

    printf("\nMatching recipes:\n");

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(recipes[i], key) != NULL) {  // partial match allowed
            printf("- %s\n", recipes[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No matches found.\n");
}
