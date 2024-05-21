#include <iostream>
using namespace std;
int expo(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    int ans = expo(a, b / 2);
    if ((b & 1) == 1)
    {
        return a * (ans * ans);
    }
    else
    {
        return ans * ans;
    }
}
int main()
{

    int a, b;
    cout << "Enter the value of a and b :" << endl;
    cin >> a >> b;
    cout << expo(a, b) << endl;
}