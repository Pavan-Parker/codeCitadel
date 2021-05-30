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
        virtual void putdata();
        virtual void getdata();
};

class Professor : public Person
{
    private:
        int publications;
    public:
        static int cur_id;
        Professor()
        {
            cur_id+=1;
        }
        void putdata()
        {
            cin>>this->name>>this->age>>this->publications;
        }
        void getdata()
        {
            cout<<this->name<<this->age<<this->publications<<this->cur_id;
        }
        
};

class Student : public Person
{
    private:
        vector<int> marks[6];
    public:
        static int cur_id;
        Student()
        {
            cur_id+=1;
        }
        void putdata()
        {
            cin>>this->name>>this->age;
            for(auto itr:marks){cin>>itr;}
        }
        void getdata()
        {
            cout<<this->name<<this->age<<this->publications<<this->cur_id;
        }
        
};

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
