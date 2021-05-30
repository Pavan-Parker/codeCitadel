#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
    protected:
        int age;
        string name;
    public:
        virtual void putdata(){}
        virtual void getdata(){}
};

class Professor : public Person
{
    private:
        int cur_id;
        int publications;
    public:
        static int idCount;
        Professor()
        {
            idCount+=1;
            cur_id=idCount;
        }
        void getdata()
        {
            cin>>this->name>>this->age>>this->publications;
        }
        void putdata()
        {
            cout<<this->name<<" ";
            cout<<this->age<<" ";
            cout<<this->publications<<" ";
            cout<<this->cur_id<<endl;
        }
        
};

class Student : public Person
{
    private:
        int cur_id;        
        vector<int> marks={0,0,0,0,0,0};
        
    public:
        static int idCount;
        Student()
        {
            idCount+=1;
            cur_id=idCount;

        }
        void getdata()
        {
            cin>>this->name>>this->age;
            for(auto& itr : marks){cin >> itr;}
        }
        void putdata()
        {
            cout<<this->name<<" ";
            cout<<this->age<<" ";
            int sum=0;
            for(const auto& itr:marks){sum+=itr;}
            cout<<sum<<" ";
            cout<<this->cur_id<<endl;
        }
        
};

int Professor::idCount=0;
int Student::idCount=0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
