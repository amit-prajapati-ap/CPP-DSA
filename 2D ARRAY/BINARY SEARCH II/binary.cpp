#include <iostream>
using namespace std;
class binary
{
    int n, m, arr[100][100];

public:
    void getdata()
    {
        cout << "Enter number of rows : ";
        cin >> n;
        cout << "Enter number of coloumns : ";
        cin >> m;
        cout << "Enter the elements : " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    bool binarysrc(int target)
    {
        int row = n;
        int col = m;
        int s = 0, e = col - 1;
        while (s < row && e >= 0){
            int element = arr[s][e];
            if (element == target){
                return 1;
            }
            else if (element < target){
                s++;
            }
            else{
                e--;
            }
        }
        return 0;
    }
};
int main()
{
    binary obj;
    int key;
    obj.getdata();
    cout << "Enter the key that you search : ";
    cin >> key;
    bool bl = obj.binarysrc(key);
    if (bl == 1)
    {
        cout << "Element are present.";
    }
    else
    {
        cout << "Element does not exist.";
    }
}