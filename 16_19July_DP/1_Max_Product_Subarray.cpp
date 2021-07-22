#include<bits/stdc++.h>
using namespace std;

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