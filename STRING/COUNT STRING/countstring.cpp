#include <iostream>
using namespace std;
void toupper(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 'a' + 'A';
            str[i] = ch;
        }
    }
}
void count(string str, int &vowels, int &consonents, int &digits, int &spaces)
{
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == ' ')
        {
            spaces++;
        }
        else if (ch >= '0' && ch <= '9')
        {
            digits++;
        }
        else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            vowels++;
        }
        else
        {
            consonents++;
        }
    }
}
int main()
{
    string str;
    cout << "Enter The Sentance : " << endl;
    getline(cin, str);
    toupper(str);
    cout << str << endl;
    int vowels = 0, consonents = 0, digits = 0, spaces = 0;
    count(str, vowels, consonents, digits, spaces);
    cout << "Vowels : " << vowels << endl
         << "Consonents : " << consonents << endl
         << "Digits : " << digits << endl
         << "Spaces : " << spaces << endl;
}