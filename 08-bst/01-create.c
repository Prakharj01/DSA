#include <stdio.h>
#include <stdlib.h>
struct node
{
    int element;
    struct node *left;
    struct node *right;
};
struct node *root;
void insert(int key)
{

    struct node *t = root;
    struct node *p;
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->element = key;
        root->left = root->right = NULL;
    }
    else
    {
        while (t != NULL)
        {
            p = t;
            if (key > t->element)
            {
                t = t->right;
            }
            else
            {
                t = t->left;
            }
        }
        t = (struct node *)malloc(sizeof(struct node));
        t->left = t->right = NULL;
        t->element = key;

        if (key > p->element)
        {
            p->right = t;
        }
        else if (key < p->element)
        {
            p->left = t;
        }
    }
}

void inorder(struct node *p)
{
    if (p)
    {
        inorder(p->left);
        printf("%d\t", p->element);
        inorder(p->right);
    }
}
int main()
{
    insert(10);
    insert(20);
    insert(8);
    insert(15);
    insert(5);
    inorder(root);
    return 0;
}