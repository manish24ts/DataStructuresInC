/*Program to implement Depth First Search (DFS)Traversal */

#include<stdio.h>
#define size 5
int stack[size],visited[size],a[5][5],i,j,n,top=-1;
void push(int x)
{

    stack[++top]=x;
}
int isEmpty_stack()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void DFS(int v)
{
    int x,flag=0;
    push(v);
    visited[v]=1;
    printf("%d ",v);
    while(!isEmpty_stack())
    {
        flag=0;
        x=stack[top];
        for(i=1;i<=n;i++)
        {
            if(a[x][i]==1 && visited[i]==0)
            {
                push(i);
                printf("%d ",i);
                visited[i]=1;
                flag =1;
                break;
            }
        }
        if(flag==0)
            top--;
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
    DFS(1);
    return 0;
}

