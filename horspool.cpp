#include<stdio.h>
#include<string.h>
#define max 500
void shiftTable(char P[]);
int horspool(char T[],char P[]);
int ST[max];
int main()
{
	char Text[50];
	char Pattern[50];
	int pos;
	printf("Enter the text string\n");
	gets(Text);
	printf("Enter the pattern\n");
	gets(Pattern);
	shiftTable(Pattern);
	pos=horspool(Text,Pattern);
	if(pos>=0)
	printf("The pattern is found at %d index in text",pos);
	else
	printf("Pattern is not found");
}
void shiftTable(char P[])
{
	int i,j,m;
	m=strlen(P);
	for(i=0;i<max;i++)
	ST[i]=m;
	for(i=0;i<=m-2;i++)
	ST[P[i]]=m-1-i;
}
int horspool(char T[],char P[])
{
	int i,j,n,m,k;
	n=strlen(T);
	m=strlen(P);
	i=m-1;
	while(i<=n-1)
	{
		k=0;
		while(k<=m-1 && (P[m-1-k]==T[i-k]))
		k=k+1;
		if(k==m)
		return i-m+1;
		else
		i=i+ST[T[i]];
	}
	return -1;
}
