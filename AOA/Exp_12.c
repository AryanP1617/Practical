#include <stdio.h>


int count=0;
int x[100],w[100];
int size=0;

void printsolution()
{
    printf("{ ");
    for(int i=0;i<size;i++)
    {
        if(x[i]==1)
        {
            printf(" %d ",w[i]);
        }
    }
    printf(" }\n");
}

void sum_of_subsets(int curr_sum,int k,int remainder,int total)
{
    x[k]=1;

    if(curr_sum+w[k]==total)
    {
        printsolution();
        x[k]=0;
        printf("\n");
    }
    else if(curr_sum+w[k]+w[k+1]<=total)
    {
        sum_of_subsets(curr_sum+w[k],k+1,remainder-w[k],total);
    }
    if( curr_sum+remainder-w[k]>=total && curr_sum+w[k+1]<=total)
    {
        x[k]=0;
        sum_of_subsets(curr_sum,k+1,remainder-w[k],total);
    }
}

int main(){
    int weight=0;
    int sum;
    printf("Enter the size of the set: ");
    scanf("%d",&size);

    printf("Enter the weights of elements in ascending order: ");

    for(int i=0;i<size;i++)
    {
        scanf("%d",&w[i]);
        weight+=w[i];
    }

    printf("Enter the sum you want: ");
    scanf("%d",&sum);
    sum_of_subsets(0,0,weight,sum);
    return 0;
}