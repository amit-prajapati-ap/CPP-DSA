#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    print(n - 1);
}
void print2(int n)
{
    if (n == 0)
    {
        return;
    }
    print2(n - 1);
    cout << n << " ";
}

int main()
{

    int n;
    cout << "Enter the number : ";
    cin >> n;
    cout << "Simple order : " << endl;
    print(n);
    cout << endl;
    cout << "Reverse order : " << endl;
    print2(n);
}