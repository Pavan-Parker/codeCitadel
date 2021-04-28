#include<stdio.h>
struct Node
{
    int data;
    struct Node * leftChild;
    struct Node * rightChild;    
};

void insertNode(struct Node* root,int data)
{
    struct Node* temp=root;
    struct Node * newNode=(struct Node*)(malloc(sizeof(struct Node)));    
    newNode=&(struct Node){.data=data,.leftChild=NULL,.rightChild=NULL};

    while(!temp==NULL)
    {
        if(temp->data>=data){temp=temp->leftChild;}        
        else{temp=temp->rightChild;}        
    }
    temp=newNode;
}
void printInorder(struct Node* root)
{
    struct Node* temp=root;    
    while (!temp==NULL){}
}
int main()
{
    struct Node * root=NULL;
    insertNode(root,3);
    insertNode(root,1);
    insertNode(root,4);
    insertNode(root,9);
    insertNode(root,6);
    return 0;
}