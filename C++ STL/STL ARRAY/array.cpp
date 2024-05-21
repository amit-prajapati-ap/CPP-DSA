// Array is a static data structure,It is same like normal array.
#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> a = {1, 2, 3, 4, 5};
    int s = a.size();
    cout << "Size of array is " << s << endl;
    for (int i = 0; i < s; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Front elements is " << a.front() << endl;
    cout << "Last element is " << a.back() << endl;
    cout << "Array is empty or not ->" << a.empty() << endl;
    cout << "3rd element is " << a.at(2) << endl;
}