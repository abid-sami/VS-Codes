//Compare Circle and Rectangle
#include <iostream>
using namespace std;
class Rectangle;

class Circle{
float radius;
float area;

public:
    Circle(float r)
    {
        radius = r;
        area =3.1416*radius*radius;
    }
    void display_Circle()
    {
        cout<<"Area of Circle : " <<area<<endl;
    }
    friend void compare(Circle c, Rectangle r);

};
class Rectangle
{
   float length;
   float width;
   float area;

   public:
   Rectangle(float l, float w)
   {
       length = l;
       width = w;
       area = length * width;
   }
   void display_Rectangle()
    {
        cout<<"Area of Rectangle : " <<area<<endl;
    }
    friend void compare(Circle c, Rectangle r);

};
void compare(Circle c, Rectangle r)
{
    if (c.area == r.area)
    {
        cout<<"Area of Circle and Rectangle are Equal" <<endl;
    }
    else if(c.area>r.area)
    {
        cout<<"Area of Circle is Larger" <<endl;
    }
    else
    {
        cout<<"Area of Rectangle is Larger" <<endl;
    }

}


int main()
{
    Circle obj1(2.0);
    Rectangle obj2(2.0,2.6);
    obj1.display_Circle();
    obj2.display_Rectangle();
    compare(obj1, obj2);

return 0;
}
