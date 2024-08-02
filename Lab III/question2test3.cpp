// Test for Static member functions cannot access non-static data members.
#include <iostream>
using namespace std;
class Point {
private:
    int x;
    int y;
public:
    static void staticMemberFunction01() {
        // uncommenting the line below should result in a compilation error
        // as staticMemberFunction is static and cannot access non-static members directly.
        //cout << "X: " << x << endl;
        cout<<"Static member function 1 called!\n";
    }
    static void staticMemberFunction02(Point &p) {
         p.x=78;
         p.y=87;
         cout<<"Static memeber function 2 with point as paramter called.\n";
    }
};

int main() {
    Point p;
    p.staticMemberFunction01();
    p.staticMemberFunction02(p);
    // As noted, if we pass an object as argument to the static member function 
    //then it can access that object’s data non static data members

    return 0;
}
