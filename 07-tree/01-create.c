#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int element;
};
struct node *root = NULL;

struct queue
{
    int front;
    int rear;
    int size;
    struct node **q;
};

void create(struct queue *q1, int size)
{
    q1->q = (struct node **)malloc(size * sizeof(struct node *));
    q1->size = size;
    q1->front = q1->rear = 0;
}

void enqueue(struct queue *q1, struct node *data)
{
    if ((q1->rear + 1) % q1->size == q1->front)
    {
        printf("The queue is full");
    }
    else
    {
        q1->rear = (q1->rear + 1) % q1->size;
        q1->q[q1->rear] = data;
    }
}

struct node *dequeue(struct queue *q1)
{
    struct node *x = NULL;
    if ((q1->front) == q1->rear)
    {
        printf("Queue is empty");
    }
    else
    {
        q1->front = (q1->front + 1) % q1->size;
        x = q1->q[q1->front];
    }
    return x;
}
int isEmpty(struct queue q1){
if (q1.front==q1.rear){
    return 0;
}
return 1;
}

void createTree()
{
    struct node *p, *t;
    struct queue q1;
    create(&q1, 100);

    int x;
    printf("Enter root value: ");
    scanf("%d", &x);

    root=(struct node *)malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;
    root->element = x;
    enqueue(&q1, root);

    while (isEmpty(q1))
    {
        p = dequeue(&q1);
        printf("enter left child of %d ", p->element);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->element = x;
            t->left = t->right = NULL;
            p->right = t;
            enqueue(&q1, t);
        }
        printf("enter right child of %d ", p->element);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->element = x;
            t->left = t->right = NULL;
            p->right = t;
            enqueue(&q1, t);
        }
    }
}

void preorder(struct node *p){
    if (p){
        printf("%d\t",p->element);
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(struct node *p){
    if (p){
        preorder(p->left);
        printf("%d\t",p->element);
        preorder(p->right);
    }
}
void postorder(struct node *p){
    if (p){
        preorder(p->left);
        preorder(p->right);
        printf("%d\t",p->element);
    }
}
int main()
{
createTree();
preorder(root);
printf("\nPost Order ");
postorder(root);
    return 0;
}