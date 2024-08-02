#include <iostream>
using namespace std;
class Line
{
private:
    double length;

public:
    void setLength(double len);
    double getLength(void);
     Line(const Line &l1);  // This is a copy constructor for optional question
    ~Line();                // This is the destructor: declaration
   
};

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
    // as seen we are unable to instantiate an obeject if there is a copy const and no default cont

    


    
    return 0;
}