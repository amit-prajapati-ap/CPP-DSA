// Vector is a dynamic array which can dynamically arrange our size.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    cout << v.size() << " " << v.capacity() << endl;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    for (int i : v)
    {
        cout << i << ' ';
    }
    cout << endl;
    v.pop_back();
    for (int i : v)
    {
        cout << i << ' ';
    }
    cout << endl;
    cout << v.size() << " " << v.capacity() << endl;
    v.push_back(9);
    v.push_back(7);
    cout << "Front element is " << v.front() << endl;
    cout << "back element is " << v.back() << endl;
    cout << "Element at index 5 is " << v.at(4) << endl;
    vector<int> vec(v);
    for (int i : vec)
    {
        cout << i << ' ';
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << ' ';
    }
}