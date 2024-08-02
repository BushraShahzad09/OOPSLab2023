#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Point
{
    static int count;
    double _x;
    double _y;

public:
    void setCoords(double x, double y);
    void printCoords() const;
    double distFrom(Point &p) const;
    Point midPoint(Point &p) const;
    Point linear_combine(Point &p, double s) const;
    Point();                   // This is the DEFAULT constructor
    Point(double x, double y); // This is the PARAMETERIZED constructor
    Point(Point &p);           // This is the COPY constructor
                               // ~Point();                  // This is the destructor
    Point operator+(const Point &p) const;
    bool operator<(const Point &p) const;
    bool operator>(const Point &p) const;
    bool operator==(const Point &p) const;
    Point operator*(double scale) const;
    static int getCount();
};
Point::Point()
{
    count++;
    cout << "\nConstructor is called.";
    this->_x = 0;
    this->_y = 0;
}
Point::Point(double x, double y)
{
    count++;
    cout << "\nParameterised constructor is called.";
    this->_x = x;
    this->_y = y;
}
Point::Point(Point &p)
{
    count++;
    cout << "\nCopy constructor is called.";
    this->_x = p._x;
    this->_y = p._y;
}
void Point::setCoords(double x, double y)
{
    this->_x = x;
    this->_y = y;
}
void Point::printCoords() const
{
    cout << "\n( " << this->_x << " , " << this->_y << " )";
}
double Point::distFrom(Point &p) const
{
    return sqrt(pow(this->_x - p._x, 2) + pow(this->_y - p._y, 2));
}
Point Point::midPoint(Point &p) const
{
    Point ansP;
    ansP._x = (this->_x + p._x) / 2.0;
    ansP._y = (this->_y + p._y) / 2.0;
    return ansP;
}

int Point::getCount()
{
    return count;
}
Point Point::operator+(const Point &p) const
{
    Point ans;
    ans._x = this->_x + p._x;
    ans._y = this->_x + p._y;
    return ans;
}
bool Point::operator<(const Point &p) const
{

    double this_distance = pow(this->_x, 2) + pow(this->_y, 2);
    double p_distance = pow(p._x, 2) + pow(p._y, 2);
    return (p_distance < this_distance);
}
bool Point::operator>(const Point &p) const
{

    double this_distance = pow(this->_x, 2) + pow(this->_y, 2);
    double p_distance = pow(p._x, 2) + pow(p._y, 2);
    return (p_distance > this_distance);
}
bool Point::operator==(const Point &p) const
{
    double epsilon = -100.000;
    // cout << "Enter the value of epsilon :";
    double this_distance = pow(this->_x, 2) + pow(this->_y, 2);
    double p_distance = pow(p._x, 2) + pow(p._y, 2);
    if (abs(this_distance - p_distance) < epsilon)
        return true;
    else
        return false;
}
Point Point::operator*(double scale) const
{
    Point ans;
    ans._x = this->_x * scale;
    ans._y = this->_y * scale;
    return ans;
}
Point Point::linear_combine(Point &p, double s) const
{
    Point q;
    q = ((*this) * s) + p * (1 - s);
    return q;
}
int Point::count = 0;
int main()
{
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3;
    // checking mulitplicrtion
     p3= p2*1.5;
  //  p3 = p2 + p1;
    p3.printCoords();

    // chaining
    Point p4;
    p4 = p3 + p2 + p1;
    cout << "\np4 -";
    p4.printCoords();

    // chaining manually as much possible

    Point p5(10, 10);
    Point p6(20, 20);
    Point p7(-20, -20);
    Point p8(-10, -10);
    Point p9(-6, -6);
    Point p10;
    p10 = p4 + p5 + p6 + p7 + p8 + p9;
    cout << "\np10 - ";
    p10.printCoords();
    // compare operator overload
    Point p11(23, 23);
    Point p12(21, 21);
    bool compare = p11 < p12;
    if (compare)
    {
        p12.printCoords();
        cout << " is less than ";
        p11.printCoords();
    }
    else
    {
        p11.printCoords();
        cout << " is less than ";
        p12.printCoords();
    }
    // checking greater than function
    bool compare2 = p11 > p12;
    if (compare2)
    {
        p12.printCoords();
        cout << " is greater than ";
        p11.printCoords();
    }
    else
    {
        p11.printCoords();
        cout << " is greater than ";
        p12.printCoords();
    }
    // equality defineee
    Point a(12, 12);
    Point b(13, 13);
    bool ans_equality;
    ans_equality = (a == b);
    cout <<"\n"<< ans_equality<<"\n";

    // linear combine

    Point p13(3,6);
    Point p14(2,3);
    Point p15;
    p15=p13.linear_combine(p14,0.5);

    p15.printCoords();

    
}