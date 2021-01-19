// Maximum Subarray
// Given an integer array nums, find the contiguous subarray (containing at least one number)
// which has the largest sum and return its sum.

// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// Example 2:
// Input: nums = [1]
// Output: 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 9;
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = i; k <= j k++)
            {
                sum = sum + nums[k];
                maxi = max(sum, temp);
            }
        }
    }
}