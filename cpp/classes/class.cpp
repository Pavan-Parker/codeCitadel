#include <bits/stdc++.h>
using namespace std;

class hmm
{
    public: //Access modifier
        int var;
        hmm()   //default constructor
        {
            cout << "default constructor"<< endl;
            var=1;
        }
        hmm(int var)    //parameterized constructor
        {
            hmm::var=var;
        }
        void printVar();
};

void hmm::printVar()    // out of class defination
{
    cout<<hmm::var<<endl;
}

int main()
{
    hmm obj1;
    obj1.printVar();
    hmm obj2(2);
    obj2.printVar();
    return 0;

}