#include <iostream>
#include <stack>
using namespace std;
string solve(string str, stack<char> s)
{
    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }
    str = "";
    while (!s.empty())
    {
        str.push_back(s.top());
        s.pop();
    }
    return str;
}
int main()
{

    string str;
    stack<char> s;
    cout << "Enter a string : ";
    cin >> str;
    str = solve(str, s);
    cout << "Reverse String is : " << str << endl;
}