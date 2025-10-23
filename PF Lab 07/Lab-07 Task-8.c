#include <stdio.h>
int main(int argc, const char * argv[]) {
    char arr1[50];
    char arr2[50];
    char ch1,ch2;
    int i=0,j=0,k=0;
    printf("Enter First String : ");
    while (1)
    {
        ch1 = getchar();
        if (ch1=='\n')
        {
            break;
        }
        arr1[i] = ch1;
        i++;
    }
    arr1[i]='\0';
    printf("Enter Second String : ");
    while (1)
    {
        ch2 = getchar();
        if (ch2=='\n')
        {
            break;
        }
        arr2[j] = ch2;
        j++;
    }
    arr2[j]='\0';
    if (i==j)
    {
        for (k=0; k<i; k++)
        {
            if (arr1[k]==arr2[k])
            {
                continue;
            }
            else
            {
                goto xyz;
            }
        }
    }
    else
    {
        xyz:
        printf("Strings are Not same\n");
    }
    if (arr1[k]==arr2[k])
    {
        printf("Strings Are same\n");
    }
    return 0;
}
