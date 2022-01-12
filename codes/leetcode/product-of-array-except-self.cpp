#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> lr = {1};
        vector<int> rl = {1};
        
        for (const int itr : nums)
        {
            lr.push_back(itr*lr.back());
        }
        lr.pop_back();
        
    }
};