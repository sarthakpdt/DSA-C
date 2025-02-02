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
void push(struct stack *s,int ele){
    if (isfull(s)){
        printf("full stack\n");
    }
    else{
        s->arr[++(s->top)]=ele;
    }
}
int pop(struct stack *s){
    if (isempty(s)){
        printf("stack is empty\n");
        return -1;
    }
    else{
        return s->arr[s->top--];
    }
}
void dltmiddleele(struct stack *s,int currentindex,int middleindex){
	if (currentindex==middleindex){
		pop(s);
		return;
	}
	int temp=pop(s);
	dltmiddleele(s,currentindex+1,middleindex);
	push(s,temp);
}
void printStack(struct stack *s) {
    if (isempty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i=0;i<=s->top;i++){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}
int main(){
    struct stack s;
    init(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    int n=s.top+1;
    int middleele=n/2;
    printf("orginal stack:\n");
    printStack(&s);
    dltmiddleele(&s,0,middleele);
    printStack(&s);
}
