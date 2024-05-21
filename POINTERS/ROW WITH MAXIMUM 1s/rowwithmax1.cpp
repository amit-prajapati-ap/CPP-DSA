#include <iostream>
using namespace std;
class Solution
{
    int n, m;
    int arr[100][100];

public:
    void getdata()
    {
        cout << "Enter the number of Rows : ";
        cin >> n;
        cout << "Enter the number of Colomns : ";
        cin >> m;
        cout << "Enter the elements of matrix :" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    int rowWithMax1s()
    {
        int a = -1;
        int ans[n];
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    count++;
                }
            }
            ans[i] = count;
        }
        for (int i = 0; i < n; i++)
        {
            if (maxi < ans[i])
            {
                maxi = ans[i];
                a = i;
            }
        }
        if (a < 0)
            return -1;
        else
            return a;
    }
};
int main()
{
    Solution s;
    s.getdata();
    int ans = s.rowWithMax1s();
    cout << "The maximum number of 1s row is " << ans << endl;
}