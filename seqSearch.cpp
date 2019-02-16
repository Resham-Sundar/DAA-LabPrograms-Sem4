#include<stdio.h>
int main() {
	
	int n,i,ar[50],key,flag=0;
	
	printf("Enter number of values : ");
	scanf("%d",&n);
	
	printf("Enter %d values in array :-\n",n);
	
	for(i=0;i<n;i++) {
		scanf("%d",&ar[i]);
	}
	
	printf("Enter value to be searched\n");
	scanf("%d",&key);
	
	for(i=0;i<n;i++) {
		if(ar[i]==key) {
			printf("Value found at position : %d \n",i+1);
			flag = 1;
			break;
		}
	}
	if(flag == 0) {
		printf("Value not found!\n");
	
	}
	return 0;
}
