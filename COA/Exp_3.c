#include <stdio.h>

void convert_to_bin(int a,int arr[])
{
    int i=0,j=0;
    
    while(i<4)
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

int main()
{
    int num;
    int binary[4];
    printf("Enter a number(0 to 15): ");
    scanf("%d",&num);
    convert_to_bin(num,binary); 

    for(int i=0;i<4;i++)
    {
        printf("%d ",binary[i]);
    }
    
    return 0;
}