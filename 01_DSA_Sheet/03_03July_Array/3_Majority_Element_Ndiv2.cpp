#include <bits/stdc++.h>
using namespace std;


// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.

int majorityElement(vector<int> &nums)
{

    int ele = nums[0];
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt == 0)
            ele = nums[i];
        if (nums[i] == ele)
            cnt++;
        else
            cnt--;
    }
    return ele;
}