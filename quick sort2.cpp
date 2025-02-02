#include<stdio.h>
void quicksort(int arr[],int low,int high){
	if (low<high){
		int pivot=arr[low];
		int i=low;
		for (int j=low+1;j<=high;j++){
			if (arr[j]<pivot){
				i++;
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		arr[low]=arr[i];
		arr[i]=pivot;
		int pi=i;
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
int main(){
	int n;
	printf("enter the length of the array:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++){
		printf("enter the numbers:");
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);
	printf("the array after quick sort using left element as pivot is:\n");
	for (int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}
