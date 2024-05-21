#include <iostream>
using namespace std;
bool palindrome(string &str, int i, int j)
{
    if (i > j)
    {
        return true;
    }
    if (str[i] != str[j])
    {
        return false;
    }
    else
    {
        palindrome(str, ++i, --j);
    }
}
int main()
{
    string str = "Amit";

    bool ans = palindrome(str, 0, str.size() - 1);
    if (ans)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
}