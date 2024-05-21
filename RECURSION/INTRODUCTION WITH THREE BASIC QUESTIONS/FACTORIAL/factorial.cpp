#include <iostream>
using namespace std;
long long int fact(int n)
{
    cout << "Value of n = " << n << endl;
    if (n == 1)
        return 1;

    return n * fact(n - 1);
}
int main()
{

    int n;
    cout << "Enter the number : ";
    cin >> n;
    cout << "Factorial of " << n << " is " << fact(n) << endl;
}