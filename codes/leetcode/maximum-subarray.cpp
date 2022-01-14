/*
* 
* ===========
* Psuedo-code
* ===========
* Kadane's Algoithm says that 
* 1. local_max[i] = max(in[i], in[i]+ local_max[i-1])
* 2. global_max = max(local_max[::])
* 
*/
#include <iostream.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global_max = INT_MIN;
        int local_max, past_local_max = 0;
        
        for(const auto itr : nums)
        {
            local_max = max(itr, itr + past_local_max);
            if(global_max<local_max)
                global_max = local_max;
            past_local_max = local_max;
        }
        return global_max;
    }
};