#include <iostream>
using namespace std;
int main()
{
    char ch;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            ch = 'A'+j+n-i-1;
            cout << ch << " ";
        }
        cout << endl;
    }
}