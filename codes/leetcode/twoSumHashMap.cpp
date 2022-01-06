#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int complement;
        vector<int> returnVector;

        for(int i=0;i<nums.size()-1;i++)
        { 
            complement=target-nums[i];
            cout << "at index = "<<i<< ", searching for" << complement <<endl;

            if(map.find(complement)!=map.end()){    returnVector={i,map[complement]};   break;}
            else{map[nums[i]]=i;}
        }            
        
        return returnVector;
    }
};