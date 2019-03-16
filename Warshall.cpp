#include<stdio.h>
int i,j,k,adj[10][10],trans[10][10],n;
main()
{
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&adj[i][j]);
			trans[i][j]=adj[i][j];
     	}
     	
     	for(k=1;k<=n;k++)
     	{
     		for(i=1;i<=n;i++)
     		{
     			for(j=1;j<=n;j++)
     			{
     				trans[i][j]=(trans[i][j]||trans[i][k]&&trans[k][j]);
				 }
			 }
			 
			 printf("The transitive closure[%d] is ",k);
			 for(i=1;i<=n;i++)
			 {
			 	for(j=1;j<=n;j++)
				 {
				 	printf("%d",trans[i][j]);	
				 }
				 printf("\n");
			 }
		 }
	}
	
			
