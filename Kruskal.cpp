#include<stdio.h>
int i,j,a,b,u,v,n,ne=1;
int cost[10][10], parent[10],min,mincost=0;
main()
{
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the cost matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			{
				cost[i][j]=999;
			}
		}
	}
	
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(cost[i][j]<min)
			{
				min=cost[i][j];
				a=u=i;
				b=v=j;
			}
		}
		while(parent[u])
		u=parent[u];
		
		while(parent[v])
		v=parent[v];
		
		if(u!=v)
		{
			printf("%d Edge(%d,%d)=%d\n",ne++,a,b,min);
			parent[v]=u;
		}
		cost[a][b]=cost[b][a]=999;
		mincost=mincost+min;
	}
	printf("The minimum cost spanning tree is %d ",mincost);			
}
