#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue{
	int arr[MAX];
	int front;
	int rare;
};
void init(struct queue *q){
	q->front=-1;
	q->rare=-1;
}
int isfull(struct queue *q){
	return q->rare==MAX-1;
}
int isempty(struct queue *q){
	return q->front==-1;
}
void enqueue(struct queue *q,int ele){
	if (isfull(q)){
		printf("queue full");
	}
	else{
		if (q->front==-1){
			q->front++;
			q->rare++;
			q->arr[q->rare]=ele;
			printf("the pushed element is:%d\n",ele);
		}
		else{
			q->rare++;
			q->arr[q->rare]=ele;
			printf("the pushed element is:%d\n",ele);
		}
	}
}
void dequeue(struct queue *q){
	if (isempty(q)){
		printf("queue empty");
	}
	else{
		int temp=q->arr[q->front];
		printf("the pop element is:%d\n",temp);
		q->front++;
	}
}
int main(){
	struct queue q;
	init(&q);
	enqueue(&q,10);
	enqueue(&q,20);
	dequeue(&q);
	dequeue(&q);
}
