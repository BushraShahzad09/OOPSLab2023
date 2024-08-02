#include <iostream>
using namespace std;
// a constructor is that it is always executed whenever we create new objects of that class.
class Line
{
private:
    double length;

public:
    void setLength(double len);
    double getLength(void);
    Line();                // This is the constructor
    Line(double inLength); // This is parameterised constructor
    ~Line();               // This is the destructor: declaration
    Line(const Line &l1);        // This is a copy constructor for optional question
};
Line::Line()
{
    cout << "\nObject is being created" << endl;
    cout << "Default Constructor called!";
    length = 0.0;
}
Line::Line(double inLength)
{
    cout << "\nObject is being created" << endl;
    cout << "Parameterised Constructor called!\n";
    length = inLength;
}
Line::Line(const Line &l1)
{
    cout << "\nObject is being created" << endl;
    cout << "Copy Constructor called!\n";
}
Line::~Line(void)
{
    cout << "\nObject is being deleted" << endl;
    cout << "Default destructor called!\n";
}
void Line::setLength(double inLength)
{
    length = inLength;
}
double Line::getLength(void)
{
    return length;
}
int main()
{
    Line line;
    line.setLength(6.0);
    cout << "\nLength of line : " << line.getLength() << endl;

    Line obj1(20);    // obj1 is an lvalue
    Line obj2(obj1);  // Copy constructor is called with an lvalue


    Line someLine = Line(12.0); // no copy constructor called because object is rvalue


    
    return 0;
}