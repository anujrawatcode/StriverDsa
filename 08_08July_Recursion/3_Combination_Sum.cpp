// https://leetcode.com/problems/combination-sum/submissions/
//https://drive.google.com/drive/folders/1CN2KM4FzZt1cyz7YJ61YXnaiRwoBd3YQ?usp=sharing
class Solution {
public:
    void solve(int i, vector<int>& nums, int tar, vector<vector<int>> &ans, vector<int> temp)
    {
        if(tar==0) {
             ans.push_back(temp);
            return;
        }
               
        if(i==nums.size()) {
            
            return;
        }
        
        if(tar>=nums[i]) {
            temp.push_back(nums[i]);
            solve(i, nums, tar-nums[i], ans, temp);
            temp.pop_back();
             solve(i+1, nums, tar, ans, temp);
        } else {
             solve(i+1, nums, tar, ans, temp);
        }
       
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums, tar, ans, temp);
        return ans;
    }
};