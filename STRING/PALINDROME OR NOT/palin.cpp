#include <iostream>
using namespace std;
string findrev(string str, int n)
{
    int s = 0, e = n - 1;
    while (s < e)
    {
        swap(str[s++], str[e--]);
    }
    return str;
}
char upper(char str)
{
    if (str >= 'A' && str <= 'Z')
    {
        return str;
    }
    else
    {
        return (str = (str - 'a') + 'A');
    }
}
bool check_pal(string str, int n)
{
    int s = 0, e = n - 1;
    while (s < e)
    {
        if (upper(str[s++]) != upper(str[e--]))
        {
            return false;
        }
    }
    return true;
}
int length(string str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
int main()
{
    string str = "";
    cout << "Enter a string : ";
    cin >> str;
    int n = length(str);
    bool bl = check_pal(str, n);
    string s = findrev(str, n);
    cout << "Reverse string is : " << s << endl;
    cout << "Palindrome or not : " << bl << endl;
}