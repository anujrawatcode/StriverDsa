// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{

    vector<int> vec(2);
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = target - nums[i];
        if (mp.find(temp) != mp.end())
        {

            vec[0] = mp[temp];
            vec[1] = i;
        }
        mp[nums[i]] = i;
    }
    return vec;
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target = 14;
    twoSum(arr, target);
}