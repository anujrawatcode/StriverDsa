#include <bits/stdc++.h>
using namespace;

vector<vector<int>> threeSum(vector<int> &nums)
{

    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int sum = 0 - nums[i];
            int l = i + 1;
            int h = nums.size() - 1;
            while (l < h)
            {
                if (sum == nums[l] + nums[h])
                {
                    vector<int> temp(3);
                    temp[0] = nums[i];
                    temp[1] = nums[l];
                    temp[2] = nums[h];
                    ans.push_back(temp);

                    while (l < h && nums[l] == nums[l + 1])
                        l++;
                    while (l < h && nums[h - 1] == nums[h])
                        h--;

                    l++;
                    h--;
                }
                else if (sum > nums[l] + nums[h])
                    l++;
                else if (sum < nums[l] + nums[h])
                    h--;
            }
        }
    }
    return ans;
}
