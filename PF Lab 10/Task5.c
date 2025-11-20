#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TAGS 100
#define TAG_LENGTH 100

// Function prototypes
int loadTags(char tags[][TAG_LENGTH]);
void saveTags(char tags[][TAG_LENGTH], int count);
void displayTags(char tags[][TAG_LENGTH], int count);
void addTag(char tags[][TAG_LENGTH], int *count);
void deleteTag(char tags[][TAG_LENGTH], int *count);
void updateTag(char tags[][TAG_LENGTH], int count);
void searchTag(char tags[][TAG_LENGTH], int count);

int main() {
    char tags[MAX_TAGS][TAG_LENGTH];
    int count = 0;
    int choice;

    // Load tags from file
    count = loadTags(tags);

    do {
        printf("\n--- Photo Tags Manager ---\n");
        printf("1. Display all tags\n");
        printf("2. Add a new tag\n");
        printf("3. Delete a tag\n");
        printf("4. Update a tag\n");
        printf("5. Search for tags\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        switch(choice) {
            case 1: displayTags(tags, count); break;
            case 2: addTag(tags, &count); break;
            case 3: deleteTag(tags, &count); break;
            case 4: updateTag(tags, count); break;
            case 5: searchTag(tags, count); break;
            case 0: saveTags(tags, count); printf("Changes saved. Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while(choice != 0);

    return 0;
}

// Load tags from file
int loadTags(char tags[][TAG_LENGTH]) {
    FILE *fp = fopen("tags.txt", "r");
    int count = 0;
    if(fp == NULL) {
        printf("No existing tags found. Starting fresh.\n");
        return 0;
    }
    while(fgets(tags[count], TAG_LENGTH, fp) != NULL) {
        // Remove trailing newline
        char *ptr = tags[count];
        while(*ptr) {
            if(*ptr == '\n') *ptr = '\0';
            ptr++;
        }
        count++;
        if(count >= MAX_TAGS) break;
    }
    fclose(fp);
    return count;
}

// Save tags to file
void saveTags(char tags[][TAG_LENGTH], int count) {
    FILE *fp = fopen("tags.txt", "w");
    if(fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for(int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", tags[i]);
    }
    fclose(fp);
}

// Display all tags
void displayTags(char tags[][TAG_LENGTH], int count) {
    if(count == 0) {
        printf("No tags available.\n");
        return;
    }
    printf("\nAll Tags:\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s\n", i+1, tags[i]);
    }
}

// Add a new tag
void addTag(char tags[][TAG_LENGTH], int *count) {
    if(*count >= MAX_TAGS) {
        printf("Tag list is full!\n");
        return;
    }
    printf("Enter new tag: ");
    fgets(tags[*count], TAG_LENGTH, stdin);
    // Remove newline
    char *ptr = tags[*count];
    while(*ptr) {
        if(*ptr == '\n') *ptr = '\0';
        ptr++;
    }
    (*count)++;
    printf("Tag added successfully.\n");
}

// Delete a tag
void deleteTag(char tags[][TAG_LENGTH], int *count) {
    int idx;
    displayTags(tags, *count);
    if(*count == 0) return;
    printf("Enter tag number to delete: ");
    scanf("%d", &idx);
    getchar(); // consume newline
    if(idx < 1 || idx > *count) {
        printf("Invalid index!\n");
        return;
    }
    for(int i = idx-1; i < *count-1; i++) {
        strcpy(tags[i], tags[i+1]);
    }
    (*count)--;
    printf("Tag deleted successfully.\n");
}

// Update a tag
void updateTag(char tags[][TAG_LENGTH], int count) {
    int idx;
    displayTags(tags, count);
    if(count == 0) return;
    printf("Enter tag number to update: ");
    scanf("%d", &idx);
    getchar(); // consume newline
    if(idx < 1 || idx > count) {
        printf("Invalid index!\n");
        return;
    }
    printf("Enter new tag content: ");
    fgets(tags[idx-1], TAG_LENGTH, stdin);
    char *ptr = tags[idx-1];
    while(*ptr) {
        if(*ptr == '\n') *ptr = '\0';
        ptr++;
    }
    printf("Tag updated successfully.\n");
}

void searchTag(char tags[][TAG_LENGTH], int count) {
    char keyword[TAG_LENGTH];
    printf("Enter keyword to search: ");
    fgets(keyword, TAG_LENGTH, stdin);
    char *ptr = keyword;
    while(*ptr) {
        if(*ptr == '\n') *ptr = '\0';
        ptr++;
    }

    int found = 0;
    for(int i = 0; i < count; i++) {
        char *tagPtr = tags[i];
        if(strstr(tagPtr, keyword) != NULL) {
            printf("%d. %s\n", i+1, tags[i]);
            found = 1;
        }
    }
    if(!found) printf("No tags found with keyword '%s'.\n", keyword);
}
