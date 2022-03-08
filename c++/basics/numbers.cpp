#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int wnum = 5;
    double dnum = 5.5;
    cout << wnum + dnum << endl;

    int a = 10;
    int b = 3;
    cout << pow(a, b) << endl;
    cout << sqrt(a) << endl;
    cout << ceil(dnum) << endl;
    cout << floor(dnum) << endl;
    cout << fmax(dnum, b) << endl;
    cout << fmin(dnum, b) << endl;
    return 0;
}