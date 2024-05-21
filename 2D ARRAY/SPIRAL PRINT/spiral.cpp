#include <iostream>
#include <vector>
using namespace std;
class spiral
{
    int n, m, matrix[100][100], count = 0;

public:
    void getdata()
    {
        cout << "Enter number of rows : ";
        cin >> n;
        cout << "Enter number of columns : ";
        cin >> m;
        cout << "Enter the elements of Matrix : " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }
    void spiralprint()
    {
        vector<int> ans;
        int row = n;
        int col = m;
        int srow = 0;
        int scol = 0;
        int erow = row - 1;
        int ecol = col - 1;
        int total = row * col;
        while (count < total)
        {
            for (int i = scol; count < total && i <= ecol; i++)
            {
                ans.push_back(matrix[srow][i]);
                count++;
            }
            srow++;
            for (int i = srow; count < total && i <= erow; i++)
            {
                ans.push_back(matrix[i][ecol]);
                count++;
            }
            ecol--;
            for (int i = ecol; count < total && i >= scol; i--)
            {
                ans.push_back(matrix[erow][i]);
                count++;
            }
            erow--;
            for (int i = erow; count < total && i >= srow; i--)
            {
                ans.push_back(matrix[i][scol]);
                count++;
            }
            scol++;
        }
        cout << "Printing after Spiral : " << endl;
        for (int i = 0; i < total; i++)
        {
            cout << ans.at(i) << "  ";
        }
    }
};
int main()
{
    spiral obj;
    obj.getdata();
    obj.spiralprint();
}