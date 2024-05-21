#include <iostream>
using namespace std;
string addchar(string str)
{
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            temp.push_back('1');
            temp.push_back('0');
            temp.push_back('1');
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    return temp;
}
int main()
{
    string str;
    cout << "Enter a string : ";
    getline(cin, str);
    string add = addchar(str);
    cout << add;
}