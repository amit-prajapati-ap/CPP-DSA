#include <iostream>
using namespace std;
char getcharacter(string str)
{
    int arr[26] = {0}, maxi = -1, ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int count = 0;
        count = ch - 'a';
        arr[count]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }
    char che = 'a' + ans;
    return che;
}
int main()
{
    string str;
    cout << "Enter the string : ";
    getline(cin, str);
    char ch = getcharacter(str);
    cout << "Answer is : " << ch << endl;
}