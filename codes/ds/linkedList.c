#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node * nextNode;
};
void createNode(struct Node * head, int value)
{
    struct Node *temp=head;
    while(temp->nextNode!=NULL){temp=temp->nextNode;}
    // struct Node *new=&(struct Node){.value=value, .nextNode=NULL};
    struct Node * new =(struct Node *) malloc(sizeof(struct Node));
    new->value=value;new->nextNode=NULL;
    temp->nextNode=new;
}
void print(struct Node *head)
{
    struct Node *temp=head;
    while(temp!=NULL){printf("%d -> ",temp->value);temp=temp->nextNode;}
    printf("NULL\n");
}

int main()
{
    struct Node *head=&(struct Node){.value=1,.nextNode=NULL};
    createNode(head,23);
    print(head);
}