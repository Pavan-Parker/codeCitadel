#include<bits/stdc++.h>
using namespace std;

class Matrix
{
    public:
    vector<vector<int>> vec;
    Matrix()
    {
        vector<int> row={0,0,0};
        vector<vector<int>> temp={row,row,row};
        this->vec=temp;
    }
    void putVec(vector<vector<int>> vec)
    {
        this->vec=vec;
    }

    void getVec()
    {
        for(auto& itr : this->vec)
        {
            for(auto& itr2:itr)
            {
                cout<<itr2<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
    }

    Matrix operator+ (Matrix y)
    {
        Matrix something;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                something.vec[i][j]=(this->vec[i][j])+(y.vec[i][j]);        
            }            
        }    
        return something;
    }
};

int main()
{
    vector<int> row={0,0,0};
    vector<vector<int>> vec={row,row,row};
    
    for(auto& itr : vec)
    {
        for(auto& itr2:itr)
        {
            cin>>itr2;
        }
    }

    Matrix p,q;
    p.putVec(vec);q.putVec(vec);
    p.getVec();
    Matrix r=p+q;
    r.getVec();
    return 0;
}