// https://leetcode.com/problems/combination-sum-ii/submissions/
// https://drive.google.com/drive/folders/1CN2KM4FzZt1cyz7YJ61YXnaiRwoBd3YQ?usp=sharing
class Solution
{
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        if (ind == arr.size())
            return;

        for (int i = ind; i < arr.size(); i++)
        {
            if (i != ind && arr[i] == arr[i - 1])
                continue;

            if (arr[i] > target)
                break;

            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};