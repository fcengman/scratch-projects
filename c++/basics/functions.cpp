#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

void subtract(int a, int b)
{
    cout << a - b;
}

int main()
{
    cout << add(1, 2) << endl;
    subtract(2, 1);
    return 0;
}