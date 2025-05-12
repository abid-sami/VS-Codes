#include <iostream>
using namespace std;

class Staff
{
protected:
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

class Education
{
protected:
    string gedu;
    string pedu;

public:
    void inpute(string g, string p)
    {
        gedu = g;
        pedu = p;
    }
    void displaye()
    {
        cout << "General Education: " << gedu << endl;
        cout << "Professional Education: " << pedu << endl;
    }
};

class Teacher : public Staff, public Education
{
    string subject;
    string publication;

public:
    void input(int c, string n, string sub, string pub, string g, string p)
    {
        inputs(c, n);
        subject = sub;
        publication = pub;
        inpute(g, p);
    }
    void display()
    {
        cout << "Teacher..." << endl;
        displays();
        cout << "Subject: " << subject << endl;
        cout << "Publication: " << publication << endl;
        displaye();
    }
};

class Officer : public Staff, public Education
{
    string grade;

public:
    void input(int c, string n, string g, string p, string gr)
    {
        inputs(c, n);
        inpute(g, p);
        grade = gr;
    }
    void display()
    {
        cout << "Officer..." << endl;
        displays();
        cout << "Grade: " << grade << endl;
        displaye();
    }
};

class Typist : public Staff
{
protected:
    float speed;

public:
    void inputt(int c, string n, float s)
    {
        inputs(c, n);
        speed = s;
    }
    void displayt()
    {
        displays();
        cout << "Typing Speed: " << speed << endl;
    }
};

class Regular : public Typist
{
public:
    void input(int c, string n, float s)
    {
        inputt(c, n, s);
    }
    void displayr()
    {
        cout << "Regular Typist..." << endl;
        displayt();
    }
};

class Casual : public Typist
{
    float dailyw;

public:
    void input(int c, string n, float s, float w)
    {
        inputt(c, n, s);
        dailyw = w;
    }
    void displayc()
    {
        cout << "Casual Typist..." << endl;
        displayt();
        cout << "Daily Wages: " << dailyw << endl;
    }
};

int main()
{
    Teacher t;
    t.input(1001, "Sami", "Cpp", "Book", "HSC", "CSE");
    t.display();
    Officer o;
    o.input(1002, "Ragib", "HSC", "MBA", "A");
    o.display();
    Regular r;
    r.input(1003, "Abid", 60);
    r.displayr();
    Casual c;
    c.input(1004, "Hasan", 45, 500);
    c.displayc();
}
