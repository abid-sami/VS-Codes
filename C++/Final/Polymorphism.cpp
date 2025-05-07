#include<iostream>
using namespace std;

class Complex{
    int real, imag;
    public:
    Complex(int r=0, int i=0){
        real=r;
        imag=i;
    }

Complex addition(Complex const& obj){
    Complex result;
    result.real=real+obj.real;
    result.imag=imag+obj.imag;
    return result;
}
void print(){
    cout<<real<<"+"<<imag<<"i"<<endl;
}
};

int main(){
    Complex c1(10,5), c2(2,4), c3;
    c3=c1.addition(c2);
    c3.print();
}
