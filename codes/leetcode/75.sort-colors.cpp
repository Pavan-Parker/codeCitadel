    /*
    * @lc app=leetcode id=75 lang=cpp
    *
    * [75] Sort Colors
    */
    /*
    *======Psuedo Code=====
    * 1. Push 0's to front of
    * 2. 2's to back.
    * 3. let 1's stay.
    */
    // @lc code=start
    class Solution
    {
    public:
        void sortColors(vector<int> &nums)
        {
            int twoCount = 0;
            int temp;
            for (auto itr = nums.begin(); itr < nums.end()-twoCount;itr++)
            {
                if (*itr == 0)
                {
                    temp = *itr;
                    nums.erase(itr);
                    nums.insert(nums.begin(), temp);
                }
                else if (*itr == 2)
                {
                    temp = *itr;
                    nums.erase(itr);
                    nums.insert(nums.end(), temp);
                    itr--;
                    twoCount++;
                }
            }
        }
    };
    // @lc code=end
