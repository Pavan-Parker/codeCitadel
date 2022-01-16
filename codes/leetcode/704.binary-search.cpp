/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

/*
*=========Psuedo Bank==========
* 1. Initialize start and end
* 2. midIndex = (start + end+1)/2
* 3. midElement = input[midIndex]
* 4. if (midElement == target): 
*       return midIndex;
* 5. else if (midElement > target):
*       end = midIndex;
* 6. else:
*       start = midIndex;
* 7. Repeat until (start == end),repeat 2-6

*/
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int midIndex;
        int mid;
        if (!nums.size())
            return -1;
        while (true)
        {
            if ((end - start) <= 1)
            {
                if (nums[start] == target)
                    return start;
                else if (nums[end] == target)
                    return end;
                else
                    return -1;
            }

            midIndex = (start + end) / 2;
            mid = nums[midIndex];

            if (target == mid)
                return midIndex;
            else if (target < mid)
                end = midIndex;
            else
                start = midIndex;
        }
    }
};
// @lc code=end
