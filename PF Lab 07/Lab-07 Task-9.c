
#include <stdio.h>
int main(int argc, const char * argv[])
{
	int m,s;
    char ch;
    char arr[100],largestword[100]="";
    int i=0,j=0,k=0,wordlength=0,largestlength=0,start=0;
    printf("Enter the Words :");
    while (1)
    {
        ch = getchar();
        if (ch=='\n')
        {
            break;
        }
        arr[i] = ch;
        i++;
    }
    arr[i]='\0';
    while (arr[j]!='\0')
    {
        if (arr[j]==' ' || arr[j]==',' || arr[j]=='.' || arr[j]=='\t')
        {
            if (wordlength>0)
            {
                printf("Word:\"");
                for ( m =start; m<start+wordlength; m++)
                {
                    printf("%c",arr[m]);
                }
                printf("\",Length  : %d\n",wordlength);
                if (wordlength>largestlength)
                {
                    largestlength=wordlength;
                    k=0;
                    for ( m=start; m<start+wordlength; m++)
                    {
                        largestword[k]=arr[m];
                        k++;
                    }
                    largestword[k]='\0';
                }
            }
            wordlength=0;
            start=j+1;
        }
        else
        {
            wordlength++;
        }
        j++;
    }
    if (wordlength>0)
    {
        printf("Word: \"");
                for (s = start; s < start + wordlength; s++) {
                    printf("%c", arr[s]);
                }
                printf("\", Length: %d\n", wordlength);
        if (wordlength > largestlength) {
            largestlength = wordlength;
            int k = 0;
            for ( j = start; j < start + wordlength; j++) {
                largestword[k] = arr[j];
                k++;
            }
            largestword[k] = '\0';
        }
        
    }
    printf("-----------------------------------------\n");
        printf("Largest Word Found: \"%s\"\n", largestword);
        printf("Largest Length: %d\n", largestlength);
}

