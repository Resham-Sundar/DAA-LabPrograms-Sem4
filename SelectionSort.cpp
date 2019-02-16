#include<stdio.h>
int main() {
	int ar[20],i,j,min;
	int n,t;
	
	printf("Enter number of elements : ");
	scanf("%d",&n);
	
	//Accepting values
	printf("Enter %d numbers in array :-\n",n);
	for(i=0;i<n;i++) {
		scanf("%d",&ar[i]);
	}
	
	//Sorting using Selection Sort
	for(i=0;i<n-1;i++) {
		min=i;
		for(j=i+1;j<n;j++) {
			if(ar[j]<ar[min]) {
				min=j;
			}
		}
		t=ar[min];
		ar[min] = ar[i];
		ar[i] =t;
	}
	
	printf("Sorted array : ");
	for(i=0;i<n;i++){
		printf("%d\t",ar[i]);
	}
	return 0;
}
