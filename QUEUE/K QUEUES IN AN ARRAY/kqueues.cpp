#include <iostream>
using namespace std;

class queue
{
    int n, freespot;
    int *arr, *front, *rear, *next;

public:
    queue(int size, int k)
    {
        n = size;
        freespot = 0;
        arr = new int[n];
        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
    }
    int push(int x, int qn)
    {
        if (freespot == -1)
        {
            return -1;
        }
        int index = freespot;
        freespot = next[index];
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            next[rear[qn - 1]] = index;
        }
        next[index] = -1;
        rear[qn - 1] = index;
        arr[index] = x;
        return arr[front[qn - 1]];
    }
    int pop(int qn)
    {
        if (front[qn - 1] == -1)
        {
            return -1;
        }
        int ans = arr[front[qn - 1]];
        int index = front[qn - 1];
        front[qn - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return ans;
    }
};

int main()
{
    int k = 3;
    int n = 9;
    queue q(n,k);
    int ans;
    ans = q.push(10, 1);
    cout << "Push : " << ans << endl;
    ans = q.push(20, 1);
    cout << "Push : " << ans << endl;
    ans = q.push(15, 2);
    cout << "Push : " << ans << endl;
    ans = q.push(98, 2);
    cout << "Push : " << ans << endl;
    ans = q.push(30, 1);
    cout << "Push : " << ans << endl;
    ans = q.pop(1);
    cout << "Pop : " << ans << endl;
    ans = q.push(40, 1);
    cout << "Push : " << ans << endl;
    ans = q.push(52, 3);
    cout << "Push : " << ans << endl;
    ans = q.pop(2);
    cout << "Pop : " << ans << endl;
    ans = q.pop(3);
    cout << "Pop : " << ans << endl;
    ans = q.push(95, 2);
    cout << "Push : " << ans << endl;
}