#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
int Chocolate(int m, int n, vector<int> packets)
{
    int mini = INT_MAX;
    int j = m - 1;
    sort(packets.begin(), packets.end());
    while (j < n)
    {
        int diff = packets[j] - packets[j - m + 1];
        mini = min(mini, diff);
        j++;
    }
    return mini;
}
int main()
{

    int m, data, len;
    vector<int> packets;
    cout << "Enter Number Of Students : ";
    cin >> m;
    cout << "Enter Number Of Packet : ";
    cin >> len;
    cout << "Enter the Chocalates In Packets : " << endl;
    for (int i = 0; i < len; i++)
    {
        cin >> data;
        packets.push_back(data);
    }
    cout << "Difference Of Max and Min of every Window size m is minimum is : " << Chocolate(m, len, packets);
}