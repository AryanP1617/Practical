#include <stdio.h>
#include <string.h>

void computeLPS(char pattern[],int lps[])
{
    int m=strlen(pattern);
    int len=0;
    lps[0]=0;
    int i=1;

    while(i<m)
    {
        if(pattern[len]==pattern[i])
        {
            len++;
            lps[i++]=len;
        }
        else{
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[len]=0;
                i++;
            }
        }
    }
}

void KmpSearch(char pattern[],char text[])
{
    int i=0,j=0;
    int m=strlen(pattern);
    int n=strlen(text);

    int lps[m];
    computeLPS(pattern,lps);

    while(i<n)
    {
        if(pattern[j]==text[i])
        {
            i++;
            j++;
        }

        if(j==m)
        {
            printf("Pattern found at index:%d\n",i-j);
            j=lps[j-1];
        }
        else if(i<n && pattern[j]!=text[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                
                i++;
            }
        }
    }
    
}

int main() {
    char text[100];
    char pattern[100];
        
    printf("Enter the text: ");
    scanf("%s",text);
    printf("Enter the pattern: ");
    scanf("%s",pattern);
    KmpSearch(pattern,text);
    return 0;
}