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
    Point linear_comb(Point &p, double s) const;
    double l2Norm() const;
    Point();                   // This is the DEFAULT constructor
    Point(double x, double y); // This is the PARAMETERIZED constructor
    Point(Point &p);           // This is the COPY constructor
    // ~Point();               // This is the destructor
    Point operator+(const Point &p) const;
    bool operator<(const Point &p) const;
    bool operator>(const Point &p) const;
    bool operator==(const Point &p) const;
    Point operator*(double scale) const;
    // double operator[](int index) const;                // this overloading works only with r value
    double &operator[](int index);
    friend ostream &operator<<(ostream &os, const Point &p);

    static int getCount();
};
Point::Point()
{
    count++;
    // cout << "\nConstructor is called.";
    this->_x = 0;
    this->_y = 0;
}
Point::Point(double x, double y)
{
    count++;
    // cout << "\nParameterised constructor is called.";
    this->_x = x;
    this->_y = y;
}
Point::Point(Point &p)
{
    count++;
    // cout << "\nCopy constructor is called.";
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
Point Point::linear_comb(Point &p, double s) const
{
    Point q;
    q = ((*this) * s) + p * (1 - s);
    return q;
}
double Point::l2Norm() const
{
    return sqrt(pow(_x, 2) + pow(_y, 2));
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
double &Point::operator[](int index)
{
    double ans = 0.0;
    if (index == 0)
        return _x;
    else if (index == 1)
        return _y;
    else
    {
        cout << "\nInvalid Index";
    }
    return ans;
}
ostream &operator<<(ostream &os, const Point &p)
{
    os << "\nPoint (" << p._x << ", " << p._y << "),Norm = " << p.l2Norm();
    return os;
}
int Point::count = 0;
Point *construct_array(int size)
{
    Point *points_arr = new Point[size];
    // initialise with random points
    for (int i = 0; i < size; i++)
    {
        points_arr[i] = Point(1.0 + static_cast<double>(rand()) / (RAND_MAX / 99.0), 1.0 + static_cast<double>(rand()) / (RAND_MAX / 99.0));
    }
    return points_arr;
}
void insertionSort(Point arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Point temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = temp;
    }
}
double measure_execution_time(void insertionSort(Point[], int), Point arr[], int n)
{
    clock_t start_time = clock();
    insertionSort(arr, n);
    clock_t end_time = clock();
    return double(end_time - start_time) / CLOCKS_PER_SEC ; 
}

int main()
{
    // l2Norm
    Point P1(1, 2);
    double norm_p1 = P1.l2Norm();
    cout << "\nNorm " << norm_p1;

    // overloading the subscript operator for r value
    Point P2(3, 5);
    double ans_x = P2[0];
    double ans_y = P2[1];
    cout << "\n"
         << ans_x << " " << ans_y << "\n";

    // what about l value if we want to set the value i.e P2[0]=20
    // P2[0]=20; // the given line of code gives error and hence to make it work we need to
    // Overload the subscript operator "[]" so that it works both when a Point object is an l-value
    // and when it is an r-value.

    Point P3;
    P3[0] = 5;
    P3[1] = 9;

    P3.printCoords();

    // overlaoding ostream <<
    Point P4(2.4, 6.7);
    cout << P4;

    // Question 2 insertion sort
    // array of point objects of size

    Point *points_10 = construct_array(10);

    // cout << "\nUnsorted array of size 10 \n";
    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << points_10[i] << " ";
    // }
    // cout << "\n\n";

    // cout << "\nSorted array of size " << 10 << ":\n";
    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << points_10[i] << " ";
    // }
    double duration_10 = measure_execution_time(insertionSort, points_10, 10);
    cout << "\nSorting time for array of size 10 is " << duration_10*1e6 << " microseconds\n"; // to convert to microseconds
    
    Point *points_100 = construct_array(100);
    double duration_100 = measure_execution_time(insertionSort, points_100, 100);
    cout << "\nSorting time for array of size 100 is " << duration_100 << " seconds\n";

    Point *points_1000 = construct_array(1000);
    double duration_1000 = measure_execution_time(insertionSort, points_1000, 1000);
    cout << "\nSorting time for array of size 1000 is " << duration_1000 << " seconds\n";

    Point *points_10000 = construct_array(10000);
    double duration_10000 = measure_execution_time(insertionSort, points_10000, 10000);
    cout << "\nSorting time for array of size 10000 is " << duration_10000 << " seconds\n";

    // writing insertion sort for int for the same data

    return 0;
}
