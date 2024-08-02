#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Point
{ // by default private - data members (need getter setter to access them)
    double _x;
    double _y;
    static int count;
    static int countTL;
    static int countTR;
    static int countBR;
    static int countBL;
    // public:
    // given member functions are public
    // they can be accessed publicly by object (without getter setter)
public:
    // static int count=0; error
    Point();                   // This is the DEFAULT constructor
    Point(double x, double y); // This is the PARAMETERIZED constructor
    Point(Point &p);           // This is the COPY constructor
    void setCoords(double x, double y);
    void printCoords() const;
    double distFrom(Point &p) const;
    Point midPoint(Point &p) const;
    void countAll() const;
    ~Point(); // This is the destructor
};
// Initalising count =0
int Point::count = 0;
int Point::countTL = 0;
int Point::countTR = 0;
int Point::countBL = 0;
int Point::countBR = 0;
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
    this->_x = p._x;
    this->_y = p._y;
}
// functions
void Point::setCoords(double x, double y)
{
    this->_x = x;
    this->_y = y;
}
void Point::printCoords() const
{
    cout << "( " << this->_x << " , " << this->_y << " )";
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
void Point::countAll() const
{
    if (this->_x > 0 && this->_y > 0)
        countTR++;
    else if (this->_x < 0 && this->_y > 0)
        countTL++;
    else if (this->_x < 0 && this->_y < 0)
        countBL++;
    else if (this->_x > 0 && this->_y < 0)
        countBR++;
    // Displaying Count
    cout << "\nPoints in -\n";
    cout << "First Quadrant - " << countTR << endl;
    cout << "Second Quadrant - " << countTL << endl;
    cout << "Third Quadrant - " << countBL << endl;
    cout << "fourth Quadrant - " << countBR << endl;
}
// destructor
Point::~Point()
{
    cout << "\nDestructor is called!" << endl;
    count--;
}

int main()
{
    // Point::count=0; error
    Point p1;
    cout << "\nPoint 1:" << endl;
    p1.printCoords();

    Point p2(1, 1);
    cout << "\nPoint 2:" << endl;
    p2.printCoords();

    Point p3(2, 2);
    cout << "\nPoint 3:" << endl;
    p3.printCoords();

    cout << "\nDistance between Point 1 and 2:" << endl;
    cout << p1.distFrom(p2);
    cout << "\nDistance between Point 1 and 3:" << endl;
    cout << p1.distFrom(p3);

    Point ans_mid;
    ans_mid = p2.midPoint(p3);
    cout << "\nMidPoint of Point 3 and 2:";
    ans_mid.printCoords();
    p1.countAll();
    p2.countAll();
    p3.countAll();
    ans_mid.countAll();
    // les create negative corrdinate object
    Point p4(-3, -4);
    cout << "\nPoint 4:" << endl;
    p4.printCoords();
    p4.countAll();
    Point p5(-3, 7);
    p5.printCoords();
    p5.countAll();
    Point p6(3, -7);
    p6.printCoords();
    p6.countAll();

    // aaray of points object
   // Point arr[100][100];

    // intialisation
    // for (int i = 0; i < 100; i++)
    // {
    //     for (int j = 0; j < 100; j++)
    //     {
    //         arr[i][j]=Point(i,j);
    //     }

    // }
    // cout<<"\nPrinting array\n";
    // for (int i = 0; i < 100; i++)
    // {
    //     arr[i]->printCoords();
    //     cout<<" ";
    // }

    return 0;
}