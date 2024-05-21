#include <iostream>
using namespace std;
class moved
{
    int arr[100], n;
    void moving()
    {
        // 1st approach
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= 0)
            {
                if (arr[i] != arr[j])
                {
                    swap(arr[i], arr[j]);
                }
                j++;
            }
        }
    }
    void moving2()
    {
        // 2nd approach
        int start = 0;
        int end = n - 1;
        while (start < end)
        {
            if (arr[start] < 0)
            {
                start++;
            }
            else if (arr[end] > 0)
            {
                end--;
            }
            else
            {
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
        }
    }

public:
    void getdata()
    {
        cout << "Enter number of element : ";
        cin >> n;
        cout << "Enter element : " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    void print()
    {
        moving();
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
    void print2()
    {
        moving2();
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << "  ";
        }
    }
};
int main()
{
    moved ans;
    ans.getdata();
    ans.print();
    moved ans2;
    ans2.getdata();
    ans2.print2();
}