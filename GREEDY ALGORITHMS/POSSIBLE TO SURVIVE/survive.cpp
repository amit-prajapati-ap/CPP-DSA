#include <iostream>
using namespace std;
int PossibleSurvive(int n, int m, int s)
{
    int sunday = s / 7;
    int buydays = s - sunday;
    int totalfood = s * m;
    int ans = 0;
    if (totalfood % n == 0)
    {
        ans = totalfood / n;
    }
    else+
    {
        ans = totalfood / n + 1;
    }
    if (ans <= buydays)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int n, s, m;
    cout << "Enter The Max food per Day by Shop : ";
    cin >> n;
    cout << "Enter The Days to Survive : ";
    cin >> s;
    cout << "Enter The food per day to Survive : ";
    cin >> m;
    int ans = PossibleSurvive(n, m, s);
    if (ans != -1)
    {
        cout << "Minimum Days To Buy Food To Survive : " << ans << endl;
    }
    else
    {
        cout << "Impossible To Survive" << endl;
    }
}