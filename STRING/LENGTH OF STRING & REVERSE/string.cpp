#include <iostream>
using namespace std;
string reverse(string str, int n)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        swap(str[s], str[e]);
        s++;
        e--;
    }
    return str;
}
int length(string str)
{
    int ans = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        ans++;
    }
    return ans;
}
int main()
{
    string str;
    cout << "Enter your name : ";
    cin >> str;
    int n = length(str);
    string ans = reverse(str, n);
    cout<<"After reverse : "<<ans;
}