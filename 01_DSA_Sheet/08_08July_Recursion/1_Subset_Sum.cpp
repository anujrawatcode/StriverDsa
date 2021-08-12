// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

// https://drive.google.com/drive/folders/1CN2KM4FzZt1cyz7YJ61YXnaiRwoBd3YQ?usp=sharing

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> arr, int n, vector<int> &ans, int sum)
    {
        if (n == 0)
        {
            ans.push_back(sum);
            return;
        }
        else
        {
            solve(arr, n - 1, ans, sum);
            sum += arr[n - 1];
            solve(arr, n - 1, ans, sum);
        }
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(arr, N, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};