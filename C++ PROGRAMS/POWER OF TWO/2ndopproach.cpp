#include <iostream>
using namespace std;
int pow(int n)
{
    int count = 0, temp;
    temp = n;
    for (int i = 0; i < temp; i++)
    {
        if ((n & 1) == 1)
        {
            count++;
            n = n >> 1;
        }
        else
        {
            n = n >> 1;
        }
    }
    return count;
}
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    int power = pow(n);
    if (power == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}