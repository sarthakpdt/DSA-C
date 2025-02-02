#include<stdio.h>
#include<stdlib.h>
void sortarray(int arr[],int n){
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			if (abs(arr[i]) > abs(arr[j]) || abs(arr[i]) == abs(arr[j]) && arr[i] > arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main(){
	int n;
	printf("enter the length of the array:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++){
		printf("enter the number:");
		scanf("%d",&arr[i]);
	}
	sortarray(arr,n);
	printf("after sorting the array is:\n");
	for (int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
