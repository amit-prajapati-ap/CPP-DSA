#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 1, n, temp;
    cout << "ENTER A NUMBER FOR PRINTING A FIBONACCI SERIES : " << endl;
    cin >> n;
    if (n == 0)
    {
        cout << a << '\t';
    }
    else if (n == 1)
    {
        cout << a << '\t' << b << '\t';
    }
    else
    {
        cout << a << '\t' << b << '\t';
        for (int i = 2; i < n; i++)
        {
            temp = a + b;
            a = b;
            b = temp;
            cout << temp << '\t';
        }
    }
}