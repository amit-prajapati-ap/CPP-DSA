#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
class Item
{
public:
    int weight, values;
};
static bool cmp(pair<double, Item> a, pair<double, Item> b)
{
    return a.first > b.first;
}
double Findmax(int n, Item *arr, int c)
{
    vector<pair<double, Item>> v;
    for (int i = 0; i < n; i++)
    {
        double per_unit_Value = (1.0 * arr[i].values) / arr[i].weight;
        v.push_back({per_unit_Value, arr[i]});
    }
    sort(v.begin(), v.end(), cmp);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second.weight > c)
        {
            ans += c * v[i].first;
            c = 0;
        }
        else
        {
            ans += v[i].second.values;
            c = c - v[i].second.weight;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the Number of Items : ";
    cin >> n;
    Item arr[n];
    cout << "Enter The Values of Items : ";
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        arr[i].values;
    }
    cout << "Enter The Weight of Items : ";
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        arr[i].weight;
    }
    cout << "Enter the capacity of Knapsack : ";
    int capacity;
    cin >> capacity;
    cout << "Maximum Value that is Store in Knapsack : " << Findmax(n, arr, capacity) << endl;
}