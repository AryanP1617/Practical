#include <stdio.h>

void convert_to_bin(int a,int arr[])
{
    int i=0,j=0;
    
    while(i<5)
    {
        arr[i++]=a%2;
        a/=2;
    }
    
    i--;

    while(j<i)
    {
        int temp=arr[j];
        arr[j++]=arr[i];
        arr[i--]=temp;
    }
}

void copy(int a[],int b[])
{
    for(int i=0;i<5;i++)
    {
        b[i]=a[i];
    }
}

void two_complement(int a[]){
    int i,j;

    for(i=4;i>=0;i--)
    {
        if(a[i]==1)
        {
            j=i-1;
            while(j>=0)
            {
                a[j]=1-a[j];
                j--;
            }
            break;
        }
    }
}

int main()
{
    int num;
    int binary[5];
    int twos_complement[5];
    printf("Enter the number(0-15): ");
    scanf("%d",&num);
    convert_to_bin(num,binary);
    copy(binary,twos_complement);
    two_complement(twos_complement);
    printf("Binary form:\n");
    for(int i=0;i<5;i++)
    {
        printf("%d ",binary[i]);
    }
    printf("\nTwo's complement form:\n");

    for(int i=0;i<5;i++)
    {
        printf("%d ",twos_complement[i]);
    }
}