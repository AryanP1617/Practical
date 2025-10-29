#include <stdio.h>

int count=0;
void printarray(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
}

void merge(int low,int mid,int high,int a[],int size)
{
    int b[size];
    int h=low;
    int k=mid+1;
    int i=0;

    printarray(a,size);
    while(h<=mid && k<=high)
    {
        if(a[h]<=a[k])
        {
            b[i++]=a[h++];
        }
        else
        {
            b[i++]=a[k++];
        }
    }

    while(h<=mid)
    {
        b[i++]=a[h++];
    }

    while(k<=high)
    {
        b[i++]=a[k++];
    }

    for(int j=low;j<=high;j++)
    {
        a[j]=b[j-low];
    }    
}

void merge_sort(int low,int high,int a[],int size)
{
    count++;
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(low,mid,a,size);
        merge_sort(mid+1,high,a,size);
        merge(low,mid,high,a,size);
    }
}

int main()
{
    int array[100];
    int size;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    printf("Enter the elements of array: ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
    merge_sort(0,size-1,array,size);
    printarray(array,size);
    printf("The number of calls done is:%d",count);
    return 0;
}