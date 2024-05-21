#include <iostream>
using namespace std;
int main()
{
    int rupee, amount, ans;
    cout << "Enter the Amount : ";
    cin >> amount;
    cout << "Enter the Note Which you find (only 100,50,20,10) : ";
    cin >> rupee;
    switch (rupee)
    {
    case 100:
        ans = amount / 100;
        cout << "Number of notes : " << ans << endl;
        break;
    case 50:
        ans = amount / 50;
        cout << "Number of notes : " << ans << endl;
        break;
    case 20:
        ans = amount / 20;
        cout << "Number of notes : " << ans << endl;
        break;
    case 10:
        ans = amount / 10;
        cout << "Number of notes : " << ans << endl;
        break;

    default:
        break;
    }
}