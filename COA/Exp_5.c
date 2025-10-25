#include <stdio.h>

int user_pow(int a,int b)
{
    int p=0;
    int result=1;
    while(p<b)
    {
        result=result*a;
        p++;
    }
    return result;
}

int convert_to_dec(int a[])
{
    int sum=0;
    for(int i=4;i>=0;i--)
    {
        sum=sum+(a[i]*(user_pow(2,4-i)));
    }
    return sum;
}

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

void add_bin(int a[],int b[],int c[])
{
    int carry=0;

    for(int i=4;i>=0;i--)
    {
        if(carry==0)
        {
            c[i]=a[i]^b[i];
            if(a[i]==1 && b[i]==1)
            {
                carry=1;
            }
        }
        else if(carry==1)
        {
            c[i]=1-(a[i]^b[i]);
            if(a[i]==0 && b[i]==0)
            {
                carry=0;
            }  
        }

    }
}


int main()
{
    int num1,num2;
    int bin1[5],bin2[5];
    int result[5];
    int decimal;
    printf("Enter the first number(0-15): ");
    scanf("%d",&num1);
    convert_to_bin(num1,bin1);
    // for(int i=0;i<5;i++)
    // {
    //     printf("%d ",bin1[i]);
    // }
    // printf("\n");
    printf("Enter the second number(0-15): ");
    scanf("%d",&num2);
    convert_to_bin(num2,bin2);
    // for(int i=0;i<5;i++)
    // {
    //     printf("%d ",bin2[i]);
    // }
    //  printf("\n");
    add_bin(bin1,bin2,result);
    // for(int i=0;i<5;i++)
    // {
    //     printf("%d ",result[i]);
    // }
    // printf("\n");
   
    decimal=convert_to_dec(result);
    printf("%d",decimal);
    return 0;
}