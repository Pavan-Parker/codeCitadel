/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 *=====Psuedo Code=====
 * 1. iterate though both LL's and push all the nodes onto a respective stack.
 * 1.5 initialize temp to nullptr.
 * 2. compare top and pop if equal and store it in temp.
 * 3. if unequal, temp is the intersection.
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        stack<ListNode *> stackA, stackB;
        ListNode *node;
        ListNode *temp = nullptr;
        node = headA;
        while (node != nullptr)
        {
            stackA.push(node);
            node = node->next;
        }

        node = headB;
        while (node != nullptr)
        {
            stackB.push(node);
            node = node->next;
        }

        while (!(stackA.empty() || stackB.empty()))
        {
            if (stackA.top() == stackB.top())
                temp = stackA.top();
            else
                break;
            stackA.pop();
            stackB.pop();
        }
        return temp;
    }
};
// @lc code=end
