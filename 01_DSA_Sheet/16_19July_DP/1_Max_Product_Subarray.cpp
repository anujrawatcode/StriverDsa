#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-product-subarray


// https://drive.google.com/drive/folders/16Dt8uxTTr-zZ06hBTJ773x58HYUkZ5AO?usp=sharing


// https://www.youtube.com/watch?v=6EuhbMprB5Y


int maxProduct(vector<int> &nums)
{

    int maxSoFar = nums[0],
        minSoFar = nums[0],
        overAllMax = nums[0],
        preMaxSoFar = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {

        preMaxSoFar = maxSoFar;
        maxSoFar = max(nums[i], max(maxSoFar * nums[i], minSoFar * nums[i]));
        minSoFar = min(nums[i], min(minSoFar * nums[i], preMaxSoFar * nums[i]));
        overAllMax = max(overAllMax, maxSoFar);
    }
    return overAllMax;
}

int maxProduct(vector<int> &nums)
{

    int n = nums.size();
    int prod = 1;
    int max_val = INT_MIN;

    // left to right
    for (int i = 0; i < n; i++)
    {
        if (prod == 0)
            prod = 1;
        prod = prod * nums[i];
        max_val = max(max_val, prod);
    }

    // right to left
    prod = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (prod == 0)
            prod = 1;
        prod = prod * nums[i];
        max_val = max(max_val, prod);
    }

    return max_val;
}