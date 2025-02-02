#include<stdio.h>
#define MAX 5
struct stack{
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
		printf("stack is full");
	}
	else{
		s->arr[++(s->top)]=ele;
	}
	printf("the element pushed is:%d\n",ele);
}
int pop(struct stack *s){
	int temp=s->arr[s->top--];
	return temp;
	
}
void createarray(struct stack *s1,struct stack *s2,int arr[]){
	int i=0;
	while (!isempty(s1)){
		arr[i++]=pop(s1);
	}
	while (!isempty(s2)){
		arr[i++]=pop(s2);
	}
}
int main(){
	struct stack s;
	init(&s);
	push(&s,20);
	push(&s,30);
	struct stack q;
	init(&q);
	push(&q,40);
	push(&q,50);
	int arr[4];
	createarray(&s,&q,arr);
	printf("the array is:\n");
	for (int i=0;i<4;i++){
		printf("%d  ",arr[i]);
	}
}
