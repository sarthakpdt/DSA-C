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
    }
    else{
        int value=s->arr[s->top--];
        return value;
    }
}
void copy(struct stack *s1,struct stack *s2){
    if (!isempty(s1)){
        int ele=pop(s1);
        copy(s1,s2);
        push(s2,ele);
        push(s1,ele);
    }
}
int main(){
    struct stack s;
    init(&s);
    push(&s,10);
    push(&s,20);
    struct stack q;
    init(&q);
    copy(&s,&q);
    printf("%d",pop(&q));
    printf("%d",pop(&q));
}
