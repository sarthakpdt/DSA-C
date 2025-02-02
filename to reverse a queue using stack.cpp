#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue{
	int arr[MAX];
	int front;
	int rare;
};
struct stack{
    int top;
    int arr[MAX];
};
queue init(){
	queue q;
	q.front=-1;
	q.rare=-1;
	return q;
}
int isfull(queue *pq){
	return pq->rare==MAX-1;
}
int isempty(queue *pq){
	return pq->front==-1;
}
void init(struct stack *s){
    s->top=-1;
}
int isempty(struct stack *s){
    return s->top==-1;
}
int isfull(struct stack *s){
    return s->top==MAX-1;
}
void enqueue(queue *pq,int ele){
	if (isfull(pq)){
		printf("stack is full");
	}
	else{
		if (pq->front==-1){
			pq->front++;
			pq->rare++;
			pq->arr[pq->rare]=ele;
		}
		else{
			pq->rare++;
			pq->arr[pq->rare]=ele;
		}
	}
}
int dequeue(queue *pq){
	int temp=pq->arr[pq->front];
	printf("the element dequeued is:%d\n",temp);
	pq->front++;
	if (pq->front>pq->rare){
		pq->front=-1;
		pq->rare=-1;
	}
	return temp;
}
void push(struct stack *s,int ele){
    if (isfull(s)){
        printf("full stack");
    }
    else{
        s->arr[++(s->top)]=ele;
    }
}
int pop(struct stack *s){
    if (isempty(s)){
        printf("stack is empty");
    }
    else{
        return s->arr[s->top--];
    }
}
void reversequeue(queue *pq){
	struct stack s;
	init(&s);
	while (!isempty(pq)){
		push(&s,dequeue(pq));
	}
	while (!isempty(&s)){
		enqueue(pq,pop(&s));
	}
}
void displayqueue(struct queue *pq){
	for (int i=pq->front;i<=pq->rare;i++){
		printf("%d ",pq->arr[i]);
	}
	printf("\n");
}
int main(){
	queue pq=init();
	enqueue(&pq,10);
	enqueue(&pq,20);
	enqueue(&pq,30);
	printf("orginal queue:");
	displayqueue(&pq);
	reversequeue(&pq);
	printf("reversed queue:");
	displayqueue(&pq);
}
