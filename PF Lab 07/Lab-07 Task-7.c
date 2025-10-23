#include <stdio.h>
int main()
{
    char arr[100];
    int j=0,vow=0,cons=0,k=0;
    printf("Enter the sentence : ");
    scanf("%[^\n]",arr);

    while(arr[j]!='\0')
    {
        if (arr[j]>='A' && arr[j]<='Z')
        {
            arr[j]=arr[j]+32;
        }
        j++;
    }
    while (arr[k]!='\0')
    {
        if (arr[k]=='a' || arr[k]=='e' || arr[k]=='i' || arr[k]=='o' || arr[k]=='u')
        {
            vow++;
        } 
        else if(arr[k]==' ')
		{
		
		}
        else 
        {
            cons++;
        }
        k++;
    }
    printf("In Lower Case : %s\n",arr);
    printf("Totals Vowels = %d\n",vow);
    printf("Total Consonants = %d\n",cons);

}
