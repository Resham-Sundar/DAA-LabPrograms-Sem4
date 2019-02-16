#include<stdio.h>
#define max 10
void mergeSort(int ar[], int low, int high);
void merge(int ar[], int low, int mid, int high);

//Driving Function
int main() {
	
	int ar[max],n,i;	 
	
	printf("Enter size of the array\n");
	scanf("%d",&n);
	
	//Accepting Elements
	printf("Enter %d number of elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	
	mergeSort(ar,0,n-1);
	printf("Sorted array : \n");
	for(i=0;i<n;i++) {
		printf("%d\t",ar[i]);
	}
}

//Dividing the array in half on every recursive call
void mergeSort(int ar[], int low, int high) {
	int mid;
	if(low<high) {
		mid=(low+high)/2;
		mergeSort(ar,low,mid);
		mergeSort(ar,mid+1,high);
		merge(ar,low,mid,high);
	}
}

//Comapring elements and recombining the arrays
void merge(int ar[], int low, int mid, int high) {
	int t[max];
	int i=low, k=low, j=mid+1;
	
	while(i<=mid && j<=high) {
		if(ar[i]<ar[j]) {
			t[k] = ar[i];
			i++;
			j++;
		}
		
		else {
			t[k] = ar[j];
			j++;
			k++;
		}
	}
	while(i<=mid) {
		t[k]=ar[i];
		k++;
		i++;
	}
	
	while(j<=high) {
		t[k]=ar[j];
		j++;
		k++;
	}
	
	for(i=low;i<=high;i++) {
		ar[i] = t[i];
	}
}
