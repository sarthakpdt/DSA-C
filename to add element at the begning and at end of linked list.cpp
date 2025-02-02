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
struct data *insertatbeg(struct data *head){
	struct data *pnode=(struct data *)malloc(sizeof(struct data));
	int ndata;
	printf("enter the data you want to enter in the begning:");
	scanf("%d",&ndata);
	pnode->data=ndata;
	pnode->next=head;
	head=pnode;
	return head;
}
struct data *insertatend(struct data *head){
	struct data *ptr=head;
	struct data *pnode=(struct data *)malloc(sizeof(struct data));
	int ndata;
	printf("enter the data you want to enter at the end:");
	scanf("%d",&ndata);
	pnode->data=ndata;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=pnode;
	pnode->next=NULL;
	return head;
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
	printf("\n");
	head=insertatbeg(head);
	printf("the linked list after insertion of element at begning is:\n");
	display(head);
	printf("\n");
	head=insertatend(head);
	printf("the linked list after insertion of element at end is:\n");
	display(head);
}
