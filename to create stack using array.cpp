#include <stdio.h>
#include<stdlib.h>
#define MAX 100
struct stack {
	int top;
	int arr[MAX];
};
void init(struct stack *s){
	s->top=-1;
}
int isfull(struct stack *s){
	return s->top==MAX-1;
}
int isempty(struct stack *s){
	return s->top==-1;
}
void push(struct stack *s,int ele){
	if (isfull(s)){
		printf("stack full");
	}
	else{
		s->arr[++(s->top)]=ele;
	}
}
void pop(struct stack *s){
	if (isempty(s)){
		printf("stack empty");
	}
	else{
		int value=s->arr[s->top--];
		printf("the pop element is:%d\n",value);
	}
} 
int main(){
	struct stack s;
	init(&s);
	push(&s,10);
	push(&s,20);
	pop(&s);
	pop(&s);
}
