#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,vector<int>> map;
        for(int i=0;i<s.length();i++)
        {
            auto found=map.find(s[i]);
            if(found!=map.end())
            {
                if((found->second[1]-found->second[0])>(i-found->second[1]) ){}
            }
        }
        
    }
};