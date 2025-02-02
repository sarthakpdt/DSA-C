#include<stdio.h>
#include<stdlib.h>
struct data{
	int data;
	struct data *next;
};
struct data *create(struct data *head){
	struct data *ptr;
	struct data *pnode=(struct data *)malloc(sizeof(struct data));
	int num;
	printf("enter the data:");
	scanf("%d",&num);
	pnode->data=num;
	pnode->next=NULL;
	if (head==NULL){
		head=pnode;
	}
	else{
		ptr=head;
		while (ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=pnode;
	}
	return head;
}
void display(struct data *head){
	struct data *ptr=head;
	printf("the linked list is:\n");
	while(ptr!=NULL){
		printf("%d->\t",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
}
int main(){
	struct data *head=NULL;
	int n;
	printf("how many data?:");
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		head=create(head);
	}
	display(head);
}
