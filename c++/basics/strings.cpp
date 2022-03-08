#include <iostream>

using namespace std;

int main()
{
    string phrase = "This is a string";
    cout << phrase << "\nHere is a new line\n";
    cout << phrase.length() << ": is the length.\n";
    cout << phrase.find("string", 0) << ": is the starting position of 'string'.\n";

    cout << phrase.substr(8, 3) << ": is three charcters starting at index: 8\n";

    return 0;
}