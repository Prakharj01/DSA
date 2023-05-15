#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
}*first=NULL;

void create(int a[],int n){
struct node *last, *temp;
first=(struct node *)malloc(sizeof(struct node));
first->data=a[0];
first->next=NULL;
last=first;


for(int i=1;i<n;i++){
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a[i];
    temp->next=NULL;
    last->next=temp;
    last=temp;
}
}

void display(){
struct node *temp;
temp=first;
int count=1;

while(temp->next!=NULL){
    printf("%d-->", temp->data);
    temp=temp->next;
    count++;
}
printf("%d",temp->data);
printf("\nThe number of elements is %d. \n",count);
}
void duplidelete(){
    struct node *p=first,*q;
    int temp=p->data;
    q=p;
    p=p->next;
    while(p){
        if(temp==p->data){
            q->next=p->next;
            free(p);
            p=q->next;
        }
        else{
        q=p;
        temp=p->data;
        p=p->next;
        }

    }

}

int main()
{
    int a[8]={8,8,12,19,19,19,19,23};
    create(a,8);
    display();

    struct node *p=first;
    duplidelete();
    display();
    return 0;
}