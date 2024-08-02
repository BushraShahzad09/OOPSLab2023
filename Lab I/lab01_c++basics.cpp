#include <iostream>
using namespace std;
// Problem 03 clock class
class Clock
{
private:
    int hour;        // an hour in the range 1 - 12
    int minute;      // a minute in the range 0 - 59
    int second;      // a second in the range 0 - 59
    string meridian; // is the time AM or PM

public:
    // set the clock to the specified time
    void setClock(int h, int m, int s, string mer)
    {
        if (h >= 1 && h <= 12 && m >= 0 && m <= 59 && s >= 0 && s <= 59)
        {
            hour = h;
            minute = m;
            second = s;
            meridian = mer;
        }
        else
        {
            cout << "Invalid time input." << endl;
        }
    }

    // display the time in standard notation
    void displayStandard()
    {
        cout << hour << ":" << (minute < 10 ? "0" : "") << minute << ":" << (second < 10 ? "0" : "") << second << " " << meridian << endl;
    }

    // display the time in military notation
    void displayMilitary()
    {

        if (meridian == "AM" || meridian == "am")
        {
            if (hour == 12)
            {
                hour = 0; // midnight
            }
        }
        else if (meridian == "PM" || meridian == "pm")
        {
            if (hour != 12)
            {
                hour += 12; // adding 12 hours forevening times
            }
        }
        cout << hour << ":" << (minute < 10 ? "0" : "") << minute << ":" << (second < 10 ? "0" : "") << second << endl;
    }
};
int main()
{
    // Problem 01
    cout << "Hello World!\n";
    // Problem 02
    double pounds, kilograms;

    cout << "\nEnter the weight in pounds: ";
    cin >> pounds;

    kilograms = pounds * 0.453592;

    cout << pounds << " pounds is " << kilograms << " kilograms." << endl
         << endl;

    cout << "Enter the weight in kilograms: ";
    cin >> kilograms;

    pounds = kilograms / 0.453592;

    cout << kilograms << " kilograms is " << pounds << " pounds.\n"
         << endl;

    // Problem 03
    Clock myClock;
    myClock.setClock(5, 30, 45, "PM");

    cout << "Standard Format: ";
    myClock.displayStandard();

    cout << "Military Format: ";
    myClock.displayMilitary();

    return 0;
}
