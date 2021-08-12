#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> levelOrder(TreeNode *root)
{

    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> x;
        for (int i = 0; i < n; i++)
        {
            TreeNode *t = q.front();
            q.pop();
            x.push_back(t->val);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        ans.push_back(x);
    }
    return ans;
}