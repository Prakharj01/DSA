#include<stdio.h>
#include<stdlib.h>

struct queue{
int front;
int rear;
int *q;
};
    struct queue q1,q2,q3;

void create(){
    q1.q=(int *)malloc(7*sizeof(int));
    q1.front=q1.rear=-1;

    q2.q=(int *)malloc(7*sizeof(int));
    q2.front=q2.rear=-1;

    q3.q=(int *)malloc(7*sizeof(int));
    q3.front=q3.rear=-1;
}


void push(char *set, int *priority){
    for (int i=0;i<len(priority);i++){
        if (priority[i]==1){
            q1.q[q1.rear++]=set[i];
        }

        if (priority[i]==2){
            q2.q[q2.rear++]=set[i];
        }

        if (priority[i]==3){
            q3.q[q3.rear++]=set[i];
        }
    }
}


int main()
{
    create();
    char ch[]={'A','B','C','D','E','F','G','H','I','J','K','L'};
    int prior[]={1,1,2,3,2,1,2,3,2,2,1,1};

push(ch,prior);
printf("%s",q1.q);
printf("%s",q2.q);
printf("%s",q3.q);
    return 0;

}