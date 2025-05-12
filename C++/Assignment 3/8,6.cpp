#include <iostream>
using namespace std;

class Staff
{
    int code;
    string name;

public:
    void inputs(int c, string n)
    {
        code = c;
        name = n;
    }
    void displays()
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
        inputs(c, n);
        subject = sub;
        publication = pub;
    }
    void displayT()
    {
        cout << "Teacher..." << endl;
        displays();
        cout << "Subject: " << subject << endl;
        cout << "Publication: " << publication << endl;
    }
};

class Officer : public Staff
{
    string grade;

public:
    void inputO(int c, string n, char g)
    {
        inputs(c, n);
        grade = g;
    }
    void displayO()
    {
        cout << "Officer..." << endl;
        displays();
        cout << "Grade: " << grade << endl;
    }
};

class Typist : public Staff
{
    float speed;

public:
    void inputT(int c, string n, float s1)
    {
        inputs(c, n);
        speed = s1;
    }
    void displayT()
    {
        displays();
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
        cout << "Regular Typist..." << endl;
        displayT();
    }
};

class Casual : public Typist
{
    float dailyw;

public:
    void inputC(int c, string n, float s, float w)
    {
        inputT(c, n, s);
        dailyw = w;
    }
    void displayC()
    {
        cout << "Casual Typist..." << endl;
        displayT();
        cout << "Daily Wages: " << dailyw << endl;
    }
};

int main()
{
    Teacher t;
    t.inputT(1001, "Sami", "Cpp", "Book");
    t.displayT();
    Officer o;
    o.inputO(1002, "Ragib", 'A');
    o.displayO();
    Regular r;
    r.inputR(1003, "Abid", 60);
    r.displayR();
    Casual c;
    c.inputC(1004, "Hasan", 45, 500);
    c.displayC();
}
