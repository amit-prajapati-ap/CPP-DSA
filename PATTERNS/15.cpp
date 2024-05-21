#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int space = i - 1;
        for (int s = 1; s <= space; s++)
        {
            cout << ' ';
        }
        cout << endl;
        int temp = n - i + 1;
        for (int j = 1; j <= temp; j++)
        {
            cout << i;
        }
    }
}