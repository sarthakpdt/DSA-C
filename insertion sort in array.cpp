#include<stdio.h>
void insertionsort(int arr[],int n){
	for (int i=0;i<n;i++){
		int j;
		int minnumber=arr[i];
		for (j=i;j>=0;j--){
			if (arr[j]>minnumber){
				arr[j+1]=arr[j];
			}
		}
		arr[j+1]=minnumber;
	}
}
int main(){
    int n;
    printf("enter the length of array:");
    scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
    	printf("enter number:");
    	scanf("%d",&arr[i]);
    }
    insertionsort(arr, n);
    printf("array after insertion sort is:\n");
    for (int i=0;i<n;i++){
    	printf("%d",arr[i]);
	}
}
