#include <iostream>
using namespace std;
int main()
{
    int n;
    bool check = 1;
    cout << "ENTER A NUMBER TO CHECK WHEATHER IS PRIME OR NOT : " << endl;
    cin >> n;
    for (int i = 2; i < n; i++)
    {
        if ((n % i) == 0)
        {
            check = 0;
        }
    }
    if (check == 0)
    {

        cout << "NOT A PRIME NUMBER" << endl;
    }
    else
    {
        cout << "PRIME NUMBER" << endl;
    }
}