#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * leftChild;
    struct Node * rightChild;    
};

void insertNode(struct Node* root,int data)
{
    struct Node* parent=root;
    struct Node* current=root;
    struct Node* newNode=(struct Node*)(malloc(sizeof(struct Node)));    
    newNode=&(struct Node){.data=data,.leftChild=NULL,.rightChild=NULL};
    int  direction;
    if(current==NULL){current=newNode;}
    else
    {
        while(!(current==NULL))
        {
            parent=current;
            printf("%d",current->data);
            if(current->data>=data){direction=0; current=current->leftChild;}        
            else{direction=1;current=current->rightChild;}        
        }
        if(direction==0){parent->leftChild=newNode;}
        else{parent->leftChild=newNode;}
    }
}
void printInorder(struct Node* root)
{
    struct Node* current=root;    
    while (!(current==NULL))
    {
        printInorder(current->leftChild);
        printf("%d -> ",current->data);
        printInorder(current->leftChild);
    }
    printf("\t done Printing\n");
}
int main()
{
    struct Node* root=NULL;
    insertNode(root,3);
    printInorder(root);
    insertNode(root,1);
    printInorder(root);
    insertNode(root,4);
    printInorder(root);
    insertNode(root,9);
    printInorder(root);
    insertNode(root,6);
    printInorder(root);
    return 0;
}