#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const double EARTH_RADIUS = 6371.0;
const double PI=3.14;
class Element{
    public:
    virtual void print()
    {
        cout<<"Abstract class virtual print function."<<endl;
    }
    virtual double norm()
    {
        
    }
};
class Point:public Element
{
public:
    double _x;
    double _y;

public:
    void print() override
    {
        cout<<"\nVirtual function.\n";
    }
    void setCoords(double x, double y);
    void printCoords() const;
    double distFrom(Point &p) const;
    Point();                   // This is the DEFAULT constructor
    Point(double x, double y); // This is the PARAMETERIZED constructor
    Point(Point &p);           // This is the COPY constructor
                               // ~Point();                  // This is the destructor
};
Point::Point()
{
    cout << "\nDefault Constructor of Point class is called.\n";
    this->_x = 0;
    this->_y = 0;
}
Point::Point(double x, double y)
{
    cout << "\nParameterised constructor is called.\n";
    this->_x = x;
    this->_y = y;
}
Point::Point(Point &p)
{
    cout << "\nCopy constructor is called.\n";
    this->_x = p._x;
    this->_y = p._y;
}
void Point::setCoords(double x, double y)
{
    cout << "Set coordinates member function called!\n";
    this->_x = x;
    this->_y = y;
}
void Point::printCoords() const
{
    cout << "\n( " << this->_x << " , " << this->_y << " )";
}
double Point::distFrom(Point &p) const
{
    cout << "\nDistance from function of Point class called!\n";
    return sqrt(pow(this->_x - p._x, 2) + pow(this->_y - p._y, 2));
}
class Location : public Point
{
    string address;

public:
    Location()
    {
        cout << "Default constructor of location class called!\n";
    }
    Location(double x_l, double y_l)
    {
        cout << "2 - arg constructor called!\n";
        // _x = x_l;
        // _y = y_l;
        // here we can call set coords of point also to set x and y - check
        setCoords(x_l, y_l);
    }
    Location(double x_l, double y_l, string add_l) : Point(x_l, y_l)
    {
        cout << "Derived class constructor called!";
        _x = x_l;
        _y = y_l;
        address = add_l;
    }
    void print_loc()
    {
        cout << "\n( " << _x << " , " << _y << " )";
        cout << "\nAddress - " << address << "\n";
    }
    /*double distFrom_loc(Location &l)
    {
        cout << "\nDistance from function of location class called!\n";
        return distFrom(l);
    }*/
    Location(string s1, string s2) : Point() // we are changing signature of constructor so that compiler distinguised
    // between the two default constructor (so called default becuse when we provide argument it is no more deafult)
    {
        cout << "Over riding default constructor.\n";
    }
    double distFrom(Location &loc)
    {
        cout << "\nDistFrom function of location class called!\n";
        double angle = acos(sin(this->_x*(M_PI/180)) * sin(loc._x*(M_PI/180)) + cos(this->_x*(M_PI/180)) * cos(loc._x*(M_PI/180)) * cos(loc._y*(M_PI/180) - this->_y*(M_PI/180)));
        return angle * EARTH_RADIUS*M_PI;
    }
};

int main()
{
    Location l0;
    // on instatntiating a object using default constructor there is error
    // hence we make a default constrcutor
    // now calling an object with only two coordinates
    // Location l_corrdinates(1.3, 1.5);
    // the statement above is throwing error
    // hence we will have to make constructor with just coordinates - like [oint class]
    // now that i have made 2 argument constructor it is working
    Location l_corrdinates(1.3, 1.5);
    l_corrdinates.print_loc();
    // 3 argument constructor called
    Location l1(28.66992, 77.29162, "shahadra mandi");
    l1.print_loc();
    Location l2(28.68991, 77.30672, "GTB CROSSING");
    l2.print_loc();
    cout << "\nDistance from l1 to l2 ";
    // cout << l1.distFrom(l2);
    // here distFrom of point is called
    // testing over ridin constructor
    Location l3("bushra", "shahzad");
    // after over rdiing
    cout << l1.distFrom(l2);
    //
    Location arr[10];
    arr[0] = {28.66992, 77.29162};
    arr[1] = {28.68991, 77.30672};
    arr[2] = {28.68991, 77.25796};
    arr[3] = {28.64789, 77.29509};
    arr[4] = {28.65005, 77.31381};
    arr[5] = {28.67069, 77.26678};
    arr[6] = {28.7111, 77.26034};
    arr[7] = {28.70129, 77.29146};
    arr[8] = {28.61812, 77.32086};
    arr[9] = {28.63583, 77.28713};
    
    double ans=0;
    for(int i=0;i<8;i++)
    {
        ans+=arr[i].distFrom(arr[i+1]);
    }
    cout<<ans*PI/180<<"\n";
    //
    Point p;
    p.print();

    Location l_virtual;
    l_virtual.print();

}