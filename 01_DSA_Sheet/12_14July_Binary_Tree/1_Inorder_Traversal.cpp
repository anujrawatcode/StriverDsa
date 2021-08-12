#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
        }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};