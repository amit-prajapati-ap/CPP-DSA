#include <iostream>
using namespace std;
int fact(int f);
int nCr(int n, int r);
int main()
{
    int ans, n, r;
    cout << "Enter the value of n & r : " << endl;
    cin >> n >> r;
    ans = nCr(n, r);
    cout << ans << endl;
}
int fact(int f)
{
    int temp = 1;
    for (int i = 1; i <= f; i++)
    {
        temp = temp * i;
    }
    return temp;
}
int nCr(int n, int r)
{
    int num = fact(n);
    int denum = fact(r) * fact(n - r);
    int answer = num / denum;
    return answer;
}