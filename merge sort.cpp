#include<stdio.h>
void mergesort(int arr[],int left,int right){
	if (left<right){
		int mid=left+(right-left)/2;
		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		int n1=mid-left+1;
		int n2=right-mid;
		int larr[n1];
		int rarr[n2];
		for (int i=0;i<n1;i++){
			larr[i]=arr[left+i];
		}
		for (int i=0;i<n2;i++){
			rarr[i]=arr[mid+i+1];
		}
		int i=0;
		int j=0;
		int k=left;
		for (;i<n1 && j<n2;k++){
			if (larr[i]<rarr[j]){
				arr[k]=larr[i];
				i++;
			}
			else{
				arr[k]=rarr[j];
				j++;
			}
		}
		for (;i<n1;i++,k++){
			arr[k]=larr[i];
		}
		for (;j<n2;j++,k++){
			arr[k]=rarr[j];
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
	mergesort(arr,0,n-1);
	printf("the array after merge sort is:\n");
	for (int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}
