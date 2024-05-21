#include <iostream>
using namespace std;
long long int pow(int value, int power)
{
    if (power == 0)
        return 1;
    cout << value << " ki power " << power << endl;
    return value * pow(value, power - 1);
}
int main()
{

    int value, power;
    cout << "Enter the value that you want to find power : ";
    cin >> value;
    cout << "Enter the power : ";
    cin >> power;
    cout << pow(value, power) << endl;
}