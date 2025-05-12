#include<iostream>
using namespace std;

class four_seater{
    public:
    void sProperty(){
        cout<<"It has space for four persons"<<endl;
    }
};

class four_wheels{
    public:
    void wProperty(){
        cout<<"It runs on four tyres"<<endl;
    }
};

class Car:public four_seater, public four_wheels{
    public:
    void display(){
        sProperty();
        wProperty();
    }
};

int main(){
    Car c1;
    c1.display();
    
}