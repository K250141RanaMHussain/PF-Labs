#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SONGS 10
#define MAX_TITLE 100

int loadSongs(char playlist[][MAX_TITLE]);
void saveSongs(char playlist[][MAX_TITLE], int count);
void addSong(char playlist[][MAX_TITLE], int *count);
void deleteSong(char playlist[][MAX_TITLE], int *count);
void updateSong(char playlist[][MAX_TITLE], int count);
void searchSong(char playlist[][MAX_TITLE], int count);
void sortSongs(char playlist[][MAX_TITLE], int count);

int main() {
    char playlist[MAX_SONGS][MAX_TITLE];
    int count = loadSongs(playlist);

    int choice;

    while (1) {
        printf("\n--- Playlist Menu ---\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Update Song\n");
        printf("4. Search Song\n");
        printf("5. Exit (-1)\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        if (choice == -1 || choice == 5) {
            break;
        }

        switch (choice) {
            case 1: addSong(playlist, &count); break;
            case 2: deleteSong(playlist, &count); break;
            case 3: updateSong(playlist, count); break;
            case 4: searchSong(playlist, count); break;
            default: printf("Invalid choice!\n");
        }
    }

    // Sort alphabetically before exiting
    sortSongs(playlist, count);

    // Save updated playlist
    saveSongs(playlist, count);

    printf("\nFinal sorted playlist saved to playlist.txt!\n");

    return 0;
}


int loadSongs(char playlist[][MAX_TITLE]) {
    FILE *file = fopen("playlist.txt", "r");
    int count = 0;

    if (!file) return 0;

    while (count < MAX_SONGS && fgets(playlist[count], MAX_TITLE, file)) {
        playlist[count][strcspn(playlist[count], "\n")] = '\0';
        count++;
    }

    fclose(file);
    return count;
}


void saveSongs(char playlist[][MAX_TITLE], int count) {
    FILE *file = fopen("playlist.txt", "w");
    if (!file) {
        printf("Error saving file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", playlist[i]);
    }

    fclose(file);
}

void addSong(char playlist[][MAX_TITLE], int *count) {
    if (*count >= MAX_SONGS) {
        printf("Playlist full! Cannot add more.\n");
        return;
    }

    printf("Enter new song title: ");
    fgets(playlist[*count], MAX_TITLE, stdin);
    playlist[*count][strcspn(playlist[*count], "\n")] = '\0';

    (*count)++;
    printf("Song added!\n");
}

void deleteSong(char playlist[][MAX_TITLE], int *count) {
    char target[MAX_TITLE];
    printf("Enter song title to delete: ");
    fgets(target, MAX_TITLE, stdin);
    target[strcspn(target, "\n")] = '\0';

    for (int i = 0; i < *count; i++) {
        if (strcmp(target, playlist[i]) == 0) {
            // Shift songs left
            for (int j = i; j < *count - 1; j++) {
                strcpy(playlist[j], playlist[j+1]);
            }
            (*count)--;

            printf("Song deleted!\n");
            return;
        }
    }

    printf("Song not found.\n");
}

void updateSong(char playlist[][MAX_TITLE], int count) {
    char oldTitle[MAX_TITLE];

    printf("Enter song to update: ");
    fgets(oldTitle, MAX_TITLE, stdin);
    oldTitle[strcspn(oldTitle, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(oldTitle, playlist[i]) == 0) {
            printf("Enter new title: ");
            fgets(playlist[i], MAX_TITLE, stdin);
            playlist[i][strcspn(playlist[i], "\n")] = '\0';

            printf("Song updated!\n");
            return;
        }
    }

    printf("Song not found.\n");
}

void searchSong(char playlist[][MAX_TITLE], int count) {
    char target[MAX_TITLE];

    printf("Enter song to search: ");
    fgets(target, MAX_TITLE, stdin);
    target[strcspn(target, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(target, playlist[i]) == 0) {
            printf("Song found at index %d!\n", i);
            return;
        }
    }

    printf("Song not found.\n");
}

void sortSongs(char playlist[][MAX_TITLE], int count) {
    char temp[MAX_TITLE];

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(playlist[i], playlist[j]) > 0) {
                strcpy(temp, playlist[i]);
                strcpy(playlist[i], playlist[j]);
                strcpy(playlist[j], temp);
            }
        }
    }
}
