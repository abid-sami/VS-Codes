#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    void inputp(string n, int a)
    {
        name = n;
        age = a;
    }
    void displayp()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person
{
protected:
    int id;
    string dept;

public:
    void inpute(int id, string d)
    {
        id = id;
        dept = d;
    }
    void displaye()
    {
        cout << "Employee ID: " << id << endl;
        cout << "Department: " << dept << endl;
    }
};

class Salary : public Employee
{
    float basic;
    float gross;

public:
    void inputs(float b, float g)
    {
        basic = b;
        gross = g;
    }
    void displays()
    {
        cout << "Basic Salary: " << basic << endl;
        cout << "Gross Salary: " << gross << endl;
    }
};

int main()
{
    Salary s;
    s.inputp("Sami", 22);
    s.inpute(1001, "IT");
    s.inputs(20000, 30000);
    s.displayp();
    s.displaye();
    s.displays();
}
