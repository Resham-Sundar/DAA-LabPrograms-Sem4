#include<stdio.h>
void dis_count(int a[],int n,int l,int u);
int main()
{
	int i,n,a[20],l,u;
	l=0;
	u=0;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	if(a[i]>u)
	u=a[i];
	}
	l=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<l)
		l=a[i];
	}
	dis_count(a,n,l,u);
}
void dis_count(int a[],int n,int l,int u)
{
	int i,j,D[20],S[20];
	for(j=0;j<=u-l;j++)
	D[j]=0;
	for(i=0;i<n;i++)
	{
		D[a[i]-l]=D[a[i]-l]+1;
	}
	for(j=1;j<=u-l;j++)
	{
		D[j]=D[j-1]+D[j];
	}
	for(i=n-1;i>=0;i--)
	{
		j=a[i]-l;
		S[D[j]-1]=a[i];
		D[j]=D[j]-1;
	}
	printf("After sorting the array is\n");
	for(i=0;i<n;i++)
	printf("%d ",S[i]);
}
