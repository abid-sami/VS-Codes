/*Write a C++ program to add two complex numbers using operator overloading. Implement a Complex class with private members
for real and imaginary parts, and overload the + operator to return the sum of two complex numbers.
Also include a function to display the result in standard form.
*/

#include <iostream>
using namespace std;
class Complex
{
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0){
        real = r;
        imag = i;
    }
    Complex operator+(Complex const& obj){
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print(){
        cout << real << " + i" << imag << endl;
    }
};
int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();
}
