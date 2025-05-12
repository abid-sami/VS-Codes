#include <iostream>
using namespace std;

class Product
{
    string pname;
    int pcode;

public:
    void inputp(string n, int c)
    {
        pname = n;
        pcode = c;
    }

    void displayp()
    {
        cout << "Product Name: " << pname << endl;
        cout << "Product Code: " << pcode << endl;
    }
};

class Electronics : public Product
{
    string brand;

public:
    void inpute(string n, int c, string b)
    {
        inputp(n, c);
        brand = b;
    }

    void displaye()
    {
        cout << "Electronics...." << endl;
        displayp();
        cout << "Brand: " << brand << endl;
    }
};

class Food : public Product
{
    string expiry;

public:
    void inputf(string n, int c, string e)
    {
        inputp(n, c);
        expiry = e;
    }

    void displayf()
    {
        cout << "Food Item..." << endl;
        displayp();
        cout << "Expiry Date: " << expiry << endl;
    }
};

class Clothing : public Product
{
    string size;

public:
    void inputc(string n, int c, string s)
    {
        inputp(n, c);
        size = s;
    }

    void displayc()
    {
        cout << "Clothing..." << endl;
        displayp();
        cout << "Size: " << size << endl;
    }
};

class Kitchen : public Product
{
    string material;

public:
    void inputk(string n, int c, string m)
    {
        inputp(n, c);
        material = m;
    }

    void displayk()
    {
        cout << "Kitchen Product..." << endl;
        displayp();
        cout << "Material: " << material << endl;
    }
};

int main()
{
    Electronics e;
    e.inpute("Mobile", 1, "Samsung");
    e.displaye();
    Food f;
    f.inputf("IceCream", 2, "2026");
    f.displayf();
    Clothing c;
    c.inputc("Shirt", 3, "M");
    c.displayc();
    Kitchen k;
    k.inputk("Cooker", 4, "Steel");
    k.displayk();
}
