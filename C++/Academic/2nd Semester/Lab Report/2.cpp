/* Create a class Circle with a private data member radius. Implement a parameterized 
constructor that initializes the radius with the given value. Write a program that 
calculates and displays the area of the circle.*/

#include <iostream>
#define PI 3.1416
using namespace std;

class Circle {
    double radius;
public:
    Circle(double r=0){
        radius = r;
    }
    void set_value(double r) {
        radius = r;
    }
    void input() {
        cout << "Enter radius: ";
        cin >> radius;
    }
    void display() {
        double area= PI * radius * radius;
        cout << "Area: " << area << endl;
        
    }
};

int main() {
    Circle c;
    c.input();
    c.display();
}