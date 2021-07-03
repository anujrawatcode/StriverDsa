// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int num = 0;
        for (int i = 0; i < n; i++)
            num = num ^ arr[i];
        for (int i = 1; i <= n; i++)
            num = num ^ i;

        int set_bit = num & ~(num - 1); //right most set bit of num

        int x = 0;
        int y = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & set_bit)
                x = x ^ arr[i];
            else
                y = y ^ arr[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (i & set_bit)
                x = x ^ i;
            else
                y = y ^ i;
        }

        int arr1[2];
        int *temp = &arr1[0];

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                arr1[0] = x;
                arr1[1] = y;
                return temp;
            }
        }

        arr1[1] = x;
        arr1[0] = y;

        return temp;
    }
};