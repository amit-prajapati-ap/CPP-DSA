#include <iostream>
using namespace std;
class src
{
    int arr[100][100], row, col;

public:
    void getdata()
    {
        cout << "Enter number of row : ";
        cin >> row;
        cout << "Enter number of colomn : ";
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
    bool search(int key)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j] == key)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};
int main()
{
    src o;
    int key;
    o.getdata();
    cout << "Enter the element that you want to search : ";
    cin >> key;
    bool bl = o.search(key);
    if (bl == 1)
    {
        cout << "Element are found.";
    }
    else
    {
        cout << "Element Does not exist.";
    }
}