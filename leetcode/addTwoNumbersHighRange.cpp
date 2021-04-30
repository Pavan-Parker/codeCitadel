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
        // cout<<"returns "<< x <<":"<<size<<endl;
        return vector <int>{x,size};

    }
    ListNode* split(int n)
    {
        int i=n;
        struct ListNode* root=new ListNode(0,NULL);
        struct ListNode* temp=root;
        while(1)
        {
            temp->val=i%10;
            i=i/10;
            if(i)
            {
                temp->next=new ListNode(0,NULL);
                temp=temp->next;
            }
            else{break;}

        }
        return root;

    }
    ListNode* addTwoNumbersOld(ListNode* l1, ListNode* l2)
    {
        vector<int>r1=concat(l1);
        vector<int>r2=concat(l2);
        int outl1=r1[0],outl2=r2[0],size1=r1[1],size2=r2[1];
        cout<< size1 << " : "<< outl1<<" and " <<size2 << " : "<< outl2 << endl;
        return split(outl1+outl2);
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *temp1=l1,*temp2=l2;
        ListNode *output=new ListNode(0);
        bool EOL1=false,EOL2=false;
        int size=0, val1=0,val2=0;
        int sum=0,carry=0;
        // while(!EOL)
        // {
        //     if(temp1->next==NULL){EOL=1;}
        //     if(temp2->next==NULL){EOL=2;}
        //     sum+=((temp1->val+temp2->val)*pow(10,size));            
        //     size++;
        // }
        while(!(EOL1&&EOL2))
        {
            if(EOL1){val1=0;}else{val1=temp1->val;}
            if(EOL2){val2=0;}else{val2=temp2->val;}
            =((val1+val2)*pow(10,size));            
            size++;
            if(!EOL1){temp1=temp1->next;}
            if(!EOL2){temp2=temp2->next;}
            EOL1=(temp1==NULL);
            EOL2=(temp2==NULL);
        }
        

        
    }
};

void printLL(ListNode* head)
{
    struct ListNode* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<< " -> ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
//    struct ListNode* head=new ListNode();
//    printLL(head);

//    struct ListNode* second=new ListNode(1);
//    head->next=second;
//    printLL(head);
   
//    struct ListNode* fourth=new ListNode(3);
//    printLL(head);
   
//    struct ListNode* third=new ListNode(2,fourth);
//    second->next=third;
//    printLL(head);

    Solution s;
    struct ListNode* x=s.split(9);
    struct ListNode* y=s.split(9999999991);
    cout<<s.concat(s.addTwoNumbers(x,y))[0]<<endl;

   return 0;

}