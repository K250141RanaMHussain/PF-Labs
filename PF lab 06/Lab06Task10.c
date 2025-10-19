#include<stdio.h>

int main(){
    int num=0;
    printf("Enter number for hollow diamond. \n");
    scanf("%d", &num);

    // For upper side of triangle
    int spacing, x_word, i, j;
    for(spacing=num-1, x_word=1; spacing>=0; spacing--, x_word+=2){
        for(j=0; j<spacing; j++){
            printf(" ");
        }
        for(i=0; i<x_word; i++){
            // Print 'x' only at the edges, spaces in between
            if(i==0 || i==x_word-1)
                printf("x");
            else
                printf(" ");
        }
        for(j=0; j<spacing; j++){
            printf(" ");
        }
        printf("\n");
    }

    // For lower side of triangle 
    for(spacing=1, x_word=x_word-4; spacing<=num-1; spacing++, x_word-=2){
        for(j=0; j<spacing; j++){
            printf(" ");
        }
        for(i=0; i<x_word; i++){
            // Print 'x' only at the edges, spaces in between
            if(i==0 || i==x_word-1)
                printf("x");
            else
                printf(" ");
        }
        for(j=0; j<spacing; j++){
            printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
