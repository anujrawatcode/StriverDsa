// Merge two sorted arrays with O(1) extra space

// We are given two sorted array. We need to merge these two arrays
// such that the initial numbers (after complete sorting) are in the first array
// and the remaining numbers are in the second array. Extra space allowed in O(1).

// Example:

// Input: ar1[] = {10};
//        ar2[] = {2, 3};
// Output: ar1[] = {2}
//         ar2[] = {3, 10}

// Input: ar1[] = {1, 5, 9, 10, 15, 20};
//        ar2[] = {2, 3, 8, 13};
// Output: ar1[] = {1, 2, 3, 5, 8, 9}
//         ar2[] = {10, 13, 15, 20}

// INSERTION SORT ALGO

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n1 = 6;
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int n2 = 4;
    int arr2[] = {10, 13, 15, 20};

    for (int i = 0; i < n1; i++)
    {
        if (arr1[i] > arr2[0])
        {
            swap(arr1[i], arr2[0]);
            sort(arr2, arr2 + n2);
        }
    }
    
    for (int i = 0; i < n1; i++)
        cout << arr1[i];
    for (int i = 0; i < n2; i++)
        cout << arr2[i];
}