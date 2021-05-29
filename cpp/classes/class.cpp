#include <bits/stdc++.h>
using namespace std;

class hmm
{
    protected:
        int var;
        int privateVar;
    public: //Access modifier
        
        //default constructor
        hmm(){
            cout << "default constructor"<< endl;
            hmm::var=1;
        }
        
        //parameterized constructor
        hmm(int varGiven) : var(varGiven)   {}//initializer lists for inplace assignments
        
        //Copy constructor
        hmm(hmm &hmmGiven) : var(hmmGiven.var)  {}

        //Destructor, better for closing files or releasing allocated memories
        ~hmm()
        {
            cout<<"destructor for hmm is called"<<endl;
        }
        void printVar();
};
class mmm
class hmmChild:hmm
{
    
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
    
    hmm obj1Copy=obj1;
    obj1Copy.printVar();

    hmmChild objChild1;
    obj1Copy.printVar();
    
    return 0;

}