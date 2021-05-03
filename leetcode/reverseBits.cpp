#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t rev;
        for(int i=0;i<32;i++)
        {
            cout<<(n&1)<<" ";
            if(n&1){rev=(rev<<1)|1;}
            else{rev<<=1;}
            n>>=1;
        }

        return rev;
    }
};