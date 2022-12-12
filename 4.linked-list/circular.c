#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} * head;

void create(int a[], int n)
{
    int i;
    struct node *t, *last;
    head = (void *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct node *h)
{

    do
    {
        printf("%d-->", h->data);
        h = h->next;
    } while (h != head);
    printf("\n");
}

void Rdisplay(struct node *h)
{
    static int flag = 0;
    if (h != head || flag == 0)
    {
        flag = 1;
        printf("%d->", h->data);
        Rdisplay(h->next);
    }
    flag = 0;
}

void insert(int pos, int element, struct node *p)
{
    struct node *t;
    printf("\n");
    t = (struct node *)malloc(sizeof(struct node));
    t->data = element;
    if (pos == 0)
    {
        do
        {
            p = p->next;
        } while (p->next != head);
        p->next = t;
        t->next = head;
        head=t;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
int length(struct node *p)
{
int len=0;
do
{
len++;
p=p->next;
}while(p!=head);
return len;
}
int delete(struct node *p, int index)
{
    struct node *q;
    int i, x;
    if (index < 0 || index > length(head))
        return -1;
    if (index == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int a[] = {2, 3, 4, 5, 6};
    int n = 5;

    create(a, n);
    display(head);
    printf("Recursive Display\n");
    Rdisplay(head);
    insert(2, 99, head);
    display(head);
    delete(head,3);
    display(head);
    return 0;
    
}