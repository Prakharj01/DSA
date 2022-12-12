#include<stdio.h>
#include<stdlib.h>

struct listnode{
char element;
struct listnode *next;
};
struct listnode *top=NULL;


void push(char x){
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
            printf("%c ",p->element);
            p=p->next;
        }
    }

    int isBalanced(char *exp){
        for (int i=0;exp[i]!='\0';i++){
        if (exp[i]=='(') push('(');
        else if (exp[i]==')'){
            if (top==NULL){
                return 0;
            }
            pop();
        }

        }
               
               return top==NULL?1:0;
    }
int main()
{
    char *exp="((a+b)*(c-d))";
    printf("%s",isBalanced(exp)?"It is balanced":"It is not balanced\n");
    display();

    return 0;
}