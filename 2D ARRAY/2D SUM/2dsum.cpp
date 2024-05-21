#include <iostream>
using namespace std;
class sum
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
    void twoDsum()
    {
        cout << "Row Wise sum : " << endl;
        for (int i = 0; i < n; i++)
        {
            int add = 0;
            for (int j = 0; j < m; j++)
            {
                add = add + arr[i][j];
            }
            cout << add << "  ";
        }
        cout << endl;
        cout << "Coloumn Wise sum : " << endl;
        for (int i = 0; i < m; i++)
        {
            int add = 0;
            for (int j = 0; j < n; j++)
            {
                add = add + arr[j][i];
            }
            cout << add << "  ";
        }
    }
};
int main()
{
    sum o;
    o.getdata();
    o.twoDsum();
}