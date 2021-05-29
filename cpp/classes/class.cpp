#include <bits/stdc++.h>
using namespace std;

class hmm
{
    protected:
        int var;
    private:
        int privateVar=1;
    public: //Access modifier
        
        //default constructor
        hmm(){
            cout << "default constructor"<< endl;
            hmm::var=1;
        }
        
        //parameterized constructor
        hmm(int varGiven) : var(varGiven)   {}//initializer lists for inplace assignments
        
        //Copy constructor
        hmm(hmm& hmmGiven) : var(hmmGiven.var)  {}

        //Destructor, better for closing files or releasing allocated memories
        ~hmm()
        {
            cout<<"destructor for hmm is called"<<endl;
        }
        void printVar();

        //friend Class
        friend class friendHmm;

        //friend function
        friend void friendHmmFunction(hmm&);
};

void hmm::printVar()    // out of class defination
{
    cout<<hmm::var<<endl;
}

class friendHmm
{
    public:
        friendHmm(hmm& x)
        {
            cout<<"Now friendClass have access to privateVar in hmm which is "<< x.privateVar<<endl;
        }
};

class hmmChild:hmm{
};

void friendHmmFunction(hmm& x)
{
        cout<<"Now friendHmmFunction have friend class to privateVar in hmm which is "<< x.privateVar<<endl;
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
    
    friendHmm objFriend(obj1);
    friendHmmFunction(obj1);
    
    
    return 0;

}