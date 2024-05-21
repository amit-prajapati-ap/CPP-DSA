#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    bool bl = 0;
    cout << "Enter Digits" << endl;
    cin >> n;
    for (int i = 0; i <= 30; i++)
    {
        int temp = pow(2, i);
        if (temp == n)
        {
            bl = 1;
            break;
        }
    }
    if (bl == 1)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}