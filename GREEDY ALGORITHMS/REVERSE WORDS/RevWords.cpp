#include <iostream>
#include <string>
using namespace std;
void reverse(string &str) {
    int i = 0 , j = str.length() - 1;
    while(i <= j) {
        swap(str[i++],str[j--]);
    }
}
string RevWords(string str)
{
    string ans = "", temp = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == '.')
        {
            reverse(temp);
            ans = ans + temp + '.';
            temp = "";
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    reverse(temp);
    ans += temp;
    return ans;
}
int main()
{
    string str = "";
    cout << "Enter The Phrase Of Words : " << endl;
    getline(cin, str);
    str = RevWords(str);
    cout << "Reversed String : " << endl
         << str << endl;
}