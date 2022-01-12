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
        for (auto itr = nums.begin(); itr != nums.end(); itr++)
        {
            lr.insert(lr.end(), (*itr) * lr.back());
        }
        lr.erase(lr.end()-1);

        for (auto itr = nums.rbegin(); itr != nums.rend(); itr++)
        {
            rl.insert(rl.begin(), (*itr) * (rl.front()));
        }
        rl.erase(rl.begin());

        for (size_t i = 0; i < lr.size(); i++)
        {
            output.push_back(lr.at(i) * rl.at(i));
        }
        return output;
    }
};