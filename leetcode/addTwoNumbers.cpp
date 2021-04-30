#include<bits/stdc++.h>
using namespace std;
// class ListNode
// {
//     public:   
//         int val;
//         ListNode * next;
//         ListNode(){val=0;next=NULL;}
//         ListNode(int data){val=data;next=NULL;}
//         ListNode(int data,ListNode *nextNode){val=data;next=nextNode;}
              
// };
struct ListNode
{
    // public:   
        int val;
        ListNode * next;
        ListNode(){val=0;next=NULL;}
        ListNode(int data){val=data;next=NULL;}
        ListNode(int data,ListNode *nextNode){val=data;next=nextNode;}
              
};

class Solution {
public:
    int concat(ListNode* l)
    {
        ListNode* temp=l;        
        int size;
        while(temp!=NULL)
        {
            temp=temp->next;
        }

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {

    }
};
void printLL(ListNode* head)
{
    ListNode* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<< " -> ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
   struct ListNode* head=new ListNode();
   printLL(head);

   struct ListNode* second=new ListNode(1);
   head->next=second;
   printLL(head);
   
   struct ListNode* fourth=new ListNode(3);
   printLL(head);
   
   struct ListNode* third=new ListNode(2,fourth);
   second->next=third;
   printLL(head);
   
   return 0;
}