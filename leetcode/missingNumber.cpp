#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp=nums[0],n=nums.size()+1;
        int des;
        switch (n%4)
        {
        case 0:
            des=n;
            break;
        case 1:
            des=1;
        case 2:
            des=n+1;
        case 3:
            des=0;
        }
        for(int i=1;i<nums.size();i++){temp^=nums[i];}
        return (des^temp)%(int)pow(2,(int)log2(des));
    }
};