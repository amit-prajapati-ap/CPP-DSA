#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
string solve(string str)
{
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        count[ch]++;
        q.push(ch);
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}
int main()
{
    string str;
    cout << "Enter The String : " << endl;
    cin >> str;
    string ans = solve(str);
    cout << "1st Non-Repeating Chars in String : " << endl
         << ans;
}