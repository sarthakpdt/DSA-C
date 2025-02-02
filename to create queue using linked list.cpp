#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
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
int isempty(struct queue *q){
	return q->front==NULL;
}
void push(struct queue *q,int ele){
	struct node *pnode=(struct node *)malloc(sizeof(struct node));
	pnode->data=ele;
	pnode->next=NULL;
	if (q->front==NULL){
		q->front=pnode;
		q->rare=pnode;
		printf("the pushed element is:%d",pnode->data);
	}
	else{
		q->rare->next=pnode;
		q->rare=pnode;
		printf("the pushed element is:%d",pnode->data);
	}
}
void pop(struct queue *q){
	struct node *temp=q->front;
	printf("the pop element is:%d",temp->data);
	q->front=q->front->next;
	free(temp);
}
int main(){
	struct queue q;
	init(&q);
	push(&q,10);
	push(&q,20);
	pop(&q);
	pop(&q);
}
