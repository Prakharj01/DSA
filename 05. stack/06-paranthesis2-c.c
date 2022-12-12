#include<stdio.h>

#include<stdlib.h>
#include<string.h>


struct node{
char element;
struct node *next;
};
struct node *top=NULL;

void push(char ch){
struct node *ptr=(void *)malloc(sizeof(struct node));

ptr->element=ch;
ptr->next=top;
top=ptr;

}
int pop(char ch){
if (top->element==ch){
struct node *ptr=top;
top=top->next;
free(ptr);
return 1;
}
else{
    printf("Not an valid expression");
    return 0;
}
}

void display(){
  struct node *p;

    p = top;

    while (p != NULL)
    {
        printf("%d ", p->element);
        p = p->next;
    }
    printf("\n");
}


int isBalanced(char *exp){
int res=1;
char temp;
for (int i=0;i<strlen(exp);i++){
    if (exp[i]=='{' || exp[i]=='[' || exp[i]=='(' || exp[i]=='<'){
push(exp[i]);
    }
    else if (exp[i]=='}' || exp[i]==']' || exp[i]==')' || exp[i]=='>'){
        if ((int)exp[i]<50){
        res=pop((char)exp[i]-1);
        }
        else if (((int)exp[i]>90)){
            res=pop((char)exp[i]-2);

        }
    }
    if (res==0){
        return res;
        break;
    }

}
printf("It is a valid expression\n");
return 1;
}
int main(){

char *exp="{([a+b]*[c-d])/e}";
printf("%d",isBalanced(exp));
    return 0;
}