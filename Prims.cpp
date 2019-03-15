#include<stdio.h>
int i,j,a,b,u,v,n,ne=1;
int cost[10][10], visited[9],min,mincost=0;
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
	
	visited[1]=1;
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					if(visited[i]==0)
					continue;
					
					else
					{
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
			    }
			}
			if(visited[v]==0)
			{
				printf("%d Edge(%d,%d)=%d\n",ne++,a,b,min);
				visited[v]=1;
				mincost =mincost + min;

			}
			
			cost[a][b]=cost[b][a]=999;
		}
	printf("The minimum cost spanning tree is %d ",mincost);			
	}
	
