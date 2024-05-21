#include <iostream>
using namespace std;
int main()
{
    int arr1[] = {1, 2, 2, 3, 3, 4, 5, 5}, arr2[] = {1, 1, 2, 3, 4, 4};
    /* // 1st approach
    for (int i = 0; i < 8; i++)
     {
         int element = arr1[i];
         for (int j = 0; j < 6; j++)
         {
             if (element < arr2[j]) // only in sorted array
             {
                 break;
             }

             else if (arr2[j] == element)
             {
                 cout << element << ' ';
                 arr2[j] = -2;
                 break;
             }
         }
     }
    */
    // 2nd appproach
    int i = 0, j = 0;
    while (i < 8 && j < 6)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << ' ';
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}