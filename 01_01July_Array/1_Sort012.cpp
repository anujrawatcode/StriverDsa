// https://leetcode.com/problems/sort-colors/submissions/
// https://drive.google.com/drive/folders/1F42i9S7-OVz3O4__UQVLtQigcRT0VD37?usp=sharing
// Given an array nums with n objects colored red, white, or blue,
// sort them in-place so that objects of the same color are adjacent,
// with the colors in the order red, white, and blue.

// Dutch national flag algo
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int l = 0,
        m = 0,
        h = nums.size() - 1;

    while (m <= h)
    {
        switch (nums[m])
        {
        case 0:
            swap(nums[m++], nums[l++]);
            break;
        case 1:
            m++;
            break;
        case 2:
            swap(nums[m], nums[h--]);
            break;
        }
    }
}
int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sortColors(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}