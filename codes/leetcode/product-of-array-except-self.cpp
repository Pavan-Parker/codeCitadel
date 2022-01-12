#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> lr = {1};
        vector<int> rl = {1};
        vector<int> output;
        for (const int& itr : nums)
        {
            lr.push_back(itr * lr.back());
        }
        lr.erase(lr.end());

        for (auto itr = nums.rbegin(); itr < nums.rend(); itr++)
        {
            rl.insert(lr.begin(), (*itr) * (lr.front()));
        }
        rl.erase(lr.begin());

        for (size_t i = 0; i < lr.size(); i++)
        {
            output.push_back(lr.at(i) * rl.at(i));
        }
        return output;
    }
};