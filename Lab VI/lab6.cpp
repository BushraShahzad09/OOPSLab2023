#include <iostream>
#include <vector>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;
class Vector;
class Point
{
    double _x;
    double _y;

public:
    Point(){};
    Point(double *p)
    {
        _x = p[0];
        _y = p[1];
    };
    Point(double x, double y)
    {
        _x = x;
        _y = y;
    }
    operator double *() const
    {
        cout << "converion operator called\n";
        double *coords = new double[2];
        coords[0] = _x;
        coords[1] = _y;
        return coords;
    }
    double &operator[](int i)
    {
        cout << "Subscript operator called" << endl;
        if (i > 1 or i < 0)
        {
            cout << "Error" << endl;
        }
        else if (i == 0)
        {
            return _x;
        }
        else
        {
            return _y;
        }
    };
    operator Vector() const;
    void print_coords() const
    {
        cout << this->_x << ", " << this->_y << endl;
    }
    double get_coords(int i) const
    {
        return i == 0 ? _x : _y;
    }
};

class Vector
{
    double v_x;
    double v_y;
    double degree;

public:
    Vector()
    {
        cout << "\ndefault constrctor called\n";
    };
    Vector(double x, double y, double deg)
    {
        cout << "vector parameterised constructor called\n";
        v_x = x;
        v_y = y;
        degree = deg;
    };
    operator Point() const
    {
        cout << "Conversion operator from vector to point called\n";
        Point p(v_x, v_y);
        return p;
    }
    Vector(Vector &v1)
    {
        cout << "\ncpoy constructor\n";
        v_x = v1.v_x;
        v_y = v1.v_y;
        degree = v1.degree;
    }
    ~Vector(){};
    void print_vector()
    {
        cout << this->v_x << ", " << this->v_y << endl;
    }
    friend ostream &operator <<(ostream &os,const Vector&v){
        os<<"\nVector "<<v.v_x<<" "<<v.v_y<<" \n";
        return os;
    }
};
void problem1()
{
    cout << "Problem1" << endl;
    double arr[2] = {1.5, 1.3};
    Point p1(arr);
    p1.print_coords();
    double *arr1 = p1;
    cout << "1st array element is - " << arr1[0];
    cout << "2st array element is - " << arr1[1];
}

void problem2()
{
    double arr[] = {1, 2};
    Point p1(arr);
    cout << p1[0] << "," << p1[1];
    double *parr = p1;
    cout << parr[0] << "," << parr[1];
}
Point::operator Vector() const
{
    cout << "Conversion operator from point to vector called\n";
    Vector v(_x, _y, 0.0);
    return v;
}
int main()
{
    problem1();
    problem2();

    // 
    cout<<"\ncheck code\n";
    Vector v1;
    Point p1(1, 1);
    v1 = p1;
    cout << v1;
    return 0;
}