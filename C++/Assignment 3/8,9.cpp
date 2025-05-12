#include <iostream>
using namespace std;

class vehicle
{
    string type;

public:
    void inputv(string t)
    {
        type = t;
    }

    void displayf()
    {
        cout << "Vehicle Type: " << type << endl;
    }
};

class twoWheeler : public vehicle
{
    string mode;

public:
    void inputtwo(string t, string m)
    {
        inputv(t);
        mode = m;
    }

    void displaytwo()
    {
        displayf();
        cout << "Mode: " << mode << endl;
    }
};

class threeWheeler : public vehicle
{
    string mode;

public:
    void inputthree(string t, string m)
    {
        inputv(t);
        mode = m;
    }

    void displaythree()
    {
        displayf();
        cout << "Mode: " << mode << endl;
    }
};

class fourWheeler : public vehicle
{
    string mode;

public:
    void inputfour(string t, string m)
    {
        inputv(t);
        mode = m;
    }

    void displayfour()
    {
        displayf();
        cout << "Mode: " << mode << endl;
    }
};

int main()
{
    twoWheeler tw1, tw2, tw3;
    tw1.inputtwo("Two Wheeler", "Manual");
    tw2.inputtwo("Two Wheeler", "Electric");
    tw3.inputtwo("Two Wheeler", "Automatic");

    threeWheeler th1, th2, th3;
    th1.inputthree("Three Wheeler", "Manual");
    th2.inputthree("Three Wheeler", "Electric");
    th3.inputthree("Three Wheeler", "Automatic");

    fourWheeler fw1;
    fw1.inputfour("Four Wheeler", "Automatic");

    cout << "Two Wheeler Types..." << endl;
    tw1.displaytwo();
    cout << endl;
    tw2.displaytwo();
    cout << endl;
    tw3.displaytwo();
    cout << endl;

    cout << "Three Wheeler Types..." << endl;
    th1.displaythree();
    cout << endl;
    th2.displaythree();
    cout << endl;
    th3.displaythree();
    cout << endl;

    cout << "Four Wheeler Type..." << endl;
    fw1.displayfour();
}
