#include <iostream>
#include <vector>
using namespace std;
void wave(int arr[][3], int row, int col)
{
    int ans[3][3];
    for (int i = 0; i < col; i++)
    {
        if (i & 1 == 1)
        {
            for (int j = row - 1; j >= row; j--)
            {
                ans[i][j] = arr[i][j];
            }
        }
        else
        {
            for (int j = 0; j < row; j++)
            {
                ans[i][j] = arr[i][j];
            }
        }
    }
    cout << "Wave printing : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    wave(arr, 3, 3);
}