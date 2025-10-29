#include <stdio.h>

int queue[50];
int front=-1,rear=-1;

void push(int a)
{
    if(front==-1)
    {
        front=0,rear=0;
        queue[rear]=a;
    }
    else
    {
        queue[++rear]=a;
    }
}

int pop()
{
    int val=queue[front++];
    if(front>rear)
    {
        front=-1;
        rear=-1;
    }
    return val;
}

void initialise_graph(int n,int graph[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }   
    }
}

void addEdge(int n,int graph[n][n],int des,int src)
{
    graph[des][src]=1;
    graph[src][des]=1;
}

void user_bfs(int n,int graph[n][n],int start)
{
    int visited[n];
    int i=0;
    int bfs[n];

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    
    push(start);
    visited[start]=1;

    while(front!=-1)
    {
        int val=pop();
        bfs[i++]=val;
        for(int v=0;v<n;v++)
        {
            if(graph[val][v] && !visited[v])
            {
                push(v);
                visited[v]=1;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        printf(" %d ",bfs[i]+1);
    }
}

int main()
{
    int rows,des,src;
    int start,choice=0;
    printf("Enter the rows: ");
    scanf("%d",&rows);

    int graph[rows][rows];
    initialise_graph(rows,graph);
   

    do{
        printf("1.Add edges\n2.Run bfs\n3.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            
            printf("Enter the source(1 to %d): ",rows);
            scanf("%d",&src);
            printf("Enter the destination(1 to %d): ",rows);
            scanf("%d",&des);
            addEdge(rows,graph,des-1,src-1);
            break;

            case 2:
            printf("Enter the start: ");
            scanf("%d",&start);
            user_bfs(rows,graph,start-1);
            printf("\n");
            break;
        }
    }while(choice!=3);
    
    return 0;
}