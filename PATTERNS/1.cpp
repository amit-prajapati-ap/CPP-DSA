#include <iostream>
using namespace std;
int main()
{
    int n;
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}