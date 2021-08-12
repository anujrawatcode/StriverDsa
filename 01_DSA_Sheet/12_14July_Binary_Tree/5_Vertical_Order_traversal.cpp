#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(TreeNode *root, map<int, vector<int>> &m, int lvl)
    {
        if (!root)
            return;

        int hd = 0;

        queue<pair<TreeNode *, int>> que;
        que.push(make_pair(root, hd));

        while (!que.empty())
        {
            // pop from queue front
            pair<TreeNode *, int> temp = que.front();
            que.pop();
            hd = temp.second;
            TreeNode *node = temp.first;

            // insert this node's data in vector of hash
            m[hd].push_back(node->val);

            if (node->left != NULL)
                que.push(make_pair(node->left, hd - 1));
            if (node->right != NULL)
                que.push(make_pair(node->right, hd + 1));
        }
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        int lvl = 0;
        solve(root, mp, lvl);

        int n = mp.size();
        vector<vector<int>> ans1(n);

        int i = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            for (int j = 0; j < it->second.size(); j++)
            {
                ans1[i].push_back(it->second[j]);
            }
            i++;
        }

        return ans1;
    }
};