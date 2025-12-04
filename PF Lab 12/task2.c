#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of feedback entries: ");
    scanf("%d", &n);
    getchar();  

    char **feedbacks = NULL;

    for (int i = 0; i < n; i++) {

        feedbacks = realloc(feedbacks, (i + 1) * sizeof(char*));
        
        printf("Enter feedback %d: ", i + 1);

        char temp[100];
        fgets(temp, sizeof(temp), stdin);

        int len = 0;
        char *p = temp;
        while (*p != '\0' && *p != '\n') {
            len++;
            p++;
        }

        feedbacks[i] = malloc((len + 1) * sizeof(char));

        for (int j = 0; j < len; j++) {
            feedbacks[i][j] = temp[j];
        }
        feedbacks[i][len] = '\0';
    }

    int totalChars = 0;
    for (int i = 0; i < n; i++) {
        char *p = feedbacks[i];
        while (*p != '\0') {
            totalChars++;
            p++;
        }
    }

    int longestIndex = 0;
    int longestLength = 0;

    for (int i = 0; i < n; i++) {
        int len = 0;
        char *p = feedbacks[i];
        while (*p != '\0') {
            len++;
            p++;
        }
        if (len > longestLength) {
            longestLength = len;
            longestIndex = i;
        }
    }

    printf("\nAll Feedback Entries:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, feedbacks[i]);
    }

    printf("\nTotal characters across all feedback: %d\n", totalChars);
    printf("Longest feedback (%d characters): %s\n", longestLength, feedbacks[longestIndex]);

    for (int i = 0; i < n; i++) {
        free(feedbacks[i]);
    }
    free(feedbacks);

    return 0;
}