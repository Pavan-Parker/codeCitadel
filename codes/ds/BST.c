#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * leftChild;
    struct Node * rightChild;    
};

struct Node* insertNode(struct Node* root,int data)
{
    struct Node* parent=root;
    struct Node* current=root;
    struct Node* newNode=(struct Node*)(malloc(sizeof(struct Node)));    
    newNode->data=data;
    newNode->leftChild=NULL;
    newNode->rightChild=NULL;
    int  direction;
    if(current==NULL){root=newNode;}
    else
    {
        while((current!=NULL))
        {
            // printf("%d",current->data);
            parent=current;
            if(current->data>=data){direction=0; current=current->leftChild;}        
            else{direction=1;current=current->rightChild;}        
        }
        if(direction==0){parent->leftChild=newNode;}
        else{parent->rightChild=newNode;}
    }
    return root;
}
void printInorder(struct Node* root)
{
    struct Node* current=root;    
    if(current!=NULL)
    {
        printInorder(current->leftChild);
        printf("%d->\t",current->data);
        printInorder(current->rightChild);
    }
    // printf("NULL->\t");
}
int main()
{
    struct Node* root=NULL;
    root=insertNode(root,10);
    printInorder(root);printf("\n");

    root=insertNode(root,11);
    printInorder(root);printf("\n");

    root=insertNode(root,7);
    printInorder(root);printf("\n");

    root=insertNode(root,9);
    printInorder(root);printf("\n");

    root=insertNode(root,15);
    printInorder(root);printf("\n");

    root=insertNode(root,8);
    printInorder(root);printf("\n");


    return 0;
}