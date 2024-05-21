// IT IS A PROGRAMME THAT PROVIDE YOU THE ALLOCATION OF BOOKS TO THE MAXIMUM NUMBER OF STUDENTS THAT READ THE MINIMUM PAGES.
#include <iostream>
using namespace std;
bool possiblesol(int arr[], int n, int k, int mid)
{
    int studentcount = 1;
    int pagesum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesum + arr[i] <= mid)
        {
            pagesum += arr[i];
        }
        else
        {
            studentcount++;
            if (studentcount > k || arr[i] > mid)
            {
                return false;
            }
        }
    }
    return true;
}
int sumofarr(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
int allocatebook(int arr[], int n, int k)
{
    int start = 0, ans;
    int end = sumofarr(arr, n);
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (possiblesol(arr, n, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    int size;
    cout << "Enter the number of books to allocate : ";
    cin >> size;
    int books[100];
    cout << "How many pages on each book : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> books[i];
    }
    int students;
    cout << "Enter how many students to allocate books : ";
    cin >> students;
    int ans = allocatebook(books, size, students);
    cout << "THE MINIMUM PAGES TO READ " << ans << endl;
}