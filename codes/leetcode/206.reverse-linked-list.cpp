/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
* =============== Pseudo Code ===================
* 1. Initialize prevptr to NULL, nextptr to head;
! 1.5 return head if nextptr is NULL;
* 2. Backup nextptr->next to temp; 
* 3. Set nextptr-> next to prevptr;
* 4. prevptr = nextptr;
* 5. nextptr = temp;
* 6. Repeat Step 2 to 5 if nextptr in step 5 is NOT NULL;
! 7. return nextptr;
*/
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prevptr = nullptr, *nextptr = head, *temp;
        while (nextptr != nullptr)
        {
            temp = nextptr->next;
            nextptr->next = prevptr;
            prevptr = nextptr;
            nextptr = temp;
        }
        return prevptr;
    }
};
// @lc code=end
