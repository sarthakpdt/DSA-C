#include<stdio.h>
void selectionsort(int arr[],int n){
	for (int i=0;i<n;i++){
		int minindex=i;
		for (int j=i;j<n;j++){
			if (arr[j]<arr[minindex]){
				minindex=j;
			}
		}
		if (minindex!=i){
			int temp=arr[i];
			arr[i]=arr[minindex];
			arr[minindex]=temp;
		}
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
	selectionsort(arr,n);
	printf("the array after selection sort is:\n");
	for (int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}

