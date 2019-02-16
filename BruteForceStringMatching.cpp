#include<stdio.h>
#include<string.h>

int main() {
	char t[30], p[10];
	int i=0,j=0,tlen,plen;
	
	printf("Enter a Text : ");
	gets(t);
	
	printf("Enter a pattern to be seacrhed : ");
	gets(p);
	
	tlen = strlen(t);
	plen = strlen(p);
	
	for(i=0;i<=tlen - plen; i++) {
		j=0;
		while(j<plen && t[i+j] == p[j] ) {
			j++;
		}
		if(j==plen) {
			printf("Pattern found!");
			return 0;
		}
	}
	printf("Pattern not found");
	return 0;
}
