#include <iostream>

using namespace std;

int main()
{
    int nums[10] = {1, 2, 3, 4};

    // cout << nums[10];
    // nums.insert(1);

    int grid[2][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}