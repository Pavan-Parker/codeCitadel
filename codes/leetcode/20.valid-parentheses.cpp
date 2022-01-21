#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
/*
 *====Psuedo Code====
 * 1. Stack using Linked List
 * 1a. Initialize a LL to null.
 * 1b. push = add node to the start i.e. newNode->val = val; newNode->next= head; head = newNode;
 * 1c. pop = return head->val; head = head->next;
 * 2. push incoming opening parenthesis.
 * 3. pop if the incoming closing parenthesis matches the top else return false.
 * 4. Repeat while not EOL.
 */
// @lc code=start
class Node
{
public:
    int val;
    Node *next;

    Node()
    {
        next = nullptr;
    }
};
class LLStack
{
public:
    Node *head = nullptr;
    void push(int val)
    {
        Node *newNode;
        newNode->val = val;
        newNode->next = head;
        head = newNode;
    }
    int pop()
    {
        int ret = head->val;
        head = head->next;
        return ret;
    }
};
class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> pair({{')', '('},
                                        {'}', '{'},
                                        {']', '['}});
        LLStack stack;
        for (const auto ch : s)
        {
            if (pair.find(ch) != pair.end())
            {
                if (stack.pop() != pair[ch])
                    return false;
            }
            else
                stack.push(ch);
        }
        return true;
    }
};
// @lc code=end
