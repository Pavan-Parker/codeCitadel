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
    vector<int> concat(ListNode* l)
    {
        ListNode* temp=l;        
        int x=0,size=0;

        while(temp!=NULL)
        {
            x+=((temp->val)*pow(10,size));
            size++;
            temp=temp->next;
        }

        return vector <int>{x,size};

    }
    ListNode* split(int n)
    {
        int i=n;
        struct ListNode* root=new ListNode(0,NULL);
        struct ListNode* temp=root;
        while(i)
        {
            temp->val=i%10;
            temp->next=new ListNode(0,NULL);
            temp=temp->next;
            i=i/10;
        }
        return root;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int outl1,outl2,size1,size2;
        vector<int>{outl1,size1}=concat(l1);
        vector<int>{outl2,size2}=concat(l2);
        return split(outl1+outl2);
        
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