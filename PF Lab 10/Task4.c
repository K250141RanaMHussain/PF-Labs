#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define maxaffirm 100
#define length 100

int  loadAffirm( char affirm[][length] ,int *count );
int wordCount(char *affirm);
void addNew(char affirm[][length], int *count);
int searchAffirm(char affirm[][length], int count);
void updateAffirm(char affirm[][length] , int count);
void deleteAffirm(char affirm[][length], int *count);
void save(char affirm[][length], int count);

int main(void)
{
    char affirm[maxaffirm][length];
    int count = 0;
    int choice=0;
    int index=0;
    while (1)
    {
        printf("1. Load Affrimation\n");
        printf("2. Add Affrimation\n");
        printf("3. Update Affrimation\n");
        printf("4. Search Affrimation\n");
        printf("5. Delete Affrimation\n");
        printf("6. Exit \n");
        printf("------------------------------\n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);
        getchar();

        printf("------------------------------\n");
        switch (choice)
        {
        case 1:
            loadAffirm(affirm,&count);
            printf("------------------------------\n");
            break;
        case 2:
            addNew(affirm,&count);
            printf("------------------------------\n");
            break;
        case 3:
            updateAffirm(affirm,count);
            printf("------------------------------\n");
            break;
        case 4:
            index = searchAffirm(affirm,count);
            if (index!=-1)
            {
              printf("Affrimation Found at index %d \n ",index);
              printf("------------------------------\n");
            }
            if (index==-1)
            {
                printf("Affirmation Not Found \n");
                printf("------------------------------\n");
            }
            
            break;
        case 5:
            deleteAffirm(affirm,&count);
            printf("------------------------------\n");
            break;
        case 6:
            save(affirm,count);
            return 0;
        default:
            break;
        }
    }
    
}

int  loadAffirm( char affirm[][length] ,int *count )
{
    FILE *fptr;
    fptr = fopen("affirm.txt","r");
    if (fptr == NULL)
    {
        printf("File Not Found! \n");
        return 0;
    }
    while (*count < maxaffirm && fgets(affirm[*count],length,fptr))
    {
        
        affirm[*count][strcspn(affirm[*count],"\n")]='\0';

        if (strlen(affirm[*count])>0)
        (*count)++;
    }
    fclose(fptr);

    return *count;
    
}




int wordCount(char *str)
{
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && !inWord)
        {
            inWord = 1;
            count++;
        }
        else if (str[i] == ' ')
        {
            inWord = 0;
        }
    }

    return count;
}




void addNew(char affirm[][length], int *count)
{
    if (*count >= maxaffirm)
    {
        printf("List Ful! \n");
        return;
    }
    char name[length];
    printf("Enter A new Phrase: ");
    fgets(name,length,stdin);

    name[strcspn(name,"\n")]='\0';


    if (wordCount(name)>=7)
    {
        printf("Maximum Words limit Exceeded! \n");
        return;
    }

    strcpy(affirm[*count],name);
    (*count)++;
    
    printf("Phrase(Affrimation) Added \n");
}

 


int searchAffirm(char affirm[][length], int count)
{
    char name[length];
    printf("Enter A new Phrase to search : ");
    fgets(name,length,stdin);

    name[strcspn(name,"\n")]='\0';

    for (int  i = 0; i < count; i++)
    {
        if (strcmp(affirm[i],name)==0)
        {
            return i;
        }
        
    }
    return -1;
}



void updateAffirm(char affirm[][length] , int count)
{
    int index = searchAffirm(affirm,count);
    if (index==-1)
    {
        printf("NO such Phrase Found \n");
        return;
    }
    char name[length];
    printf("Enter new affrimation: ");
    fgets(name,length,stdin);

    name[strcspn(name,"\n")]='\0';
    
    if (wordCount(name)>=7)
    {
       printf("Word Limit exceeded \n");
       return;
    }

    strcpy(affirm[index],name);
    printf("Affrimation updated Succesfully \n");
    
}



void deleteAffirm(char affirm[][length], int *count)
{
    int index = searchAffirm(affirm,*count);
    if (index==-1)
    {
        printf("Affrimation not Found to Delete ");
        return;
    }
    for (int  i = index; i < *count-1; i++)
    {
        strcpy(affirm[i],affirm[i+1]);
    }
    
    (*count)--;
    printf("Affrimation Deleted Successfully \n");
}


void save(char affirm[][length], int count)
{
    FILE *fptr;
    fptr = fopen("affirm.txt","w");
    if (fptr==NULL)
    {
        printf("File Not Found! \n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
       for (int j = i+1; j < count; j++)
       {
        if (strcmp(affirm[i],affirm[j])>0)
        {
            char temp[length];
            strcpy(temp,affirm[i]);
            strcpy(affirm[i],affirm[j]);
            strcpy(affirm[j],temp);
        }
        
       }
       
    }
    
    for (int  i = 0; i < count; i++)
    {
        fprintf(fptr,"%s\n",affirm[i]);
    }
    
}