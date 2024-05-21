#include <iostream>
#include <stack>
using namespace std;
bool open(char ch)
{
    if (ch == '(' || ch == '{' || ch == '[')
    {
        return true;
    }
    return false;
}
bool check(char top, char ch)
{
    if (top == '(' && ch == ')' || top == '[' && ch == ']' || top == '{' && ch == '}')
    {
        return true;
    }
    return false;
}
bool valid(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (open(ch))
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if (check(top, ch))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{

    string str;
    cout << "Enter Paranthesis : ";
    cin >> str;
    if (valid(str))
    {
        cout << "Valid Paranthesis" << endl;
    }
    else
    {
        cout << "Not a Valid Paranthesis" << endl;
    }
}