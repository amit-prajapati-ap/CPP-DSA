#include <iostream>
using namespace std;
char upper(char ch)
{
    if (ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
    {
        return ch;
    }
    else
    {
        return (ch = ch - 'a' + 'A');
    }
}
bool nospecial(char ch)
{
    if (ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z')
    {
        return true;
    }
    return 0;
}
string removes(string str, int n)
{
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        if (nospecial(str[i]))
        {
            temp.push_back(upper(str[i]));
        }
    }
    return temp;
}
int main()
{
    string str;
    cout << "Enter a string : ";
    cin >> str;
    int n = str.length();
    string newstr = removes(str, n);
    cout << "New string is : " << newstr;
}