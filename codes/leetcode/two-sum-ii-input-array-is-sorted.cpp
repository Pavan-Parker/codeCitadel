#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> lookup;

        for (auto it = numbers.begin(); it < numbers.end(); it++)
        {

            if (lookup.find(*it) == lookup.end())
            {
                lookup[target - *it] = it - numbers.begin();
            }
            else
            {
                return {lookup.at(*it), (int)(it - numbers.begin())};
            }
        }
    }
};