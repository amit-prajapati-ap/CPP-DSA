#include <iostream>
#include <stack>
using namespace std;
bool Redundant(string str)
{

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool redun = true;
                while (s.top() != '(')
                {
                    char cha = s.top();
                    if (cha == '+' || cha == '-' || cha == '*' || cha == '/')
                    {
                        redun = false;
                    }
                    s.pop();
                }
                if (redun == true)
                {
                    return true;
                }
                s.pop();
            }
        }
    }

    return false;
}
int main()
{

    string str;
    cout << "Enter The String : ";
    cin >> str;
    if (Redundant(str))
    {
        cout << "There is Redundant Brackets" << endl;
    }
    else
    {
        cout << "Not Any Redundant Bracket" << endl;
    }
}