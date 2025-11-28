#include <stdio.h>
#include <string.h>

void reverse(char w[], int i){
    if(i < 0) return;
    printf("%c", w[i]);
    reverse(w, i-1);
}

int isPalindrome(char w[], int i, int j){
    if(i >= j) return 1;
    if(w[i] != w[j]) return 0;
    return isPalindrome(w, i+1, j-1);
}

int main(){
    char w[50];
    
    printf("Enter a word: ");
    scanf("%s", w);

    printf("Reversed: ");
    reverse(w, strlen(w)-1);

    if(isPalindrome(w, 0, strlen(w)-1))
        printf("\nIt is a palindrome\n");
    else
        printf("\nIt is NOT a palindrome\n");

    return 0;
}

