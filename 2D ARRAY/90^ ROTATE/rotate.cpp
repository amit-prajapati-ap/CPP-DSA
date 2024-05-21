#include <iostream>
using namespace std;
class rotate
{
    int arr[100][100], row, col;

public:
    void getdata()
    {
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
    }
    void print()
    {
        cout << "Row wise Printing 2D array after rotating : " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << "  ";
            }
            cout << endl;
        }
    }
    void rotating()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = i + 1; j < col; j++)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
        for (int i = 0; i < row; i++)
        {
            int a = 0, b = col - 1;
            while (a < b)
            {
                swap(arr[i][a], arr[i][b]);
                a++;
                b--;
            }
        }
    }
};
int main()
{
    rotate o;
    o.getdata();
    o.rotating();
    o.print();
}
