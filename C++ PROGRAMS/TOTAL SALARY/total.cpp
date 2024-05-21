#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int basic = 5000;
    char grade = 'C';
    double hra, da, pf, totalsal;
    int ans, allowance;
    hra = 0.2 * basic;
    da = 0.5 * basic;
    pf = 0.11 * basic;
    if (grade == 'A')
    {
        allowance = 1700;
    }
    else if (grade == 'B')
    {
        allowance = 1500;
    }
    else
    {
        allowance = 1300;
    }
    totalsal = basic + hra + da + allowance - pf;

    ans = round(totalsal);
    cout << ans;
}