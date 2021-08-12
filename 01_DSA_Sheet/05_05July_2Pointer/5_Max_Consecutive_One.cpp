#include <bits/stdc++.h>
using namespace;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int k = 0;
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
            k++;
        else
            k = 0;
        maxi = max(maxi, k);
    }
    return maxi;
}