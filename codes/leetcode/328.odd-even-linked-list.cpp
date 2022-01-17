/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
 *=====Psuedo Code=====
 * 1. find first even and odd nodes and store them.
 * 2. chain all the others.
 * 3. Attach even head to odd end.
 */
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *evenHead = nullptr, *oddHead = nullptr;
        ListNode *evenItr, *oddItr;
        ListNode *itr = head;
        int i = 0;
        if(itr == nullptr)
            return nullptr;
        while (itr != nullptr)
        {
            if ((i) % 2)
            {
                if (oddHead == nullptr)
                {
                    oddHead = itr;
                    oddItr = oddHead;
                }
                else
                {
                    oddItr->next = itr;
                    oddItr = oddItr->next;
                }
            }

            else
            {
                if (evenHead == nullptr)
                {
                    evenHead = itr;
                    evenItr = evenHead;
                }
                else
                {
                    evenItr->next = itr;
                    evenItr = evenItr->next;
                }
            }
            i++;
            itr = itr->next;
        }

        if(evenItr != nullptr)
            evenItr->next = oddHead;
        if(oddItr != nullptr)
            oddItr->next = nullptr;
        return evenHead;
    }
};
// @lc code=end
