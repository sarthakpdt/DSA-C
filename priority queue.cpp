#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	int priority;
	struct node *next;
};
struct queue{
	struct queue *q;
	struct node *front;
	struct node *rare;
};
void init(struct queue *q){
	q->front=NULL;
	q->rare=NULL;
}
void push(struct queue *q,int ele,int priority){
	struct node *pnode=(struct node *)malloc(sizeof(struct node));
	pnode->data=ele;
	pnode->priority=priority;
	pnode->next=NULL;
	if (q->front==NULL){
		q->front=pnode;
		q->rare=pnode;
		printf("the push element is:%d\n",pnode->data);
		printf("the priority is:%d\n",pnode->priority);
	}
	else{
		q->rare->next=pnode;
		q->rare=pnode;
		printf("the push element is:%d\n",pnode->data);
		printf("the priority is:%d\n",pnode->priority);
	}
}
void pop(struct queue *q){
	struct node *temp=q->front;
	struct node *temp1=temp;
	struct node *prev=NULL;
	struct node *prevm=NULL;
	while (temp!=NULL){
		if (temp->priority > temp1->priority){
			temp1=temp;
			prevm=prev;
		}
		prev=temp;
		temp=temp->next;
	}
	if (temp1==q->front){
		q->front=temp1->next;
	}
	else{
		prevm->next=temp1->next;
	}
	if (temp1==q->rare){
		q->rare=prevm;
	}
	printf("the pop element is:%d\n",temp1->data);
	printf("the priority is:%d\n",temp1->priority);
}
int main(){
	struct queue q;
	init(&q);
	push(&q,10,1);
	push(&q,20,2);
	push(&q,30,3);
	pop(&q);
	pop(&q);
	pop(&q);
}
