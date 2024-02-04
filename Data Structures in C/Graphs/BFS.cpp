/*Program to implement Breadth first search (BFS)*/
#include<stdio.h>
#define size 5
int q[size],visited[size],a[5][5],i,j,n,front=-1,rear= -1;
void insert_queue(int x)
{

    q[++rear]=x;
}
int delete_queue()
{
    return q[++front];
}
int isEmpty_queue()
{
    if(front==rear)
        return 1;
    else
        return 0;
}
void BFS(int v)
{
    insert_queue(v);
    while(!isEmpty_queue())
    {
        v= delete_queue();
        printf("%d ",v);
        visited[v]=1;
        for(i=1;i<=n;i++)
        {
            if(a[v][i]==1 && visited[i]==0)
            {
                insert_queue(i);
                visited[i]=1;
            }
        }
    }
}
int main()
{
    printf("Enter no of vertices: \n");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    BFS(1);
    return 0;
}

