#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char title[20];
    char pub[20];
}book;
void insertbook(int *size,int position,book newbook,book **books){
    *books=(book *)realloc(*books,(*size+1)*sizeof(book));
    for (int i=*size;i>position;i--){
        (*books)[i]=(*books)[i-1];
    }
    (*books)[position]=newbook;
    (*size)++;
}
int main(){
    int size;
    book* books=NULL;
    printf("how many data in the book:");
    scanf("%d",&size);
    books=(book *)malloc(size*sizeof(book));
    for (int i=0;i<size;i++){
        printf("enter the title of book:");
        scanf("%s",books[i].title);
        printf("enter the pub of the book:");
        scanf("%s",books[i].pub);
    }
    int position;
    book newbook;
    printf("enter the posiiton:");
    scanf("%d",&position);
    printf("enter the title of newbook:");
    scanf("%s",newbook.title);
    printf("enter the publisher of newbook:");
    scanf("%s",newbook.pub);
    insertbook(&size,position,newbook,&books);
    for (int i=0;i<size;i++){
        printf("the title of the book is:%s\n",books[i].title);
        printf("the publisher of the book is:%s\n",books[i].pub);
    }
}
