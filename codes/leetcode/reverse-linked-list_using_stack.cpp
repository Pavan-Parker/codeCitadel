/*
*======Psuedo Code========
* 1. Push all the Nodes onto a stack till NULL is detected.
* 2. Pop each of them and link to next.
*/

class Solution {
public: 
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<ListNode*> addresses; 
        while (temp != nullptr)
        {
            addresses.push(temp);
            temp = temp-> next;
        }
        
        int isHead = 1;
        ListNode* returnHead=nullptr;
        while(!addresses.empty())
        {
            
            if (isHead)
            {
                returnHead = addresses.top();
                addresses.pop();
                temp = returnHead;
                isHead = 0;
            }
            
            else
            {
                temp -> next =  addresses.top();
                addresses.pop();
                temp = temp -> next;                
            }

        }
        if (!isHead)
        {
            temp->next = nullptr;
        }
        return returnHead;    
    }
};
