#include <iostream>
using namespace std;
bool even(int n)
{
    if ((n & 1) == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int num;
    cout << "Enter a Number To check that is even or odd" << endl;
    cin >> num;
    int ans = even(num);
    if (ans == 1)
    {
        cout << "NUMBER IS EVEN" << endl;
    }
    else
    {
        cout << "NUMBER IS ODD" << endl;
    }
}