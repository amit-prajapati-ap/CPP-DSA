#include <iostream>
using namespace std;
class Petrolpump
{
public:
    int petrol, distance;
};
void print(Petrolpump *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Petrol = " << p[i].petrol << " , Distance = " << p[i].distance << endl;
    }
    cout << endl;
}
int findstart(Petrolpump *p, int n)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0)
    {
        return start;
    }
    return -1;
}
int main()
{

    int n;
    cout << "Enter The Number of Elements : ";
    cin >> n;
    Petrolpump *p;
    p = new Petrolpump[n];
    cout << "Enter The Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].petrol >> p[i].distance;
    }
    print(p, n);
    int start = findstart(p, n);
    if (start == -1)
    {
        cout << "Circular Tour Not Possible" << endl;
    }
    else
    {
        cout << "You Can Complete Circular True From The Starting Point : " << start << endl;
    }
}