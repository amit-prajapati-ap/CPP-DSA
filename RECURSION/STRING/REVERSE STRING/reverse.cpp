#include <iostream>
using namespace std;
void reverse(string &str, int i, int j)
{
    if (i > j)
    {
        return;
    }

    swap(str[i], str[j]);
    reverse(str, ++i, --j);
}
int main()
{
    string str = "Amit";
    reverse(str, 0, str.size() - 1);
    cout << str << endl;
}