#include <stdio.h>

int size;

void printarray(int a[],int size);

int partition(int a[],int low,int high)
{
    int i=low,j=i-1;    
    for(i=low;i<high;i++)
    {
        if(a[i]<a[high])
        {
            j++;
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }        
    }
    int t=a[j+1];
    a[j+1]=a[high];
    a[high]=t;
    
    return j+1;
}

void quicksort(int a[],int low,int high,int *count)
{
    (*count)++;    
    printarray(a,size);
    

    if(low<high)
    {
        int p=partition(a,low,high);
        
        quicksort(a,low,p-1,count);
        quicksort(a,p+1,high,count);
        
    }    
}

void printarray(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int array[100];
    int count=0;
    int *p=&count;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    printf("Enter the elements of array: ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
    quicksort(array,0,size-1,p);
    printf("The number of calls done is:%d",count);    
    return 0;
}