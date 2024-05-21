#include <iostream>
using namespace std;
class Solution
{
    string haystack, needle;

public:
    void getdata()
    {
        cout << "ENTER THE STRING & SUBSTRING : " << endl;
        cin >> haystack >> needle;
    }
    int strStr()
    {
        int n = haystack.length();
        int x = needle.length();
        for (int i = 0; i < n; i++)
        {
            if (needle == haystack.substr(i, x))
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    s.getdata();
    int ans = s.strStr();
    cout << ans;
}