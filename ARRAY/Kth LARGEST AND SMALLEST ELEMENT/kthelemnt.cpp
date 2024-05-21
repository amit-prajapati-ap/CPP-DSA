#include <iostream>
using namespace std;
class kthelement
{
    int arr[100], n, k, maxi, mini;

    void sorting()
    {
        bool bl = false;
        for (int i = 0; i < n - i; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    bl = true;
                }
            }
            if (bl == false)
            {
                break;
            }
        }
    }
    void finding()
    {
        maxi = arr[n - k];
        mini = arr[k - 1];
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
        cout << "Enter the value of k to find max & min element : ";
        cin >> k;
        sorting();
    }
    void print()
    {
        finding();
        cout << k << "th minimum element is " << mini << endl;
        cout << k << "th maximum element is " << maxi << endl;
    }
};
int main()
{
    kthelement ans;
    ans.getdata();
    ans.print();
}