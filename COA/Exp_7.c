#include <stdio.h>

int exponent[8];
int mantissa[23];


int find_bit_size(int num)
{
    int size=0;
    while(num>0)
    {
        num=num/2;
        size++;
    }
    return size;
}

void convert_int_to_binary(int a,int arr[],int size)
{
    
    int i=0,j=0;
    
    while(i<size)
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

void convert_frac_to_binary(double a,int start)
{
    int i=start;
    while(i<23)
    {
        double temp=a*2;
        mantissa[i++]=(int)temp;
        a=temp-(int)temp;
        
    }
}

void fill_mantissa(int arr[],int end)
{
    for(int i=0;i<end;i++)
    {
        mantissa[i]=arr[i+1];
    }
}

void fill_exponent(int bias)
{
    int num=127+bias;
    convert_int_to_binary(num,exponent,8);
}

void iee(int num,double frac){

    int size_of_num=find_bit_size(num);
    int bias=size_of_num-1;
    int num_array[32];
    convert_int_to_binary(num,num_array,size_of_num);
    convert_frac_to_binary(frac,bias);
    fill_mantissa(num_array,bias);
    fill_exponent(bias);

    (num>0)?(printf("Sign:0\n")):(printf("Sign:1\n"));
    printf("Exponent:");
    for(int i=0;i<8;i++)
    {
        printf(" %d ",exponent[i]);
    }
    printf("\nMantissa:");
    for(int i=0;i<23;i++)
    {
        printf(" %d ",mantissa[i]);
    }
    printf("\n");
}

int main()
{
    double num;
    printf("Enter the num: ");
    scanf("%lf",&num);
    int integer=(int)num;
    double fraction=num-integer;
    iee(integer,fraction);
    return 0;
}