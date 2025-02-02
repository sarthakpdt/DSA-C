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
		pnode->next=head;
	}
	else{
		ptr=head;
		while (ptr->next!=head){
			ptr=ptr->next;
		}
		ptr->next=pnode;
		pnode->next=head;
	}
	return head;
}
void display(struct data *head){
	struct data *ptr=head;
	printf("the linked list is:\n");
	printf("%d->",ptr->data);  
    ptr = ptr->next;
	while(ptr!=head){
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("%d",head->data);
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
