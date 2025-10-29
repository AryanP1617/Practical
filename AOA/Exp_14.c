#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

void Rabin_karp(char text[],char pattern[])
{
    int m=strlen(pattern);
    int n=strlen(text);
    int t=0,p=0,h=1,j;

    for(int i=0;i<m-1;i++)
    {
        h=(h*d)%q;
    }

    for(int i=0;i<m;i++)
    {
        t=(d*t+text[i])%q;
        p=(d*p+pattern[i])%q;        
    }

    for(int i=0;i<=n-m;i++)
    {
        if(t==p)
        {
            for(j=0;j<m;j++)
            {
                if(text[i+j]!=pattern[j])
                {
                    break;
                }                
            }
            if(j==m)
            {
                printf("Pattern found at %d\n",i);
            }
        }

        if(i<n-m)
        {
            t=(d*(t-text[i]*h)+text[i+m])%q;
            if(t<0)
                t=t+q;
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
    Rabin_karp(text,pattern);
    return 0;
}