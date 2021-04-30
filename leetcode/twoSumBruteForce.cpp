#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator counter;
        int counterIndex;
        vector<int> returnVector;
        for(int i=0;i<nums.size()-1;i++)
        { 
            cout << "at index = "<<i<< ", searching for" << target-nums[i]<<endl;
            counter=find(nums.begin()+i+1,nums.end(),target-nums[i]);
            if(counter!=nums.end())
            {
                counterIndex=find(nums.begin()+i+1,nums.end(),target-nums[i])-nums.begin();
                if(counterIndex!=i){returnVector={i,counterIndex};break;}
            }
            
        }
        return returnVector;

    }
};