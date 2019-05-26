#include<stdio.h>
void bfs(int v);
int adj[10][10],visited[10],n,s,count=0,i,j;
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
	bfs(s);
	for(i=1;i<=n;i++)
	{
		if(visited[i]>0)
		count++;
	}
	if(count==n)
	printf("\nGraph is connected");
	else
	printf("Graph is connected");
}
void bfs(int v)
{
	int w,que[10],f,r;
	visited[v]=1;
	f=1;
	r=1;
	que[r]=v;
	printf("The bfs traversal is\n");
	while(f<=r)
	{
		for(w=1;w<=n;w++)
		{
			if(adj[que[f]][w]=1 && visited[w]==0)
			{
				que[++r]=w;
				visited[w]=1;
			}
		}
		printf("%d\t",que[f++]);
	}
}
