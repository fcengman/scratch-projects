#include <iostream>

using namespace std;

string day_of_the_week(int day_num)
{
    string day;
    switch (day_num)
    {
    case 1:
        day = "Mon";
        break;
    case 2:
        day = "Tues";
        break;
    case 3:
        day = "Wed";
        break;
    case 4:
        day = "Thurs";
        break;
    case 5:
        day = "Fri";
        break;
    case 6:
        day = "Sat";
        break;
    case 7:
        day = "Sun";
        break;
    default:
        day = "Invalid day number";
    }

    return day;
}

int main()
{
    string stars = "*";
    int length = 50;

    for (int i = 0; i < length; i++)
    {
        if (i < length / 2)
        {
            cout << stars << endl;
            stars = stars + "*";
        }
        else
        {
            stars = stars.substr(0, stars.length() - 1);
            cout << stars << endl;
        }
    }

    cout << day_of_the_week(1) << endl;
    cout << day_of_the_week(10) << endl;
}
