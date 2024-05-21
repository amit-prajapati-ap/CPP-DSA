#include <iostream>
#include <string>
using namespace std;
int length(string str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
string rev(string str, int n)
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
string revword(string str, int n)
{
    string temp = "";
    string reverse = "";
    string revstr = "";
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        temp.push_back(str[i]);
        k++;
        if (str[i + 1] == ' ' || str[i + 1] == '\0')
        {
            reverse = rev(temp, k);
            revstr.append(reverse);
            revstr.push_back(' ');
            temp = "";
            k = 0;
        }
    }
    return revstr;
}
int main()
{
    string str = "";
    cout << "Enter a string : ";
    getline(cin, str);
    int n = length(str);
    string revstr = revword(str, n);
    cout << "After reversing the words : " << revstr;
}