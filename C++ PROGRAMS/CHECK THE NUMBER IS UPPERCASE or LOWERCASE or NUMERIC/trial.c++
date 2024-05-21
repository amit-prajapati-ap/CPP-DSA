#include <iostream>
using namespace std;

int main()
{
    char ch;
    char uppb = 65;
    char uppl = 91;
    char lowb = 97;
    char lowl = 122;
    cin >> ch;
    int n = ch;
    if (n >= uppb && n <= uppl)
    {
        cout << "UPPERCASE " << n << endl;
    }
    else if (n >= lowb && n <= lowl)
    {
        cout << "lowercase " << n << endl;
    }
    else
    {
        cout << "NUMERIC " << n << endl;
    }
}