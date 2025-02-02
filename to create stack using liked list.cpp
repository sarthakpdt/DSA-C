#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node * push(struct node *top,int ele){
	struct node *pnode=(struct node *)malloc(sizeof(struct node ));
	pnode->data=ele;
	if (top==NULL){
		top=pnode;
		pnode->next=NULL;
	}
	else{
		pnode->next=top;
		top=pnode;
	}
	return top;
}
struct node *pop(struct node *top){
	struct node *temp=top;
	printf("pop element:%d",temp->data);
	top=top->next;
	free(temp);
}
int main(){
	struct node *st;
	st=push(st,40);
	printf("pushed element:%d\n",st->data);
	st=pop(st);
	st=push(st,50);
	printf("pushed element is:%d\n",st->data);
	st=pop(st);
}
