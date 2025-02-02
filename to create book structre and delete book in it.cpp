#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char title[20];
	char pub[20];
}book;
void deletebook(int *size,int position,book **books){
	for (int i=position;i<*size-1;i++){
		(*books)[i]=(*books)[i+1];
	}
	*books=(book *)realloc(*books,sizeof(book)*(*size-1));
	(*size)--;
}
int main(){
	int size;
	book *books=NULL;
	printf("enter how many data in book:");
	scanf("%d",&size);
	books=(book *)malloc(size*sizeof(book));
	for (int i=0;i<size;i++){
		printf("enter the title is:");
		scanf("%s",books[i].title);
		printf("the pub is:");
		scanf("%s",books[i].pub);
	}
	int position;
	printf("enter the position:");
	scanf("%d",&position);
	deletebook(&size,position,&books);
	for (int i=0;i<size;i++){
		printf("the title is:%s\n",books[i].title);
		printf("the author is:%s\n",books[i].pub);
	}
	
}
