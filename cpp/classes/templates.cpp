#include <iostream>
using namespace std;

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
int main()
{
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

    //! functional class
    cout<<"Cal"
    Calc<float> CalcFloat(5.0,2.0);

    return 0;
}