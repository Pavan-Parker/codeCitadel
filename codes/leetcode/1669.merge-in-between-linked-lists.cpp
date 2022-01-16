/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
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
*===========Psuedo Code============
* 1. Intialize temp to head. i to 0.
* 2. traverse temp through LL and increment i till it is equal to a-1.
* 3. backup b->next to temp2. 
* 4. temp -> next = j;
* 5. while (temp->next != NULL)
*       temp = temp-> next;
* 6. temp-> next = temp2;
* 7. return head
*/
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *temp = list1;
        ListNode *startBackup=nullptr;
        ListNode *endBackup=nullptr;
        int i = 0;
        while (i<=b)
        { 
            if(i == (a - 1))
                startBackup = temp;
            temp = temp->next;
            i++;
        }
        endBackup = temp->next;
        startBackup -> next = list2;
        temp = startBackup->next;
        while (temp!=nullptr)
            temp = temp->next;
        temp->next = endBackup;
        return list1;
    }
};
// @lc code=end
