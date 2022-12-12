#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    struct node *next;
    int data;
}*first=NULL;
void create(int a[],int n){
struct node *t, *last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        last->next=t;
        t->data=a[i];
        last=t;
        last->next=NULL;

    }
}

void display(struct node *p){
    
    while(p){
        printf("%d-->",p->data);
        p=p->next;
    }
    printf("\n");
}
int lengthnode(struct node *p){
    int length=0;
    while (p){
        length++;
        p=p->next;
    }
    return length;
}

void insert(int pos,int element){
    struct node *temp;
    struct node *p=first;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=element;
    if(pos ==0){
        first->prev=temp;
        temp->prev=NULL;
        temp->next=first;
        first=temp;
    }
    else{

        for(int i=0;i<pos-2;i++){
            p=p->next;

        }
        temp->next=p->next;
        p->next->prev=temp;
        p->next=temp;
        temp->prev=p;

    }
}
int delete(int pos){
    struct node *temp,*p,*q;
    p=first;
    int element;
    if (pos<1 || pos>lengthnode(p)){
        return -1;
    }
   else if (pos==1){
        first->data=element;
        temp=first;
        first=first->next;
        free(temp);
        first->prev=NULL;

    }
    else {
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        temp=p->prev;
        q=p->next;
        temp->next=q;
        q->prev=temp;
        

element=p->data;
(p->prev)->next=p->next;
if(p->next){
p->next->prev=p->prev;
    }

    free(p);
    }
    return element;
}


void Reverse(struct node *p)
{
struct node *temp;
while(p!=NULL)
{
temp=p->next;
p->next=p->prev;
p->prev=temp;
p=p->prev;
if(p!=NULL && p->next==NULL)
first=p;
}
}
int main()
{
    int a[]={2,4,6,8,10,12};
    
    create(a,6);
    display(first);
    int length=lengthnode(first);
    printf("Length is %d. \n",length);
    printf("Inserting in a list \n");
    // insert(4,20);
    // display(first);
    // int deletee=delete(6);
    // printf("Deleting in a list \n");
     display(first);

    // if (deletee==-1){
    //     printf("Index beyond the list ");
    // }

    Reverse(first);
    display(first);
    return 0;
}