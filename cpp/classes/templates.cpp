#include <bits/stdc++.h>
using namespace std;

template <typename T>
T addIt (T a,T b)
{
    return a+b;
}

int main()
{
    cout<<addIt<int>(1.0,2.0)<<endl;
    cout<<addIt<float>(1.0,2.0)<<endl;
    cout<<addIt<char>(1.0,2.0)<<endl;
    
}