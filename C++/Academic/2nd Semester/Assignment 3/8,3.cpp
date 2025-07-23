#include <iostream>
using namespace std;

class Staff
{
protected:
    int code;
    string name;

public:
    void sstaff(int c, string n)
    {
        code = c;
        name = n;
    }
    void display()
    {
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
    }
};

class Teacher : public Staff
{
    string subject;
    string publication;

public:
    void inputT(int c, string n, string sub, string pub)
    {
        sstaff(c, n);
        subject = sub;
        publication = pub;
    }

    void displayT()
    {
        display();
        cout << "Subject: " << subject << endl;
        cout << "Publication: " << publication << endl;
    }
};

class Typist : public Staff
{
protected:
    float speed;

public:
    void inputT(int c, string n, float s)
    {
        sstaff(c, n);
        speed = s;
    }

    void displayT()
    {
        display();
        cout << "Typing Speed: " << speed << endl;
    }
};

class Regular : public Typist
{
public:
    void inputR(int c, string n, float s)
    {
        inputT(c, n, s);
    }

    void displayR()
    {
        cout << "Regular...." << endl;
        displayT();
    }
};

class Casual : public Typist
{
    float dailyw;

public:
    void inputC(int c, string n, float s, float wage)
    {
        inputT(c, n, s);
        dailyw = wage;
    }

    void displayC()
    {
        cout << "Casual...." << endl;
        displayT();
        cout << "Daily Wages: " << dailyw << endl;
    }
};

class Officer : public Staff
{
    char grade;

public:
    void inputO(int c, string n, char g)
    {
        sstaff(c, n);
        grade = g;
    }

    void displayO()
    {
        display();
        cout << "Grade: " << grade << endl;
    }
};

int main()
{
    Teacher t;
    t.inputT(1001, "Sami", "CPP", "Book");
    cout << "Teacheer....." << endl;
    t.displayT();
    Officer o;
    o.inputO(1002, "Ragib", 'A');
    cout << "Officer...." << endl;
    o.displayO();
    Regular r;
    r.inputR(1003, "Abid", 50);
    r.displayR();
    Casual c;
    c.inputC(1004, "Hasan", 45, 600);
    c.displayC();
}
