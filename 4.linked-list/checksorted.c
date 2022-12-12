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

void checksorted(){
    struct node *p=first;
    int temp=1,prev=p->data;
    while(p->next!=NULL){
        prev=p->data;
        p=p->next;

    if (prev > p->data){
        temp=-1;
        break;
    }
    

    }
    if (temp==-1){
        printf("Not sorted linked list\n");
    }
    else{
        printf("Sorted linked list\n");
    }
}

int main()
{
    int a[8]={2,5,6,7,12,20,29,49};
    int b[8]={2,5,6,71,12,20,29,49};
    create(a,8);
    display();

    struct node *p=first;
    checksorted();


    create(b,8);
    display();
    checksorted();
    return 0;
}