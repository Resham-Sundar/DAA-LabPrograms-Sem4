#include<stdio.h>
int adj[10][10],visited[10],count=0,i,j,n,s;
int dfs(int v);
main()
{
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&adj[i][j]);
	printf("Enter the source for dfs traversal\n");
	scanf("%d",&s);
	for(i=1;i<=n;i++)
	visited[i]=0;
	printf("The dfs traversal is: ");
	dfs(s);
	printf("The order of traversal is\n");
	for(i=1;i<=n;i++)
	printf("%d -> %d\t",i,visited[i]);
	if(count==n)
	printf("\nGraph is connected");
	else
	printf("Graph is connected");
}
int dfs(int v)
{
	int w;
	count++;
	visited[v]=count;
	printf("%d\t",v);
	for(w=1;w<=n;w++)
	{
		if(adj[v][w]==1 && visited[w]==0)
		dfs(w);
	}
}
