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

void recursivedisplay(struct node *p){
    if(p->next==NULL){
        printf("%d", p->data);
    }
    else{
        printf("%d-->",p->data);
        p=p->next;
        recursivedisplay(p);
    }
}

int recursivecount(struct node *p){
    if(p==0){
        return 0;
    }
    else{
        return recursivecount(p->next) + 1;
    }
}
int main()
{
    int a[8]={8,5,4,56,9,12,16,20};
    create(a,8);
    display();

    struct node *p=first;
    printf("\nRecursive function\n");
    recursivedisplay(p);
    printf("\nCounting using recursion:\n");
    int count;
    count=recursivecount(p);

    printf("The number of elements is %d ", count);
    return 0;
}