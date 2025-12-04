#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int constainsDigit(char *arr){
    while (*arr)
    {
        if (isdigit(*arr))
        {
            return 1;
        }
        arr++;
    }
    return 0;
}

int main(){
    int users;

    printf("Enter Number user :");
    scanf("%d",&users);
    getchar();
    char **arr=calloc(users,sizeof(char*));

    for (int i = 0; i < users; i++)
    {
        arr[i]=calloc(100,sizeof(char));
        printf("Enter username of user %d :",i+1);
        fgets(arr[i],100,stdin);
        arr[i][strcspn(arr[i],"\n")]='\0';
    }

    for (int i = 0; i < users; i++)
    {
        if (!constainsDigit(arr[i]))
        {
            printf("%s\n",arr[i]);
        }
        else{
            free(arr[i]);
            arr[i]=NULL;
        }
        
    }
    
    free(arr);
    return 0;

    
}