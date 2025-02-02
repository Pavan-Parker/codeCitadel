// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void swap(int* p,int *q)
    {
        int temp;
        temp=*p;
        *p=*q;
        *q=temp;
    }
    void convertToWave(int *arr, int n){
        
        int i,lim=n%2;
        for(i=0;!(!(lim) && i==n) && !(lim && i==n-1);i+=2)
        {
            swap(&arr[i],&arr[i+1]);
        }
        cout<<endl;
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        int a[n]; //declare array of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        Solution ob;
        ob.convertToWave(a, n);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}  // } Driver Code Ends