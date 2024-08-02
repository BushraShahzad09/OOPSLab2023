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

    Line obj1(20); 
    cout << "\nLength of Obj1 : " << obj1.getLength() << endl; 
    
    Line obj2(obj1); // deafult copy constructor will be called -no compilation error 
    cout << "\nLength of Obj2 : " << obj2.getLength() << endl; 
    Line someLine = Line(12.0);
    cout << "\nLength of someLine: " << someLine.getLength() << endl; 


    
    return 0;
}