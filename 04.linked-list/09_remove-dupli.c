#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node *next;
}*first=NULL;

void create(int a[],int n){
struct Node *last, *temp;
first=(struct Node *)malloc(sizeof(struct Node));
first->data=a[0];
first->next=NULL;
last=first;


for(int i=1;i<n;i++){
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=a[i];
    temp->next=NULL;
    last->next=temp;
    last=temp;
}
}

void display(){
struct Node *temp;
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
    struct Node *p=first,*q;
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
        temp=q->data;
        p=p->next;
        }

    }

}

int main()
{
    int a[8]={8,8,12,19,19,19,19,23};
    create(a,8);
    display();

    struct Node *p=first;
    duplidelete();
    display();
    return 0;
}