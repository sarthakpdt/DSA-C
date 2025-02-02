#include <stdio.h>
#include<stdlib.h>
#define MAX 100
struct stack{
    int top;
    int arr[MAX];
};
void init(struct stack *s){
    s->top=-1;
}
int isempty(struct stack *s){
    return s->top==-1;
}
int isfull(struct stack *s){
    return s->top==MAX-1;
}
void push(struct stack *s1,struct stack *s2,int ele){
    if (isfull(s1)){
        printf("full stack");
    }
    else{
        s1->arr[++(s1->top)]=ele;
        if (isempty(s2) || ele>=s2->arr[s2->top]){
        	s2->arr[++(s2->top)]=ele;
		}
    }
}
void pop(struct stack *s1,struct stack *s2){
    if (isempty(s1)){
        printf("stack is empty");
    }
    else{
        int value=s1->arr[s1->top--];
        if (value==s2->arr[s2->top]){
        	s2->top--;
		}
		printf("%d",value);
    }
}
void printStack(struct stack *s1) {
    if (isempty(s1)) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i=0;i<=s1->top;i++){
        printf("%d ",s1->arr[i]);
    }
    printf("\n");
}
int getMaximum(struct stack *s2) {
    if (isempty(s2)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s2->arr[s2->top]; 
}
int main(){
    struct stack s1,s2;
    init(&s1);
    init(&s2);
    push(&s1,&s2,10);
    push(&s1,&s2,20);
    push(&s1,&s2,30);
	printStack(&s1);
	printf("%d",getMaximum(&s2));
}
