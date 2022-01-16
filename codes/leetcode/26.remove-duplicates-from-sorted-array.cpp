/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
/*
 * Psudo-Code
 * 1. Start both on initial.
 * 2. Keep on incrementing j until j's value is more than i's.
 * 3. Write it to next to i's.
 * 4. Repeat 2 until end of the range.
 */

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int iPos = 0;
        int jPos = 1;
        if(!nums.size())
            return 0;
        while (jPos < nums.size())
        {
            if ((nums[jPos]) <= (nums[iPos]))
                jPos++;
            else
            {
                iPos++;
                nums[iPos] = nums[jPos];
            }
        }
        return iPos+1;
    }
};
// @lc code=end
