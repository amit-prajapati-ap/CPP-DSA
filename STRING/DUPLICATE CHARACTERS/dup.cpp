#include <iostream>
#include <algorithm>
using namespace std;
void dup(string str)
{
    int len = str.length();
    sort(str.begin(), str.end());
    for (int i = 0; i < len; i++)
    {
        int count = 1;
        while (i < (len - 1) && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        if (count > 1)
        {
            cout << str[i] << " is repeat number of " << count << " times" << endl;
        }
    }
}
int main()
{
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;
    dup(s);
}