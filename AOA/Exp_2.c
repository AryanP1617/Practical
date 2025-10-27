#include <stdio.h>

void selection_sort(int a[],int size);
void printarray(int a[],int size);

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
    selection_sort(array,size);
    return 0;
}

void selection_sort(int a[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(a[j]<a[min])
            {
                a[j]=a[min]+a[j];
                a[min]=a[j]-a[min];
                a[j]=a[j]-a[min];
            }
        }
        printarray(a,size);
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

