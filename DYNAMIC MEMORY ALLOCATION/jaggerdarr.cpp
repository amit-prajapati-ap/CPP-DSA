#include <iostream>
using namespace std;
int main()
{
    int row, num = 1;
    cout << "Enter the number of rows : ";
    cin >> row;
    int **arr = new int *[row];
    int sizes[3] = {5, 2, 4};
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[sizes[i]];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            arr[i][j] = num++;
        }
    }
    cout << "Printing jaggerd array : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}