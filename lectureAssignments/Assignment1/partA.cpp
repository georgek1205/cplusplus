#include <iostream>
#include "today.h"
using namespace std;
 
int main()
{
    int year, month, day, det = 0, lucky;
    cout << "Please enter your birth date (yyyy mm dd) :" << endl;
    cin >> year >> month >> day;
    lucky = (year / 1000) + ((year % 1000) / 100) + ((year % 100) / 10) + (year % 10) + month + (day / 10) + (day % 10);
     
    if(year < 1900)
    {
        cout << "Year not in range!!" << endl;
        det = 1;
    }
    if(month < 1 || month > 12 || day < 1 || day > 31)
    {
        cout << "Invalid date!!" << endl;
        det = 1;
    }
 
    if(year > ThisYear())
    {
        cout << "You are not born yet!!" << endl;
        det = 1;
    }
    else if(year == ThisYear())
    {
        if(month > ThisMonth())
        {
            cout << "You are not born yet!!" << endl;
            det = 1;
        }
        else if(month == ThisMonth() && day > ThisMonth())
        {
            cout << "You are not born yet!!" << endl;
            det = 1;
        }
    }
    else if(year > ThisYear())
    {
        cout << "You are not born yet!!" << endl;
        det = 1;
    }
    else if(year == ThisYear() && month == ThisMonth() && day == ThisDay())
    {
        cout << "Happy Birthday!!." << endl;
    }
     
    if(!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
    {
        if(day == 29)
        {
            cout << "Invalid date!!" << endl;
            det = 1;
        }
         
    }
 
     
    if (det == 0)
    {
        cout << "Your birthday was on " << day;
        if(day == 1 || day == 21 || day == 31)
            cout << "st ";
        else if(day == 2 || day == 22)
            cout << "nd ";
        else if(day == 3 || day == 23)
            cout << "rd ";
        else
            cout << "th ";
         
        if(month == 1)
            cout <<  "January ";
        else if(month == 2)
            cout << "February ";
        else if(month == 3)
            cout << "March ";
        else if(month == 4)
            cout << "April ";
        else if(month == 5)
            cout << "May ";
        else if(month == 6)
            cout << "June ";
        else if(month == 7)
            cout << "July ";
        else if(month == 8)
            cout << "August ";
        else if(month == 9)
            cout << "September ";
        else if(month == 10)
            cout << "October ";
        else if(month == 11)
            cout << "November ";
        else if(month == 12)
            cout << "December ";
         
        cout << year << "." << endl;
    }
     
    if(det == 0)
    {
        int result = (lucky/10) + (lucky%10);
        while(result/10 != 0)
        {
            result = (result/10) + (result%10);
        }
        cout << "Your lucky number is " << result << "." << endl;
    }
         
 
     
 
    return 0;
}
