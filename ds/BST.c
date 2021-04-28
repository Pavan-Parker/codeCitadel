#include<stdio.h>
struct Node
{
    int data;
    struct Node * leftChild;
    struct Node * rightChild;    
};

void insertNode(struct Node* root,int data)
{
    struct Node *parent=root,*current;
    struct Node *newNode=(struct Node*)(malloc(sizeof(struct Node)));    
    newNode=&(struct Node){.data=data,.leftChild=NULL,.rightChild=NULL};
    if()
    while(!current==NULL)
    {
        if(current->data>=data){current=current->leftChild;}        
        else{current=current->rightChild;}        
    }
    current=newNode;
}
void printInorder(struct Node* root)
{
    struct Node* current=root;    
    while (!current==NULL){}
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