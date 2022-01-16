/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
/*
 *========Psuedo Code========
 * 1.
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;
        int local_profit;
        bool gotit = false;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            local_profit = prices[i + 1] - prices[i];
            if (local_profit >= 0)
                if (!gotit)
                    gotit = true;
            else
                if(gotit)
                    max_profit+=
        }
        return max_profit;
    }
};
// @lc code=end
