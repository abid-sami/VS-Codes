//*** Always try to do it in Private & it can be questioned as "Just use Constructor, No Function"

#include <iostream>
#define PI 3.1416
using namespace std;

class Shape
{
    float area, volume;
    public:
    void set_value(float a, float v)
    {
        area=a, volume=v;
    }
    void display(){
        cout << "Area: " << area << endl;
        cout << "Volume: " << volume << endl;
    }
};

class Rectangle : public Shape
{
    float height, width, length;

public:
    Rectangle(float h, float w, float l)
    {
        length = l, width = w, height = h;
    }
    void calculate()
    {
        float area = height * width;
        float volume = height * width * length;
        set_value(area, volume); //IMPORTANT
        display(); //IMPORTANT
    }
};

class Circle : public Shape
{
    float radius, height;

public:
    Circle(float r, float h)
    {
        radius = r;
        height=h;
    }
    void calculate()
    {
        float area = PI * radius * radius;
        float volume = PI * radius * height;
        set_value(area, volume);
        display();
    }
};

class Square : public Shape
{
    float length;

public:
    Square(float l)
    {
        length = l;
    }
    void calculate()
    {
        float area = length * length;
        float volume = length * length* length;
        set_value(area, volume);
        display();
    }
};

class Triangle : public Shape
{
    float base, height, length;

public:
    Triangle(float b, float h, float l)
    {
        base = b, height = h, length = l;
    }
    void calculate()
    {
        float area = 0.5 * base * height;
        float volume = 0.5 * base * height * length;
        set_value(area, volume);
        display();
    }
};

int main()
{
    Rectangle r(4, 5, 6);
    cout<<"...Rectangle..."<<endl;
    r.calculate();

    Circle c(4, 5);
    cout<<"...Circle..."<<endl;
    c.calculate();

    Square s(5);
    cout<<"...Squre..."<<endl;
    s.calculate();

    Triangle t(4, 5, 6);
    cout<<"...Triangle..."<<endl;
    t.calculate();
}