/**
 * * static data members of a class are static across all objects of that class.
 * * so that they can share the variable.   
*/
/** 
 * * Overloading vs Overriding
 * ! Overloading = behaviour depends on the type of args
 * ! Overriding = Overriding :)
 * ! derived class overrides the function only if base class's function is virtual.
*/

/**
 * * THIS
 * ! this is pointer to itself.
 * ! so to assign the variables with same name in class, use this.var=var; 
*/

/**
 * * constant reference significance
 * ? void print(const Student &s)
 * ! If we remove & in below function, a new
 * ! copy of the student object is created.
 * ! We use const to avoid accidental updates
 * ! in the function as the purpose of the function
 * ! is to print s only.
*/

/**
 * * Inline
 * ! replaces the functional call with body of the code
 * ! it saves functional call overhead for small function which are frequently used.
*/


#include <bits/stdc++.h>
using namespace std;

#define lineBreak "================================================="

class hmm
{
    protected:
        int var;
    private:
        int privateVar=1;
    public: // ? Access modifier
        
        //?default constructor
        hmm(){
            cout << "default constructor"<< endl;
            this->var=1;
        }
        
        //?parameterized constructor
        hmm(int varGiven) : var(varGiven)   {}//?initializer lists for inplace assignments
        
        //?Copy constructor
        hmm(hmm& hmmGiven) : var(hmmGiven.var)  {}

        //?Destructor, better for closing files or releasing allocated memories
        ~hmm()
        {
            cout<<"destructor for hmm is called"<<endl;
        }
        
        void whoIsThis() // ! to check the overriding
        {
            cout<<"this is class hmm Base speaking"<<endl;
        }

        void printVar(); // ! to demo the encapsulation and data hiding

        //?friend Class
        friend class friendHmm;

        //?friend function
        friend void friendHmmFunction(hmm&);
        
        //! add operator overloading
        hmm operator + (hmm& another)
        {
            return (hmm)(var+another.var);
        }

        //! cout operator overloading
        friend ostream &operator<<(ostream &output, hmm& x)
        {
            output<<x.var;
            return output;
        }

        //! cin operator overloading
        friend istream &operator>>(istream &input,hmm& x)
        {
            input>>x.var;
            return input;
        }

};

void hmm::printVar()    //! out of class defination
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
    cout<<obj1<<endl;

    hmm obj2(2);
    cout<<obj2<<endl;
    
    hmm obj1Copy=obj1;
    cout<<obj1Copy<<endl;
    
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
    cout<<":Operator Overloading:"<<endl;
    hmm objAdd=(obj1+obj2);
    cout<<objAdd<<endl;

    cout<<lineBreak<<endl;
    cout<<":Destructors:"<<endl;
    

    
    return 0;

}