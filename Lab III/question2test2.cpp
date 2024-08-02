// Test for Memory is allocated for static data members once they are defined even though no objects
//of that class have been instantiated.
#include <iostream>
using namespace std;
class Point {
public:
    // Static data member
    static int count;
};

// Define and initialize the static data member outside the class
int Point::count = 100;

int main() {
    // Accessing the static data member without creating an object
    cout << "Count " << Point::count << endl;
    cout<<"Size of Count "<<sizeof(Point::count)<<endl;
    cout<<"Address of Count "<<&(Point::count)<<endl;

    // the address is displayed implying memory have been allocated to static member 
    // even before any object has been created

    // Now creating objects of the class
    Point p1;
        return 0;
}
