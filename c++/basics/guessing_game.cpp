#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));
    int value = rand() % 100 + 1;
    int guess;
    int remaining = 15;
    cout << "I have a number between 1 and 100.";
    do
    {
        cout << "You have " << remaining << " guesses left. Guess: ";
        cin >> guess;
        if (value == guess)
        {
            cout << "You got it! The number was " << value;
            break;
        }
        else if (guess > value)
        {
            cout << "That's too high!" << endl;
        }
        else if (guess < value)
        {
            cout << "That's too low!" << endl;
        }
        remaining--;
    } while (remaining > 0);
}