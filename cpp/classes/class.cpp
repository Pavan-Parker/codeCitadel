#include <bits/stdc++.h>
using namespace std;

#define lineBreak "================================================="

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
        
        void whoIsThis()
        {
            cout<<"this is class hmm Base speaking"<<endl;
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

class hmmChildA: virtual public hmm{
    // public:
    //     void whoIsThis()
    //     {
    //         cout<<"this is class hmmChildA speaking"<<endl;
    //     }

};

class hmmChildB: virtual public hmm{
    // public:
    //     void whoIsThis()
    //     {
    //         cout<<"this is class hmmChildB speaking"<<endl;
    //     }
};

class hmmChildAB: virtual public hmmChildA, virtual public hmmChildB{
    // public:
    //     void whoIsThis()
    //     {
    //         cout<<"this is class hmmChildAB speaking"<<endl;
    //     }
};



void friendHmmFunction(hmm& x)
{
        cout<<"Now friendHmmFunction have friend class to privateVar in hmm which is "<< x.privateVar<<endl;
}



int main()
{
    cout<<lineBreak<<endl;
    cout<<":Constructors:"<<endl;
    hmm obj1;
    obj1.printVar();

    hmm obj2(2);
    obj2.printVar();
    
    hmm obj1Copy=obj1;
    obj1Copy.printVar();
    
    cout<<lineBreak<<endl;
    cout<<":Diamond problem without ambiguity:"<<endl;
    
    hmmChildA obj1ChildA;
    obj1ChildA.whoIsThis();
    

    hmmChildB obj1ChildB;
    obj1ChildB.whoIsThis();
    

    hmmChildAB obj1ChildAB;
    obj1ChildAB.whoIsThis();

    cout<<lineBreak<<endl;
    cout<<":Friend Function:"<<endl;
        
    friendHmm objFriend(obj1);
    friendHmmFunction(obj1);
        
    cout<<lineBreak<<endl;
    cout<<":Destructors:"<<endl;
    

    
    return 0;

}