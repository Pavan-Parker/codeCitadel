#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    Node* next;
};
void printAll(Node* x)
{
  while(x!=NULL)
  {
    cout<<x->data<<" -> ";
    x=x->next;
  }
  cout<<"NULL"<<endl;
}
Node* addNode(Node* x,int value, int n)
{ 
  
  Node* temp=new Node();
  Node* y=new Node();
  if(n==0){y->next=x;y->data=value;free(temp);return y;}
  else
  {
    temp=x;
    for (int i=0;i<n-1;i++){temp=temp->next;}
    y->next=temp->next;
    temp->next=y;
    y->data=value;
    //free(temp);
    return x;
  }
}
Node* deleteNode(Node* x, int n)
{
  Node* temp=new Node();temp=x;
  if(n==0){free(temp);return x->next;}
  else
  {
    for(int i=0;i<n-1;i++){temp=temp->next;}
    temp->next=(temp->next)->next;
    free(temp);
    return x;
  }
}

Node* addNodeAlt(Node* x,int value, int n)
{ 
  
  Node** temp=&x;
  Node* y=new Node();
  if(n==0){y->next=x;y->data=value;free(temp);return y;}
  else
  {
    for (int i=0;i<n-1;i++){x=x->next;}
    y->next=x->next;
    x->next=y;
    y->data=value;
    x=*temp;
    free(temp);
    return x;
  }
}

Node* deleteNodeAlt(Node* x, int n)
{
  Node** temp=&x;
  if(n==0){free(temp);return x->next;}
  else
  {
    for(int i=0;i<n-1;i++){x=x->next;}
    x->next=(x->next)->next;
    x=*temp;
    free(temp);
    return x;
  }
}


int main()
{
  Node* head=new Node();
  Node* second=new Node();
  Node* third=new Node();
  head->data=12;
  second->data=123;
  third->data=1234;
  head->next=second;
  second->next=third;
  third->next=NULL;
  printAll(head);
  head=addNode(head,1,0);
  printAll(head);
  head=addNode(head,12345,4);
  printAll(head);
  head=addNode(head,12344,4);
  printAll(head);
  deleteNodeAlt(head,1);
  printAll(head);
}
