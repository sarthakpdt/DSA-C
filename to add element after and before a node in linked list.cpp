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
struct data *insertafternode(struct data *head){
	int ch;
	printf("enter the number after which you want to enter the data:");
	scanf("%d",&ch);
	int num;
	printf("enter the data:");
	scanf("%d",&num);
	struct data *ptr=head;
	struct data *pnode=(struct data *)malloc(sizeof(struct data));
	pnode->data=num;
	while (ptr!=NULL){
		if(ptr->data==ch){
			pnode->next=ptr->next;
			ptr->next=pnode;
		}
		ptr=ptr->next;
	}
	return head;
}
struct data *insertbeforenode(struct data *head){
	int ch;
	printf("enter the number before which you want to enter the data:");
	scanf("%d",&ch);
	int num;
	printf("enter the data:");
	scanf("%d",&num);
	struct data *ptr=head;
	struct data *prev=head;
	struct data *pnode=(struct data*)malloc(sizeof(struct data));
	pnode->data=num;
	while (ptr!=NULL){
		if(ptr->data==ch){
			pnode->next=ptr;
			prev->next=pnode;
		}
		prev=ptr;
		ptr=ptr->next;
	}
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
	head=insertafternode(head);
	printf("the linked list after insertion of element after node is:\n");
	display(head);
	printf("\n");
	head=insertbeforenode(head);
	printf("the linked list after insertion of element before node is:\n");
	display(head);
}
