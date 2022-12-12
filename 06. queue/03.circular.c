#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int rear;
    int front;
    int *q;
};

void create(struct Queue *q1, int size)
{
    q1->size = size;
    q1->q = (int *)malloc(size * sizeof(int));
    q1->rear =0;
    q1->front = 0;
}

void enqueue(struct Queue *q1, int x)
{
    if ((((q1->rear) + 1) % q1->size) == q1->front)
    {
        printf("The queue is full\n");
    }
    else
    {
        q1->rear = (q1->rear + 1) % q1->size;
        q1->q[q1->rear] = x;
    }
}

int dequeue(struct Queue *q1)
{
    int x = -1;
    if (q1->front != q1->rear)
    {
        q1->front = (q1->front + 1) % q1->size;
        x = q1->q[q1->front];
    }
    else
    {
        printf("Queue is Empty");
    }
    return x;
}


void Display(struct Queue q1)
{
    int i = q1.front + 1;
    do
    {
        printf("%d ", q1.q[i]);
        i = ((i + 1) % q1.size);
    } while (i != (q1.rear + 1) % q1.size);

    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    Display(q);
    printf("%d ", dequeue(&q));

    return 0;
}
