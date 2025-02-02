#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quicksort(int arr[],int low,int high){
	if (low<high){
		int randomindex=low+rand()%(high-low+1);
		int temp=arr[randomindex];
		arr[randomindex]=arr[high];
		arr[high]=temp;
		int i=low-1;
		int pivot=arr[high];
		for (int j=low;j<high;j++){
			if (arr[j]<pivot){
				i++;
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[i+1];
		arr[i+1]=arr[high];
		arr[high]=temp;
		int pi=i+1;
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
int main(){
	srand(time(0));
	int n;
	printf("enter the length of the array:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++){
		printf("enter the numbers:");
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);
	printf("the array after quick sort using random element as pivot is:\n");
	for (int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}
