#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define lineBreak "++++++++++++++++++++++++++++++"

template<class T>
class Calc
{
    private:
        T a,b;
    public:
        Calc(T a, T b): a(a),b(b){calcAll();}
        void calcAll()
        {
            cout<<"add gives: "<<add(a,b)<<endl;
            cout<<"subtract gives: "<<subtract(a,b)<<endl;
            cout<<"multiply gives: "<<multiply(a,b)<<endl;
            cout<<"divide gives: "<<divide(a,b)<<endl;
        }
        T add(T a, T b){return a+b;}
        T subtract(T a, T b){return a-b;}
        T multiply(T a, T b){return a*b;}
        T divide(T a, T b){return a/b;}
};


//?Add using template
template <class T>
T addIt (T a,T b)
{
    return a+b;
}


//?Swap using template
template <class T>
void swapIt(T& a,T& b)
{
    T temp=a;
    a=b;
    b=temp;
}

//?Template specializtion
template<>
void swapIt<char>(char& a, char& b)
{
    cout<<"!!!You just saw a template specialization demo!!!"<<endl;
    char temp=a;
    a=b;
    b=temp;
}


//?Exception Handl
void division(int a, int b)
{
    try
    {
        if(b!=0){throw ((double)a)/b;}
        else{throw runtime_error("Math Error: Divide by zero");}
    }

    catch(double& x)
    {   
        cout<<"caught it"<<endl;
        cout<<x<<endl;
    }

    catch(runtime_error x)
    {
        cout<<"caught it"<<endl;
        cout<<x.what()<<endl;
    }
    
}

int main()
{
    cout<<lineBreak<<endl;
    //! functional template
    int aInt=1,bInt=2;
    swapIt(aInt,bInt);
    cout<<"now a is "<<aInt<< ", b is "<<bInt<<" and their sum is "<<addIt<int>(aInt,bInt)<<endl;
    float aFloat=1.1,bFloat=2.0;
    swapIt(aFloat,bFloat);
    cout<<"now a is "<<aFloat<< ", b is "<<bFloat<<" and their sum is "<<addIt<float>(aFloat,bFloat)<<endl;
    char aChar='0',bChar='1';
    swapIt(aChar,bChar);
    cout<<"now a is "<<aChar<< ", b is "<<bChar<<" and their sum is "<<addIt<char>(aChar,bChar)<<endl;
    cout<<lineBreak<<endl;


    //! functional class
    cout<<"Calculations for 5.0 and 2.0"<<endl;
    Calc<float> CalcFloat(5.0,2.0);
    cout<<lineBreak<<endl;


    //! string macros
    #define intoString(a) #a
    #define tokenPasting(a,b) a##b

    cout<<intoString(12)<<endl;
    cout<<tokenPasting(34,56)<<endl;
    cout<<lineBreak<<endl;

    //! lamda functions
    auto square = [](const int& i){return i*i;};
    cout<<"The square of 5 is "<<square(5)<<endl;


    vector<int> vec={1,2,3,4,5};
    for_each(vec.begin(),vec.end(),[](int& i){return i+=5;});
    for(const auto& i:vec){cout<<i<<", "<<endl;}
    cout<<lineBreak<<endl;

    //! new()
    int* p= new int[3]{20,210,120};
    for(auto i :{1,2,3})
    {
        cout<<*p<<endl;
        p++;
    }
    cout<<lineBreak<<endl;

    //!Exception Handling
    division(1,1);
    division(1,0);
    cout<<lineBreak<<endl;

    return 0;
}