/* Create a class Box with private data members' length, width, and height. Implement 
a default constructor to initialize these members to 0. Write a program to create an 
object of the Box class and display the values of its members. */

#include <iostream>
using namespace std;

class Box {
    double length;
    double width;
    double height;
public:
    Box() {
        length = 0;
        width = 0;
        height = 0;
    }

    void display() {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
    }
};

int main() {
    Box b1; 
    b1.display();
}