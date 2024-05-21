#include <iostream>
using namespace std;
int bit(int n)
{
    int count = 0;
    int temp = n;
    for (int i = 0; i < temp; i++)
    {
        if ((n & 1) == 1)
        {
            count++;
            n = n >> 1;
        }
        else
        {
            n = n >> 1;
            continue;
        }
    }
    return count;
}
int setbit(int a, int b)
{
    int answer;
    answer = bit(a) + bit(b);
    return answer;
}
int main()
{
    int a, b;
    cout << "Enter the value of a & b : ";
    cin >> a >> b;
    int ans = setbit(a, b);
    cout << "TOTAL NUMBER OF SET BITS IN A & B IS : " << ans << endl;
}