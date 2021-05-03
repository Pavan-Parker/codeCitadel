#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t rev,allOnes=0xFFFFFFFF;
        for(int i=0;i<31;i++)
        {
            if(n&1){rev=(rev>>1)|allOnes;}
            else{rev>>=1;}
        }

    }
};