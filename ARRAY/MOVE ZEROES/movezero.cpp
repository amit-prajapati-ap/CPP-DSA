#include <iostream>
using namespace std;
class zero
{
private:
    int arr[100], n;

public:
    void getdata();
    void movezero();
    void display();
};
int main()
{
    zero z;
    z.getdata();
    z.movezero();
    z.display();
}
void zero::getdata()
{
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements to move zero : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void zero::display()
{
    cout << "After moving zeroes : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}
void zero::movezero()
{
    int nonzero = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[nonzero]);
            nonzero++;
        }
    }
}