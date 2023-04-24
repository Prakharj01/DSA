#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next=NULL;
    }
};

Node *insertBegin(Node *head ,int x){
      Node *temp= new Node(x);
      temp->next=head;
      return temp;
}
void rList(Node *head)
{
     if(head!=NULL) {
        cout<<(head->data)<<" ";
     rList(head->next);
     }
}
int main(){
    Node *head = NULL;
    head=insertBegin(head,50);
    head=insertBegin(head,40);
    head=insertBegin(head,30);
    head=insertBegin(head,20);
    head=insertBegin(head,10);
   rList(head);
    return 0;
}