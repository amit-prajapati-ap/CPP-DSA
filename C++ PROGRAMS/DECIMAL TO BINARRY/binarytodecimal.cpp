#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, ans = 0;
    cout << "Enter a binary number" << endl;
    cin >> n;
    int i = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if (digit == 1)
        {
            ans = ans + pow(2, i);
            n = n / 10;
            i++;
        }
        else
        {
            n = n / 10;
            i++;
            continue;
        }
    }
    cout << ans;
}