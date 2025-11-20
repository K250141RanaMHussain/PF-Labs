#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOTES 100
#define NOTE_LENGTH 100

int loadNotes(char notes[][NOTE_LENGTH]);
void saveNotes(char notes[][NOTE_LENGTH], int count);
void displayNotes(char notes[][NOTE_LENGTH], int count);
void addNote(char notes[][NOTE_LENGTH], int *count);
void removeNote(char notes[][NOTE_LENGTH], int *count);
void editNote(char notes[][NOTE_LENGTH], int count);
void searchNote(char notes[][NOTE_LENGTH], int count);
void countWordInNotes(char notes[][NOTE_LENGTH], int count, const char *word);

int main() {
    char notes[MAX_NOTES][NOTE_LENGTH];
    int count = loadNotes(notes);
    int choice;
    char word[NOTE_LENGTH];

    do {
        printf("\n--- Podcast Notes Manager ---\n");
        printf("1. Display all notes\n");
        printf("2. Add a new note\n");
        printf("3. Remove a note\n");
        printf("4. Edit a note\n");
        printf("5. Search for a note\n");
        printf("6. Count specific word in all notes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) {
            case 1: displayNotes(notes, count); break;
            case 2: addNote(notes, &count); break;
            case 3: removeNote(notes, &count); break;
            case 4: editNote(notes, count); break;
            case 5: searchNote(notes, count); break;
            case 6: 
                printf("Enter the word to count: ");
                fgets(word, NOTE_LENGTH, stdin);
                char *ptr = word;
                while(*ptr) { if(*ptr=='\n') *ptr='\0'; ptr++; }
                countWordInNotes(notes, count, word); 
                break;
            case 0: saveNotes(notes, count); printf("Notes saved. Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while(choice != 0);

    return 0;
}

int loadNotes(char notes[][NOTE_LENGTH]) {
    FILE *fp = fopen("episodes.txt", "r");
    int count = 0;
    if(fp == NULL) {
        printf("No existing notes found. Starting fresh.\n");
        return 0;
    }
    while(fgets(notes[count], NOTE_LENGTH, fp) != NULL) {
        char *ptr = notes[count];
        while(*ptr) { if(*ptr == '\n') *ptr = '\0'; ptr++; }
        count++;
        if(count >= MAX_NOTES) break;
    }
    fclose(fp);
    return count;
}

void saveNotes(char notes[][NOTE_LENGTH], int count) {
    FILE *fp = fopen("episodes.txt", "w");
    if(fp == NULL) {
        printf("Error saving notes!\n");
        return;
    }
    for(int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", notes[i]);
    }
    fclose(fp);
}

void displayNotes(char notes[][NOTE_LENGTH], int count) {
    if(count == 0) { printf("No notes available.\n"); return; }
    printf("\nAll Notes:\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s\n", i+1, notes[i]);
    }
}

void addNote(char notes[][NOTE_LENGTH], int *count) {
    if(*count >= MAX_NOTES) { printf("Note list is full!\n"); return; }
    printf("Enter new note title: ");
    fgets(notes[*count], NOTE_LENGTH, stdin);
    char *ptr = notes[*count];
    while(*ptr) { if(*ptr=='\n') *ptr='\0'; ptr++; }
    (*count)++;
    printf("Note added successfully.\n");
}

void removeNote(char notes[][NOTE_LENGTH], int *count) {
    int idx;
    displayNotes(notes, *count);
    if(*count == 0) return;
    printf("Enter note number to remove: ");
    scanf("%d", &idx);
    getchar();
    if(idx < 1 || idx > *count) { printf("Invalid index!\n"); return; }
    char (*ptr)[NOTE_LENGTH] = notes + idx - 1;
    for(int i = idx-1; i < *count-1; i++) {
        strcpy(*(notes + i), *(notes + i + 1));
    }
    (*count)--;
    printf("Note removed successfully.\n");
}

void editNote(char notes[][NOTE_LENGTH], int count) {
    int idx;
    displayNotes(notes, count);
    if(count == 0) return;
    printf("Enter note number to edit: ");
    scanf("%d", &idx);
    getchar();
    if(idx < 1 || idx > count) { printf("Invalid index!\n"); return; }
    printf("Enter new title: ");
    fgets(notes[idx-1], NOTE_LENGTH, stdin);
    char *ptr = notes[idx-1];
    while(*ptr) { if(*ptr=='\n') *ptr='\0'; ptr++; }
    printf("Note updated successfully.\n");
}

void searchNote(char notes[][NOTE_LENGTH], int count) {
    char keyword[NOTE_LENGTH];
    printf("Enter keyword to search: ");
    fgets(keyword, NOTE_LENGTH, stdin);
    char *kptr = keyword;
    while(*kptr) { if(*kptr=='\n') *kptr='\0'; kptr++; }

    int found = 0;
    for(int i = 0; i < count; i++) {
        char *ptr = notes[i];
        if(strstr(ptr, keyword) != NULL) {
            printf("%d. %s\n", i+1, notes[i]);
            found = 1;
        }
    }
    if(!found) printf("No notes found with keyword '%s'.\n", keyword);
}

void countWordInNotes(char notes[][NOTE_LENGTH], int count, const char *word) {
    int total = 0;
    for(int i = 0; i < count; i++) {
        char *ptr = notes[i];
        while(*ptr) {
            // Skip non-alphabetic characters
            while(*ptr && !isalpha(*ptr)) ptr++;
            if(!*ptr) break;
            // Start of word
            char buffer[NOTE_LENGTH];
            int j = 0;
            while(*ptr && isalpha(*ptr)) {
                buffer[j++] = *ptr;
                ptr++;
            }
            buffer[j] = '\0';
            if(strcmp(buffer, word) == 0) total++;
        }
    }
    printf("The word '%s' appears %d time(s) across all notes.\n", word, total);
}
