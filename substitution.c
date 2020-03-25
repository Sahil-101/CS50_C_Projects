#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(int argc , char* argv[])
{   
    string str;
    int i,j,c,count=0;
    for(i=0; argv[1][i]!='\0'; i++)
    {
        count++;
        
    }
    if(count<26)
    {
        printf("Key must contain 26 letters count is %d", count);
        exit(0);
    }
    
    for(i=0; i<26; i++)
    {
        for(j=i+1; j<26; j++)
        {   
            if(argv[1][i]==argv[1][j])
            {
                printf("entered %c this char 2 times",argv[1][i]);
                return 1;
            }
        }
    }
    str =get_string("Plain text:  ");
    printf("Cipher text:\t\b\b\b");
    for(i=0; i<argc-1; i++)
    {
        for(j=0; str[j]!='\0'; j++)
        {   if(isalpha(str[j]))
            {
                if(((int) str[j]) <= 90)
                {
                    c=((int) str[j]) - 65;
                    printf("%c",argv[1][c]);
                }
                if(((int) str[j])>90)
                {
                    c=((int) str[j])-97;
                    printf("%c",argv[1][c]);
                }
            }
            else
                {
                    printf("%c",str[j]);
                }
        }
        printf("\n");
    }
    return 0;
}