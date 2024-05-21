#include <iostream>
using namespace std;
void ap(int n)
{
    int ans;
    for (int i = 1; i <= n; i++)
    {
        ans = 3 * i + 7;
        cout << ans << "\t";
    }
}
int main()
{
    int n, ans;
    cout << "Enter the number to find nth term" << endl;
    cin >> n;
    ap(n);
}