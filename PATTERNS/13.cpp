#include <iostream>
using namespace std;
int main()
{
    int n;
    char ch = ' ';
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int space = n - i;
        for (int k = 0; k < space; k++)
        {
            cout << ch;
        }

        for (int j = 0; j < i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
}