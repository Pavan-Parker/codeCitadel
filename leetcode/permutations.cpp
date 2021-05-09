#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int factorial(int x)
    {
        int prod=1;
        int temp=1;
        while (temp<=x)
        {
            prod*=temp;
            temp+=1;
        }
        return prod;
    }
    string getPermutation(int n, int k)
    {
        string s;
        int segment=factorial(n)/n;
        int whichSegment;
        whichSegment=
        return s;
    }
};
int main()
{
    Solution s;
    cout<<s.factorial(5)<<endl;
    return 0;
}