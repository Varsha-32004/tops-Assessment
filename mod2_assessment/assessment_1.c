#include<stdio.h>
#include<string.h>
// Function to reverse a string
void reverce(char s1[])
{
    int lenth=strlen(s1);
    for(int i=0;i<lenth/2;i++)
    {
        char temp=s1[i];
        s1[i]=s1[lenth-i-1];
        s1[lenth-i-1]=temp;
    }
    printf("\n Reversed string is=%s",s1);
}

// Function for concatenating two strings
void concatenate(char s2[],char s3[])
{
    strcat(s2,s3);
    printf("\n concatenate string is=%s",s2);
}


// Function to check if a string is palindrome
int palindrome(char s1[])
{
    int lenth=strlen(s1);
    for(int i = 0;i < lenth/2 ; i++)
    {
        if (s1[i] != s1[lenth-i-1])
        {
            return 0;
        }
    }
    return 1;
}

// Function to copy a string
void copy(char s2[],char s3[])
{
    strcpy(s3,s2);
    printf("\n Copy string=%s\n",s2);
}

// Function to find the length of a string
int length(char s1[])
{
    return  strlen(s1);
}

// Function to find the frequency of a character in a string
void frequency(char s1[], char ch)
{
    int count=0;
    for(int i=0;i<strlen(s1);i++)
    {
        if(s1[i] == ch)
        {
            count++;
        }
    }
    printf("\ncharacter '%c' appears %d time is  the string.\n",ch,count);
}

// Function to find number of vowels and consonants
void  vowelsandconsonants(char s1[])
{
    int vowels=0,cons=0;
       for(int i=0;i<strlen(s1);i++)
       {   
            char ch = s1[i];
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
                ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            {
                    vowels++;
            }
            else if((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z'))
            {
                    cons++;
            }
            
        
       }
    printf("\n Vowels=%d , consonants=%d\n",vowels,cons);
}

// Function to find number of blank spaces and digits
void spacesanddigits(char s1[])
{
    int spaces=0 , digits=0;
    for(int i =0;i < strlen(s1);i++)
    {
        if(s1[i] == ' ')
        {
            spaces++;
        }
        else if(s1[i] >= '0' && s1[i] <= '9')
        {
            digits++;
        }
    }
    printf("\n Blank space = %d , digits = %d \n ",spaces,digits);
}


int main()
{
    char s1[200],s2[200],ch;
    int choice;
    

    do
    {
        printf("\n Choice your Operation=\n");
        printf("1.reverse a string .\n");
        printf("2.Concatenation string.\n");
        printf("3.Palindrome.\n ");
        printf("4.Copy  a string.\n ");
        printf("5.Length of the string.\n ");
        printf("6.Frequency of character in s string.\n  ");
        printf("7.Count number of vowels and consonants.\n  ");
        printf("8.Count number of blank spaces and digits.\n");
        printf("9.End");


        // Taking user input for operation choice
        printf("\n Enter your choice(1 to 9)=");
        scanf("%d", &choice);
        getchar();

         // Performing the selected operation
        switch (choice)
        {
        case 1:
            printf("\n Enter the string to reverse=");
            fgets(s1,sizeof(s1),stdin);
            s1[strcspn(s1,"\n")] = '\0';   // Remove newline character
            reverce( s1);
            break;
        case 2:
            printf("\n Enter the first string to concatenate=");
            fgets(s1,sizeof(s1),stdin);
            s1[strcspn(s1,"\n")] = '\0';
            printf("\nEnter the second string to concatenate=");
            fgets(s2,sizeof(s2),stdin);
            s2[strcspn(s2,"\n")] = '\0';
            concatenate( s2, s1);
            break;
        case 3:
            printf("\n Enter the first string to check palindrome=");
            fgets(s1,sizeof(s1),stdin);
            s1[strcspn(s1,"\n")] = '\0';
            if(palindrome(s1))
            {
                printf("\n The string is a palindrome \n");
            }
            else
            {
                printf("\n The string is a not Palindrome \n");
            }
            break;
        case 4:
            printf("\n Enter the string to copy=");
            fgets(s2,sizeof(s2),stdin);
            s1[strcspn(s2,"\n")] = '\0';
            copy(s1,s2);
            break;
        case 5:
            printf("\n Enter the first string to find length=");
            fgets(s1,sizeof(s1),stdin);
            s1[strcspn(s1,"\n")] = '\0';
            printf("\n Length of the string=%d \n",length(s1));
            break;
        case 6:
            printf("\n Enter the first string to find frequency=");
            fgets(s1,sizeof(s1),stdin);
            s1[strcspn(s1,"\n")] = '\0';
            printf("\n Enter character to find frequency=");
            scanf("%c", &ch);
            getchar();
            frequency(s1,ch);
            break;
        case 7:
             printf("\n Enter the first string to find vowels and consonants =");
            fgets(s1,sizeof(s1),stdin);
            s1[strcspn(s1,"\n")] = '\0';
            vowelsandconsonants(s1);
            break;
        case 8:
            printf("\n Enter the first string to find spaces and digits =");
            fgets(s1,sizeof(s1),stdin);
            s1[strcspn(s1,"\n")] = '\0';
            spacesanddigits(s1);
            break;
        case 9:
            goto end;  
            break;
        default:
            printf("\n Invalid choice.\n");
        }
        if(choice != 9 )      // Ask user if they want to continue
        {
            printf("\n Do you want to continue ?(y/n): ");
            scanf("%c", &ch);
        }

    }while (ch == 'y' || ch == 'Y');
    
        end:
        printf("Thank you.");
    

    return 0;
}