#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Point
{ // by default private - data members (need getter setter to access them)
    double _x;
    double _y;
    static int count;
    // public:
    // given member functions are public
    // they can be accessed publicly by object (without getter setter)
public:
    Point();                   // This is the DEFAULT constructor
    Point(double x, double y); // This is the PARAMETERIZED constructor
    Point(Point &p);           // This is the COPY constructor
    void setCoords(double x, double y);
    void printCoords();
    double distFrom(Point &p);
    Point midPoint(Point &p);
    ~Point(); // This is the destructor
};
// Implement the class defining each of the functions, constructors and destructor
int Point::count = 0;
// constructors
Point::Point()
{
    cout << "\nDefault constructor is called!" << endl;
    this->_x = 0;
    this->_y = 0;
    count++;
    cout << "\nObj currently in use: " << count << endl;
}
Point::Point(double x, double y)
{
    cout << "\nParameterised constructor is called!" << endl;
    this->_x = x;
    this->_y = y;
    count++;
    cout << "\nObj currently in use: " << count << endl;
}
Point::Point(Point &p)
{
    cout << "\nCopy constructor is called!" << endl;
    count++;
    cout << "\nObj currently in use: " << count << endl;
    // this->_x=p._x;
    // this->_y=p._y;
}
void Point::setCoords(double x, double y)
{
    this->_x = x;
    this->_y = y;
}
void Point::printCoords()
{
    cout << "\nThe x coordinate is " << this->_x << endl;
    cout << "The y coordinate is " << this->_y;
}
double Point::distFrom(Point &p)
{
    return sqrt(pow(this->_x - p._x, 2) + pow(this->_y - p._y, 2));
}
Point Point::midPoint(Point &p)
{
    Point ansP;
    ansP._x = (this->_x + p._x) / 2.0;
    ansP._y = (this->_y + p._y) / 2.0;
    return ansP;
}

Point::~Point()
{
    cout << "\nDestructor is called!" << endl;
    count--;
}
int main()
{
    cout << "\nPoint 1:" << endl;
    Point p1;
    p1.printCoords();
    cout << "\nPoint 2:" << endl;
    Point p2(1, 1);
    p2.printCoords();
    cout << "\nPoint 3:" << endl;
    Point p3(2, 2);
    p3.printCoords();
    cout << "\nDistance between Point 1 and 2:" << endl;
    cout << p1.distFrom(p2);
    cout << "\nDistance between Point 1 and 3:" << endl;
    cout << p1.distFrom(p3);

    Point ans_mid;
    ans_mid = p2.midPoint(p3);
    cout << "\nMidPoint of Point 3 and 2:";
    ans_mid.printCoords();

    return 0;
}