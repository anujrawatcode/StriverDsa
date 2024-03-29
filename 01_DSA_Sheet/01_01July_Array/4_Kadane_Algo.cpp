// https : //leetcode.com/problems/maximum-subarray/
// https://drive.google.com/drive/folders/1F42i9S7-OVz3O4__UQVLtQigcRT0VD37?usp=sharing

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

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int ans = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    return ans;
}

int main()
{
}