#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void print(vector<int> a)
{ 
  for (int i=0;i<(int)a.size();i++)
    cout<<a[i]<<" ";
  cout<<endl;
}
int main()
{
  vector<int> arr;
  for(int i=0;i<=5;i++)
    arr.push_back(i);
  print(arr);
  arr.assign(5,10);print(arr);
  arr.push_back(20);print(arr);
  arr.pop_back();print(arr);
  arr.insert(arr.begin(),5);print(arr);
  auto x=find(arr.begin(),arr.begin()+arr.size(),5);
  cout<<x-arr.begin()<<endl;
  replace(arr.begin(),arr.end(),5,50);print(arr);
}
