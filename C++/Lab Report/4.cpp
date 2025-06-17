/* Define a class Student with private members for name, roll number, and marks. 
Implement a copy constructor to copy the details of one student object to another. 
Write a destructor to display a message when the object is destroyed. Test this by 
creating a Student object and copying it to another. */

#include <iostream>
using namespace std;

class Student {
    string name;
    int roll;
    float marks;
public:
    