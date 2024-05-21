#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    long int n, ans = 0;
    cout << "Enter a decimal number" << endl;
    cin >> n;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = ans + (pow(10, i) * bit);
        n = n >> 1;
        i++;
    }
    cout << ans;
}