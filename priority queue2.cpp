#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	int priority;
	struct node *next;
};
struct queue{
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
	if (q->front==NULL || q->front->priority>priority){
		pnode->next=q->front;
		q->front=pnode;
	} 
	if (q->rare==NULL){
		q->rare=pnode;
	}
	else{
		struct node *ptr=q->front;
		while (ptr->next!=NULL && ptr->next->priority<=priority){
			ptr=ptr->next;
		}
		pnode->next=ptr->next;
		ptr->next=pnode;
	}
	if (pnode->next==NULL){
		q->rare=pnode;
	}
	printf("the push element is:%d\n",pnode->data);
	printf("the priority is:%d\n",pnode->priority);
}
void pop(struct queue *q){
	struct node *temp=q->front;
	printf("the pop element is:%d\n",temp->data);
	q->front=q->front->next;
	free(temp);
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
