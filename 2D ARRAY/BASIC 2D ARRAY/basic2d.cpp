#include <iostream>
using namespace std;
int main()
{
    int arr[100][100], row, col;
    cout << "Enter the number of rows : ";
    cin >> row;
    cout << "Enter the number of colomn : ";
    cin >> col;
    cout << "Enter elements : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Row wise Printing 2D array : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "Column Wise Printing 2D array : " << endl;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << arr[j][i] << "  ";
        }
        cout << endl;
    }
}