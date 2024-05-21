#include <iostream>
using namespace std;
int main()
{
    int n, digit, rev = 0;
    cout << "Enter digits" << endl;
    cin >> n;
    while ( n != 0)
    {
        digit = n % 10;
        n = n / 10;
        rev = (rev * 10) + digit;
    }
    cout << rev;
}