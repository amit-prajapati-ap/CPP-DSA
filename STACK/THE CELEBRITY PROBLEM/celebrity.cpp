#include <iostream>
#include <stack>
using namespace std;
void print(int **arr, int n)
{
    cout << "Printing the Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}
bool knows(int **arr, int A, int B, int n)
{
    if (arr[A][B] == 1)
    {
        return true;
    }
    else
    {
        false;
    }
}
int celebrity(int **M, int n)
{
    stack<int> s;
    // step1: push all element in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step2: get 2 elements and copare them

    while (s.size() > 1)
    {

        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M, a, b, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans = s.top();
    // step3: single element in stack is potential celeb
    // so verify it

    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
            zeroCount++;
    }

    // all zeroes
    if (zeroCount != n)
        return -1;

    // column check
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 1)
            oneCount++;
    }

    if (oneCount != n - 1)
        return -1;

    return ans;
}
int main()
{

    int n;
    int **arr;
    cout << "Enter Number Of Row : ";
    cin >> n;
    arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    cout << "Enter the Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    print(arr, n);
    cout << "Celebrity is : " << celebrity(arr, n) << endl;
}