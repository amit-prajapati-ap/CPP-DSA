// Example of reference variable
// Same memory address and different names of this address
#include <iostream>
using namespace std;
void update(int &i)
{
    i++;
}
int &func(int i)
{
    int a = i;
    int &ans = a;
    a++;
    return ans;
}
int *func2(int i)
{
    int *ptr = &i;
    *ptr++;
    return ptr;
}
int main()
{
    /*int i = 5;
    int &j = i;
    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;
    cout << j << endl;
    */
    // Pass by reference
    /*

     int n = 5;
     cout << "Before func call : " << n << endl;
     update(n);
     cout << "After func call : " << n << endl;
    */
    // Return by reference
    // Bad practice
    /*

    int n = 5;
    cout << func(n) << endl;
    */
    // Return by pointer
    int n = 5;
    cout << func2 << endl;
}