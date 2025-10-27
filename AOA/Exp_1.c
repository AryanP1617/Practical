#include <stdio.h>

void printarray(int a[],int size);
void insertion_sort(int a[],int size);

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
    insertion_sort(array,size);
    return 0;

}

void insertion_sort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        int key=arr[i];
        int j;
        for(j=i-1;j>=0 && arr[j]>key;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
        printarray(arr,size);
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

