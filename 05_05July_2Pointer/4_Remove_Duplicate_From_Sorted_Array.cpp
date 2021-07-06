#include <bits/stdc++.h>
using namespace;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0 || n == 1)
        return n;

    int i = 0;
    int j = 0;
    int k = 1;

    while (j < n)
    {
        if (nums[i] == nums[j])
        {
            j++;
        }
        else
        {
            k++;
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return k;
}