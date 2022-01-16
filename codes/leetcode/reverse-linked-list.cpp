/*
*============Psuedo Code==============
* 1. intialize prevptr to head and nextptr to next to it, sanity check for LL of size 0 or 1.
* 2. backup the nextptr->next to temp and set to to prevptr.
* 3. prevptr = nextptr; nextptr = temp; 
* 4. While temp is not nullptr, Repeat 2-4. 
* 5. 
*/

class Solution {
public: 
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = head;
        ListNode* nextNode = prevptr -> next;
        ListNode* returnHead = nullptr;
        bool isEmpty = True; 
        do{
            if (prevNode)
        }while(nextNode!=nullptr);
        return returnHead;    
    }
};
