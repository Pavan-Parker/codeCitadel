/*
* Psuedo-code
* 1. Maintain two arrays.
* 2. One goes left to right, which starts with 1 and following elements are LR(i) = LR(i-1) * input(i-1)
* 3. Similarly, a right to left array starting with 
*/





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
        int temp = 1;
        vector<int> output;
        for (auto itr = nums.begin(); itr != nums.end(); itr++)
        {
            temp = temp * (*itr);
            lr.insert(lr.end(), temp);
        }
        lr.erase(lr.end() - 1);

        temp = 1;
        for (auto itr = nums.rbegin(); itr != nums.rend(); itr++)
        {
            temp = temp * (*itr);
            rl.insert(rl.begin(), temp);
        }
        rl.erase(rl.begin());

        for (size_t i = 0; i < lr.size(); i++)
        {
            output.push_back(lr.at(i) * rl.at(i));
        }
        return output;
    }
};