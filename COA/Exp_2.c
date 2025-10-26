#include <stdio.h>

int div_register[8];
int accumalator[4]={0};
int dividend[4];
int divisor[4];

void print_result()
{
    for(int i=0;i<8;i++)
    {
        printf("%d ",div_register[i]);
    }
}

void copy_array(int a[],int b[],int size)
{
    for(int i=0;i<size;i++)
    {
        b[i]=a[i];
    }
}

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

void sl()
{
    for(int i=0;i<7;i++)
    {
        div_register[i]=div_register[i+1];
        
    }
        
    for(int i=0;i<4;i++)
    {
        accumalator[i]=div_register[i];
        dividend[i]=div_register[i+4];
    }    
}

void bin_add(int a[],int b[],int c[])
{
    int carry=0;

    for(int i=3;i>=0;i--)
    {
        c[i]=(carry==0)?(a[i]^b[i]):(1-(a[i]^b[i]));
        carry=(carry==0)?(a[i]&b[i]):(a[i]|b[i]);
    }
    
}

void two_complement(int a[],int size)
{
    for(int i=size-1;i>=0;i--)
    {
        if(a[i]==1)
        {
            for(int j=i-1;j>=0;j--)
            {
                a[j]=1-a[j];
            }
            break;  
        }
    }
    
    
}

void bin_sub(int a[],int b[],int c[])
{
    int temp[4];
    copy_array(b,temp,4);
    two_complement(temp,4);
    bin_add(a,temp,c);
}

void non_restoring()
{
    int count=0;
    int temp[4];
    
    while(count<4)
    {
        
        if (accumalator[0]) 
        {
            sl();
            bin_add(accumalator, divisor, div_register);
        } 
        else 
        {
            sl();
            bin_sub(accumalator, divisor, div_register);
        }
        copy_array(div_register,accumalator,4);
        div_register[7]=(accumalator[0])?0:1;
        
        dividend[3]=div_register[7];
        count++;
    }
    (accumalator[0])?(bin_add(accumalator,divisor,div_register)):0;
    copy_array(div_register,accumalator,4);
}

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
    
    for(int i=7;i>=0;i--)
    {
        sum=sum+(a[i]*(user_pow(2,7-i)));
    }

    return sum;
}

void initialise_register()
{
    for(int i=0;i<4;i++)
    {
        div_register[i]=accumalator[i];
        div_register[i+4]=dividend[i];
    }
    
    
}

int main()
{
    int num1,num2,result;
    
    printf("Enter a number: ");
    scanf("%d",&num1);
    printf("Enter another number: ");
    scanf("%d",&num2);

    convert_to_bin(num1,dividend);
    convert_to_bin(num2,divisor);
    
    initialise_register();
    non_restoring();
    print_result();
    printf("\n");
    printf("Result: %d",convert_to_dec(div_register));
    return 0;
}