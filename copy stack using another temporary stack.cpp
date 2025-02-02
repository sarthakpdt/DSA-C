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
        printf("full stack");
    }
    else{
        s->arr[++(s->top)]=ele;
    }
}
int pop(struct stack *s){
    if (isempty(s)){
        printf("stack is empty");
        return -1;
    }
    else{
        int value=s->arr[s->top--];
        return value;
    }
}
struct stack *cpy(struct stack *s1,struct stack *s2,struct stack *temp){
    while (!isempty(s1)){
        push(temp,pop(s1));    
    }
    while (!isempty(temp)){
        push(s2,pop(temp));
    }
    return s2;
}
int main(){
    struct stack s;
    init(&s);
    push(&s,10);
    push(&s,20);
    struct stack q;
    init(&q);
    struct stack temp;
    init(&temp);
    cpy(&s,&q,&temp);
    printf("%d",pop(&q));
    printf("%d",pop(&q));
}
