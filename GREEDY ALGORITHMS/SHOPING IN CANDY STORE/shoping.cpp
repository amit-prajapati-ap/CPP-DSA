#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void shopingCandy(int N, int K, vector<int> &candies,vector<int> &ans)
{
    sort(candies, candies + N);
    int mini = 0;
    int buy = 0;
    int freeC = N - 1;
    while (buy <= freeC)
    {
        mini += candies[buy];
        freeC -= K;
        buy++;
    }
    int maxi = 0;
    freeC = 0;
    buy = N - 1;
    while (freeC <= buy)
    {
        maxi += candies[buy];
        freeC += K;
        buy--;
    }
    ans.push_back(mini);
    ans.push_back(maxi);
}
int main()
{
    int n, k, data;
    vector<int> price;
    cout << "Enter Number of Different Candies : ";
    cin >> n;
    cout << "Enter The Number Of Different Candies You Provide For Free : ";
    cin >> k;
    cout << "Enter The Price Of Each Type Of Candy : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        price.push_back(data);
    }
    vector<int> ans; 
    shopingCandy(n,k,price,ans);
    cout << "Minimum Money Spend to Get All Types Of Candies : " << ans[0] << endl;
    cout << "Maximum Money Spend to Get All Types Of Candies : " << ans[1] << endl;
}