#include<stdio.h>
#include "to create stack using array.cpp" 
typedef struct QueueUsingStacks{
    stack s1, s2;  
}queue;
void initQueue(queue *q){
    init(&(q->s1)); 
    init(&(q->s2));  
}
void enqueue(queue *q, int value){
    push(&(q->s1), value);  
    printf("Enqueued: %d\n", value);
}
int dequeue(queue *q){
    if(isEmpty(&(q->s2))){  
        while(!isEmpty(&(q->s1))){
            push(&(q->s2), pop(&(q->s1)));
        }
	}
    if(isEmpty(&(q->s2))){
        printf("Queue is empty\n");
        return '\0';
    }
    return pop(&(q->s2));  
}

