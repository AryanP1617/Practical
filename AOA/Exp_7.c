#include <stdio.h>

void knapsack(int n,int W,int dp[n+1][W+1],int keep[n][W+1],int wt[],int val[])
{
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0||w==0)
            {
                dp[i][w]=0;
                keep[i][w]='X';
            }
            else if(wt[i-1]<=W)
            {
                if((val[i-1]+dp[i-1][w-wt[i-1]])>dp[i-1][w]){
                    dp[i][w]=val[i-1]+dp[i-1][w-wt[i-1]];
                    keep[i][w]='O';
                }
                else
                {
                    dp[i][w]=dp[i-1][w];
                    keep[i][w]='X';
                }
            }
            else
            {
                dp[i][w]=dp[i-1][w];
                keep[i][w]='X';
            }
        }
    }

    printf("DP table: \n");
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            printf("%3d",dp[i][w]);
        }
        printf("\n");
    }
    printf("\n\n");

    printf("Keep Table: \n");
     for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            printf(" %c ",keep[i][w]);
        }
        printf("\n");
    }

    printf("\n\n");

    for(int j=n;j>0;j--)
    {
        if(W>0 && keep[j][W]=='O')
        {
            printf("Item:%d value:%d",j,val[j-1]);
            W=W-wt[j-1];
        }
    }
}

int main()
{
    int val[100];
    int wt[100];
    int W,n;
    int i=0;
    printf("Enter the size of the items: ");
    scanf("%d",&n);

    printf("Enter the maximum wight of the bag: ");
    scanf("%d",&W);

    int dp[n+1][W+1];
    char keep[n+1][W+1];

    printf("Enter the values: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&val[i]);
    }
    printf("Enter their weights: ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&wt[i]);
    }



    knapsack(W,n,dp,keep,val,wt);
    return 0;
    return 0;
}