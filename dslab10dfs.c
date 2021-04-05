#include<stdio.h>
// defining a array 1st 2d array for graph 2nd  1d aarray for for visited node
int a[20][20] , visited[20],n;

void dfs(int v)
{
    int i;
    for(i=0;i<n;i++) // check all the vertex in the the graph
    {
        if(a[v][i] !=0 && visited[i]==0) // adjacent to v and not visited
        {
            visited[i]=1; // mark the matrix visited
            printf("%d ",i);
            dfs(i);
        }

    }
}

int main()
{
    int v,i,j;

    printf("\n Enter the number of vertices:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }

    printf("\n Enter Graph data in matrix form:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);

        printf("\n Enter the starting vertex:");
        scanf("%d",&v);
        printf("\n DFS traversal is: \n");

        // marking the starting vertex is visited
        visited[v]=1;

        printf("%d ",v);
        dfs(v);
    

        
        

}

