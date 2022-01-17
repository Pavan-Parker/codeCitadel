#include <iostream.h>
#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */
/*
 *=====Psuedo Code=====
 * 1. for _ in k:
 * 2.    temp = pop(input);
 * 3.    input.insert(0, temp);
 */
// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % (nums.size());
        cout << "k:" << k << endl;
        cout << "selection:";
        for (auto i = k; i > 0; i--)
            cout << *(nums.end() - i) << " ";
        cout << endl;

        nums.insert(nums.begin(), (nums.end() - k), nums.end());
        cout << "after insertion :";
        for (const auto itr : nums)
            cout << itr << " ";
        cout << endl;
        nums.erase((nums.end() - k), nums.end());
        cout << "after deletion :";
        for (const auto itr : nums)
            cout << itr << " ";
        cout << endl;
    }
};
// @lc code=end
