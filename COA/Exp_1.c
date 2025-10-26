#include <stdio.h>

int booths_register[9];
int accumalator[4]={0};
int multiplier[4];
int multiplicand[4];

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

void copy_array(int a[],int b[],int size)
{
    for(int i=0;i<size;i++)
    {
        b[i]=a[i];
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

void ars()
{
    for(int i=8;i>0;i--)
    {
        booths_register[i]=booths_register[i-1];
        
        if(i>=4 && i<8)
        {
            multiplier[i-4]=booths_register[i];
        }
        else if(i<4)
        {
            accumalator[i]=booths_register[i];
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
    int flag=0;
    
    if(a[0]==1)
    {
        two_complement(a,8);
        flag=1;
    }
    
    for(int i=7;i>=0;i--)
    {
        sum=sum+(a[i]*(user_pow(2,7-i)));
    }

    return ((flag==0)?sum:-sum);
}

void initialise_register()
{
    for(int i=0;i<4;i++)
    {
        booths_register[i]=accumalator[i];
        booths_register[i+4]=multiplier[i];
    }
    booths_register[8]=0;
    
}

void print_result()
{
    for(int i=0;i<8;i++)
    {
        printf("%d ",booths_register[i]);
    }
}

void booths_algo()
{
    int count=4;
    int temp[4];
    while(count>0)
    {
        
       
        int diff=booths_register[7]-booths_register[8];
        if(diff>0)
        {
            bin_sub(accumalator,multiplicand,temp);
           
            copy_array(temp,accumalator,4);
            copy_array(temp,booths_register,4);
            
            
        }
        else if(diff<0)
        {
            bin_add(accumalator,multiplicand,temp);
            copy_array(temp,accumalator,4);
            copy_array(temp,booths_register,4);
        }
        
        ars();
        count--;

    }
}

int main()
{
    int num1,num2,result;
    int temp[4];
    printf("Enter a number(0-7): ");
    scanf("%d",&num1);
    printf("Enter another number(0-7): ");
    scanf("%d",&num2);

    if(num1<0)
    {
        convert_to_bin(-num1,multiplier);
        
        two_complement(multiplier,4);
        
        for(int i=0;i<4;i++)
        {
            printf("%d",multiplier[i]);
        }
        printf("\n");
        
    }
    if(num2<0)
    {
        convert_to_bin(-num2,multiplicand);
        
        two_complement(multiplicand,4);
        
    }
    
    if(num1>0)
    {
        convert_to_bin(num1,multiplier);
    }
    if(num2>0)
    {
        convert_to_bin(num2,multiplicand);
    }
    
    initialise_register();
    
    booths_algo();
    print_result();

    result=convert_to_dec(booths_register);
    printf("The result is:%d",result);
    return 0;
}

