#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue{
	int arr[MAX];
	int front;
	int rare;
};
queue init(){
	queue q;
	q.front=-1;
	q.rare=-1;
	return q;
}
int isfull(queue *pq){
	return (pq->rare+1)%MAX==pq->front;
}
int isempty(queue *pq){
	return pq->front==-1;
}
void enqueue(queue *pq,int ele){
	if (isfull(pq)){
		printf("stack is full");
	}
	else{
		if (pq->front==-1){
			pq->front=0;
            pq->rare=0;
		}
		else{
			pq->rare=(pq->rare+1)%MAX;
		}
		pq->arr[pq->rare]=ele;
		printf("the element enqueued is:%d\n",ele);
	}
}
void dequeue(queue *pq){
    if (isempty(pq)){
        printf("Queue is empty\n");
    } 
	else{
        int temp=pq->arr[pq->front];
        printf("The element dequeued is: %d\n",temp);
        if (pq->front==pq->rare){
            pq->front=-1;
            pq->rare=-1;
		} 
		else{
            pq->front=(pq->front+1)%MAX;
        }
    }
}
int main(){
	queue q=init();
	enqueue(&q,10);
	enqueue(&q,20);
	dequeue(&q);
	dequeue(&q);
}

