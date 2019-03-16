#include<stdio.h>
int i,j,k,cost[10][10],dis[10][10],n;
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
				dis[i][j]=cost[i][j];
     	}
     	
     	for(k=1;k<=n;k++)
     	{
     		for(i=1;i<=n;i++)
     		{
     			for(j=1;j<=n;j++)
     			{
     				if(dis[i][k]+dis[k][j]<dis[i][j])
     				{
     					dis[i][j]=dis[i][k]+dis[k][j];
					 }
				 }
			 }
			 
			 printf("The transitive closure[%d] is ",k);
			 for(i=1;i<=n;i++)
			 {
			 	for(j=1;j<=n;j++)
				 {
				 	printf("%d\t",dis[i][j]);	
				 }
				 printf("\n");
			 }
		 }
	}
