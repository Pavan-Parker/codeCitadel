#include<bits/stdc++.h>
using namespace std;
void substring(string s,int stepSize)
{
    for(int i=0;i<s.length()-stepSize;i++)
    {
        cout<<s.substr(i,stepSize+1)<<" ";     
    }
    cout<<endl;
}
int main()
{

    string s="abcdef";
    for(int i=s.length();i>=0;i--)
    {
        substring(s,i);
    }
}