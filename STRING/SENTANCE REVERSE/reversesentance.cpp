#include <iostream>
#include <string.h>
using namespace std;
string reverse(string str)
{
    int s = 0;
    int e = str.length() - 1;
    while (s < e)
    {
        swap(str[s], str[e]);
        s++;
        e--;
    }
    return str;
}
/*string reversesentance(string str)
{
    string tempword = "", ans = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        tempword.push_back(str[i]);
        if (str[i] == ' ')
        {
            string rev = reverse(tempword);
            if (rev[0] == ' ')
            {
                rev.erase(0, 1);
                rev.push_back(' ');
            }
            for (int i = 0; i < rev.length(); i++)
            {
                ans.push_back(rev[i]);
            }
            tempword = "";
        }
        else if (i == 0)
        {
            string rev = reverse(tempword);
            for (int i = 0; i < rev.length(); i++)
            {
                ans.push_back(rev[i]);
            }
            tempword = "";
        }
    }
    return ans;
}*/
// 2nd approach
/*string reversesentance(string str)
{
    string tempword = "", ans = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        tempword.push_back(str[i]);
        if (str[i - 1] == ' ' || i == 0)
        {

            string rev = reverse(tempword);
            rev.push_back(' ');
            for (int i = 0; i < rev.length(); i++)
            {
                ans.push_back(rev[i]);
            }
            tempword = "";
        }
    }
    ans.erase(ans.length()-1,1);
    return ans;
}*/
//3rd approach
string reversesentance(string str) {
    string tempword = "",ans = "";
    int end = str.length()-1;
    while (end >= 0)
    {
        if (str[end] == ' ')
        {
            end--;
            continue;
        }
        tempword.push_back(str[end]);
        if (str[end - 1] == ' ' || end == 0)
        {

            string rev = reverse(tempword);
            rev.push_back(' ');
            for (int i = 0; i < rev.length(); i++)
            {
                ans.push_back(rev[i]);
            }
            tempword = "";
        }
        end--;
    }
    ans.erase(ans.length()-1,1);
    return ans;
    
}
int main()
{
    string str;
    cout << "Enter a string : " << endl;
    getline(cin, str);
    cout << "String before reversing sentance : " << endl
         << str << endl;
    cout << "Length is " << str.length() << endl;
    string ans = reversesentance(str);
    cout << "String after reversing sentance : " << endl
         << ans << endl;
    cout << "Length is " << ans.length() << endl;
}