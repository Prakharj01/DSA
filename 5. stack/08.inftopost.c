

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char data;
    struct Node *next;
}
    *top = NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    struct Node *t;
    char x = -1;
    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
int inprecedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 2;
    }
    if (ch == '*' || ch == '/')
    {
        return 4;
    }
    if (ch == '^')
    {
        return 5;
    }
    if (ch == '(')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int outprecedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    if (ch == '^')
    {
        return 6;
    }
    if (ch == '(')
    {
        return 7;
    }
    if (ch == ')')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int isOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char *InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (outprecedence(infix[i]) > inprecedence(top->data))
                push(infix[i++]);
            else
            {
                if (outprecedence(infix[i]) == inprecedence(top->data))
                {
                    pop();
                    i++;
                }
                else
                {
                    postfix[j++] = pop();
                }
            }
        }
    }
    while (top != NULL){
        postfix[j++] = pop();
        }
    postfix[j] = '\0';
    return postfix;
}
int main()
{

    char *infix = "((a+b)*c)-d^e^f";

    push('#');
    char *postfix = InToPost(infix);
    printf("%s ", postfix);
    return 0;
}