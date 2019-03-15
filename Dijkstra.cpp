#include<stdio.h>
int i,j,k,min,v,s,n,u;
int cost[10][10],visited[10],dis[10];
main()
{
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the cost matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			{
				cost[i][j]=999;
			}
		}
	printf("Enter the source vertex\n");
	scanf("%d",&s);
	
	for(i=1;i<=n;i++)
	{
		dis[i]=cost[s][i];
		visited[i]=0;
	}
	visited[s]=1;
	dis[s]=0;
	
	for(i=1;i<=n-1;i++)
	{
		min=999;
	for(k=1;k<=n;k++)
	{
		if(dis[k]<min && visited[k]==0)
		{
			min=dis[k];
			u=k;
		}
	}
	visited[u]=1;
	for(v=1;v<=n;v++)
	{
		if(visited[v]==0)
		{
			if(dis[u]+cost[u][v]<dis[v])
			{
				dis[v]=dis[u]+cost[u][v];
			}
		}
	
	}
	}
	
	printf("The shortest path/distance is ");
	for(i=1;i<=n;i++)
	{
		printf("\n distance[%d] -> distance[%d]=%d",s,i,dis[i]);
	}
}
