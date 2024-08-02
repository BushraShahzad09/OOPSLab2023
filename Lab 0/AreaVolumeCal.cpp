#include <iostream>
using namespace std;
class oops{
    public:
    float length;
    float breadth;
    float height;
    float area(){
        return length*breadth;
    }
    float volume(){
        return length*breadth*height;
    }
};
int main() {
   
    cout << "Hello world!";
  //  oops*abc=new oops();  -- dynamic allocation
  oops abc;
    cout<<"\nEnter length :";
    cin>>abc.length;
    cout<<"Length is "<<abc.length;
    
    cout<<"\nEnter breadth :";
    cin>>abc.breadth;
    cout<<"Breadth is "<<abc.breadth;
   
    cout<<"\nEnter height :";
    cin>>abc.height;
    cout<<"Height is "<<abc.height;
    
    cout<<"\nArea is :"<<abc.area();
    cout<<"\nVolume is "<<abc.volume();
    
    return 0;
}
