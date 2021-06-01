Test 1 (1 point) : Testing heritance

#include <iostream>
using namespace std;

class Parent {
  public:
    void doA() { cout << "doA in Parent" << endl; }
    virtual void doB() { cout << "doB in Parent" << endl; }
    virtual void doC() { cout << "doC in Parent" << endl; }
};

class Child : public Parent {
  public:
    void doA() { cout << "doA in Child" << endl; }
    virtual void doB() { cout << "doB in Child" << endl; }
    virtual void doC() override { cout << "doC in Child" << endl; }
};

Parent* p1 = new Parent();
Parent* p2 = new Child();
Child* cp = new Child();

int main() {
  p1->doA();
  p2->doA();
  cp->doA();

  p1->doB();
  p2->doB();
  cp->doB();
  
  p1->doC();
  p2->doC();
  cp->doC();
  
  return 0;
}

Answer : 
doA in Parent
doA in Parent
doA in Parent

doB in Parent
doB in Parent
doB in Child

doC in Parent
doC in Child
doC in Child
------------------------------------------------------------------------
------------------------------------------------------------------------
------------------------------------------------------------------------
------------------------------------------------------------------------

Test 2 (3 point) : Pass by value and reference 

#include <iostream>
using namespace std;
void Decrement1( int*& d ) {
   --d;
}
void Decrement2( int* d ) {
   --*d;
}
int main( void )
{
   int a[4] = {10,20,30,40};
   
   int* ptr = &a[2];
   cout<<"Before: "<< *ptr << endl;
   
   Decrement1(ptr);
   cout<<"After1: " << *ptr << endl;
   
   Decrement2(ptr);
   cout<<"After2: " << *ptr << endl;
   return 0;
}
Answer : 
30
20
19
------------------------------------------------------------------------
------------------------------------------------------------------------
------------------------------------------------------------------------
------------------------------------------------------------------------

3. (3 point) : Function pointer and Functors
#include <iostream>
#include <list>
#include <tuple>
#include <memory>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <functional>
#include <unordered_map>

using namespace std;

class Base
{
	private:
	std::function<int(int x, int y)> myFunction = 0;
	
	public:
	void SetFunction(std::function<int(int x, int y)> functionPointer)
	{
		if (functionPointer)
			myFunction = functionPointer;
	}
	
	int operator ()(int x, int y)
	{
		if(myFunction)
			return myFunction(x, y);
	}
};

class Testing
{
	int GetResult(int a, int b)
	{
		return ++a;
	}	
	
	public:
	void SetFunction(Base* base)
	{
		base->SetFunction(std::bind(&Testing::GetResult, this, std::placeholders::_2, std::placeholders::_1));
	}
};

int main( void )
{
	Base base = Base();
	Testing test = Testing();
	test.SetFunction(&base);
	cout << base(1,2) << endl;
   	return 0;
}
Answer :

------------------------------------------------------------------------
------------------------------------------------------------------------
------------------------------------------------------------------------
------------------------------------------------------------------------

4. (2 point) : Threading and Mutex
Explain the concept of threads and mutex
What/ explain different types of mutex.
Find the issue with the following program.

#include <iostream>
#include <list>
#include <tuple>
#include <memory>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <functional>
#include <unordered_map>

using namespace std;

std::mutex myMutex;
int buffer = 0;

void recursion(char threadName, int loopFor)
{
	if (loopFor < 0)
		return;

	myMutex.lock();
	cout << threadName << " " << ++buffer << endl;
	recursion(threadName, --loopFor);
	myMutex.unlock();
}

int main(void)
{
	thread t0(recursion, '0', 10);
	thread t1(recursion, '1', 5);
	t0.join();
	t1.join();
	return 0;
}
Answer :

------------------------------------------------------------------------
------------------------------------------------------------------------
------------------------------------------------------------------------
------------------------------------------------------------------------

5. (1 point) Testing pointer part 2
Fix/ What is the issue with the following code

#include <iostream>
#include <list>
#include <tuple>
#include <memory>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <functional>
#include <unordered_map>

using namespace std;

class Testing
{
public:
	char* name = nullptr;
	void PrintName()
	{
		cout << name << endl;
	}
};

int main(void)
{
	Testing test;
	{
		string myName = "Hello";
		test.name = myName.c_str();
	}
	test.PrintName();
	return 0;
}
Answer : 

6. (3 point) Testing memory allocation concept
#include <iostream>
#include <list>
#include <tuple>
#include <memory>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <functional>
#include <unordered_map>

using namespace std;

struct myStruct
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
};

int main(void)
{
	myStruct *testing = new myStruct;
	memset(testing, 0, sizeof(testing));

	auto print = [&]()
	{
		cout << testing->a << endl;
		cout << testing->b << endl;
		cout << testing->c << endl;
		cout << testing->d << endl;
		cout << testing->e << endl;
	};

	print();
	testing = nullptr;
	cout << sizeof(testing) << endl;
	cout << sizeof(*testing) << endl;
	cout << sizeof(myStruct) << endl;

	return 0;
}
Answer :
4
20
20
------------------------------------------------------------------------
------------------------------------------------------------------------
------------------------------------------------------------------------
------------------------------------------------------------------------

7. (3 point) STL
Implement a template function IsDerivedFrom() that takes class C and class P as template parameters.
It should return true when class C is derived from class P and false otherwise.

#include <iostream>
#include <list>
#include <tuple>
#include <memory>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <functional>
#include <unordered_map>

using namespace std;
template <class C, class P>
bool IsDerivedFromType1()
{
	return std::is_base_of(C,P);
}

template <class C, class P>
bool IsDerivedFromType2()
{
}

template <class C, class P>
bool IsDerivedFromType3()
{
}

class Base
{};
class Derived : public Base
{};

int main(void)
{
	cout << IsDerivedFromType1<Derived, Base>() << endl;
	cout << IsDerivedFromType2<Derived, Base>() << endl;
	cout << IsDerivedFromType3<Derived, Base>() << endl;
	return 0;
}
Answer :

8. (2 point) Testing exceptions
What is the output of the following code.

#include <iostream>

class A {
public:
    A() {}
    ~A() {
        throw 42;
    }
};

int main(int argc, const char * argv[]) {
    try {
        A a;
        throw 32;
    } catch(int a) {
        std::cout << a;
    }
}
Answer :
42

9.
(1 point)
Difference between class and structure in C++
Answer : 

10.
(1 point)
Explain difference between static_cast, dynamic_cast, reinterpret_cast
And when to use them.

Answer :


