#include <stdio.h>

int x[100];
int count;

int mod(int a)
{
    return (a>0)?a:-a;
}

void print_1D_board(int n)
{
    printf("1D Representation: \n");
    for(int i=0;i<n;i++)
    {
        printf("| %d ",x[i]+1);
    }
    printf("| \n\n");

}

void print_2D_board(int n)
{
    printf("2D representation: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(x[i]==j)
            {
                printf(" Q ");
            }
            else
            {
                printf(" . ");
            }
        }
        printf("\n");
    }

    printf("\n\n");
}
int place(int row,int column)
{
    for(int j=0;j<row;j++)
    {
        if(column==x[j]||mod(x[j]-column)==mod(row-j))
        {
            return 0;
        }
    }
    return 1;
}



void n_queens(int row,int n)
{
    count++;
    for(int i=0;i<n;i++)
    {
        if(place(row,i))
        {
            x[row]=i;
            if(row==n-1)
            {
                print_1D_board(n);
                print_2D_board(n);
                return;
            }
            else
            {
                n_queens(row+1,n);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of rows and columns: ");
    scanf("%d",&n);
    printf("\n");
    n_queens(0,n);
    printf("The number of calls are %d",count);
    return 0;
}