#include<stdio.h>
#include<stdlib.h>

struct listnode{
int element;
struct listnode *next;
};
struct listnode *top=NULL;


void push(int x){
    struct listnode *ptr;
    ptr=(struct listnode *)malloc(sizeof(struct listnode));
    ptr->element=x;
    ptr->next=top;
    top=ptr;
}

int pop(){
    int x=-1;
    struct listnode *p;
        p=top;
    if (top==NULL){
        printf("Stack Underflow");
    }
    else{
        top=top->next;
        x=p->element;
        free(p);
    }
    return x;
}

    void display(){
        struct listnode *p;
        p=top;
        while(p!=NULL){
            printf("%d ",p->element);
            p=p->next;
        }
    }

int main()
{
    push(2);
    push(3);
    push(23);
    push(25);
    push(28);

    display();
    return 0;
}