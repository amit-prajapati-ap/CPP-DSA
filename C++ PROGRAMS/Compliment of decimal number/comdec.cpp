#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, m, ans, mask = 0;
    cout << "Enter a decimal number" << endl;
    cin >> n;
    m = n;
    if (n == 0)
    {
        cout << "1";
    }
    else
    {
        while (m != 0)
        {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        ans = (~n) & mask;
        cout << ans;
    }
}