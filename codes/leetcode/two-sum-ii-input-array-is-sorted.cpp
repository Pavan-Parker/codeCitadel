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
        vector<int> indices;

        for (const int it : numbers)
        {

            if (lookup.find(it) == lookup.end())
            {
                lookup[target - it] = &it - &numbers[0];
            }
            else
            {
                indices = {lookup.at(it) + 1, (int)(&it - &numbers[0] + 1)};
            }
        }
        return indices;
    }
};