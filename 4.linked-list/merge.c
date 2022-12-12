#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};


void create(int a[],int n,struct node *first){
struct node *last, *temp;

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

void display(struct node *first){
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

struct node * sortmerge(struct node *first, struct node *second){
struct node *third=NULL,*last=NULL;
if(first->data<second->data){
    third=first;
    last=first;
    first=first->next;
    last->next=NULL;
}
else{
    third=second;
    last=third;
    second=second->next;
    last->next=NULL;
}
while (first!=NULL && second!=NULL){
    if(first->data>second->data){
    last->next=second;
    last=second;
    second=second->next;
    last->next=NULL;
}
else{ 
   last->next=first;
    last=first;
    first=first->next;
    last->next=NULL;
}
if(first!=NULL){
    last->next=first;
}
else{
    last->next=second;
}
}

return third;
}
int main()
{
    struct node *first=NULL,*second=NULL, *third=NULL;
    first=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    int a[8]={2,5,8,9,15,18,26,30};
    int b[7]={1,3,12,14,20,22,25};
    create(a,8,first);
    display(first);
     create (b,7,second);
     display(second);
      third=sortmerge(first,second);
      display(third);
    return 0;
}