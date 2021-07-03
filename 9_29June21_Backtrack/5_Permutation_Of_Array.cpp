#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int lvl, int n)
    {
        if (n == 0 || lvl == n)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = lvl; i < n; i++)
        {
            swap(nums[lvl], nums[i]);
            solve(nums, ans, lvl + 1, n);
            swap(nums[lvl], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        solve(nums, ans, 0, n);
        return ans;
    }
};