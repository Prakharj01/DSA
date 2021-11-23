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

void delete(int index){
    struct node *p=first,*q;

    if (index==1){
        first=first->next;
        free(p);
    }
    else{
        int count=1;
        while(count!=index && p){
            q=p;
            p=p->next;
            count++;
        }
        if (p){
        q->next=p->next;
        free(p);
        }
    }
    
    }

int main()
{
    int a[8]={8,5,4,56,9,12,16,20};
    create(a,8);
    display();
    delete(5);
    display();
   
    return 0;
}