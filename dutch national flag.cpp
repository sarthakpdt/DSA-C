#include<stdio.h>
void dutchflag(int arr[],int n){
	int low=0;
	int mid=0;
	int high=n-1;
	while (mid<=high){
		if (arr[mid]==0){
			int temp=arr[low];
			arr[low]=arr[mid];
			arr[mid]=temp;
			low++;
			mid++;
		}
		else if(arr[mid]==1){
			mid++;
		}
		else{
			int temp=arr[mid];
			arr[mid]=arr[high];
			arr[high]=temp;
			high--;
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
	dutchflag(arr,n);
	printf("after sorting the array is:\n");
	for (int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
