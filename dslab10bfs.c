#include<stdio.h>
// 2D adjancey matrix array,queue,1d array for marking already visited array ,rare and front
int a[20][20],q[20],visited[20],n,f=-1,r=-1;

void bfs(int v)
{
    int i;
    for ( i = 0; i < n; i++) //check all the vertices in the graph
    {
        if(a[v][i]!=0 && visited[i]==0) // condition for checking adjacent vertex and not visited vertex
        {
            r=r+1;
            q[r]=1 ; //insertion in the queue
            visited[i]=1; //mark the vertex visited
            printf("%d ",i);

        }
        f=f+1;              // removing the vertex at front of the queue
        if(f<=r)            // as along as there is element in the queue
            bfs(q[f]);      // perform bfs again on the vertex at front of the queue
        /* code */
    }
    
   
    
}

void main()
{
    int v,i,j;
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    for (i = 0;i<n;i++) // mark the all vertices not visited
    {
        visited[i]=0;
  
    }

    printf("\n  Enter the graph data in matrix form:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    // for(i=0;i<n;i++)
    //     for(j=0;j<n;j++)

    //     scanf("%d",a[i][j]);

        printf("\n Enter the starting vertex:");
        scanf("%d",&v);
        f=r=0;
        q[r]=v;
        printf("\n BFS traversal is:\n");
        visited[v]=1; // mark the starting vertex as visited
        printf("%d  ",v);
        bfs(v);
        if(r!=n-1)
        printf("\n BFS is not possible");




    
}
