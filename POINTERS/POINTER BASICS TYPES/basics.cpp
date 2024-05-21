#include <iostream>
using namespace std;
void temp(int *p)
{
    int a = 5;
    p = &a;
    cout << *p << endl;
}
int main()
{
    // BASICS
    /*
   int a = 5;
     int *ptr = &a;
     cout << *ptr << endl;
     cout << a << endl;
     cout << ptr << endl;
     cout << &a << endl;
    */
    // WILD PTR
    /*
     int a = 5;
     int *ptr; // wild pointer
     cout << ptr << endl;
     cout << *ptr << endl;
     ptr = &a;
     cout << ptr << endl;
     cout << *ptr << endl;
    */
    // DANGLING PTR
    /*
    int *ptr = 0; // NULL PTR
    temp(ptr);
    cout << ptr << endl;
    */
    // VOID PTR
    /*
    int *ptr2 = 0;
    char *ptrch = 0;
    void *ptr;
    int a = 5;
    char str[20] = "Amit";
    ptr = &a;
    ptr2 = ptr;
    cout << ptr << endl;
    ptr = &str;
    ptrch = ptr;
    cout << ptr << endl;
    */
}