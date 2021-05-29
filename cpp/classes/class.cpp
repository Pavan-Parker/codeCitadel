#include <bits/stdc++.h>
using namespace std;

class hmm
{
    public: //Access modifier

        int var;

        hmm()   //default constructor
        {
            cout << "default constructor"<< endl;
            hmm::var=1;
        }

        hmm(int var)    //parameterized constructor
        {
            hmm::var=var;
        }

        hmm(hmm &hmmGiven)     //Copt constructor  
        {
            hmm::var=hmmGiven.var;
        }

        ~hmm()
        {
            cout<<"destructor for hmm is called"<<endl;
        }

        void printVar();
};

class hmmChild:hmm{}

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
    
    hmm obj1Copy=obj1;
    obj1Copy.printVar();

    return 0;

}