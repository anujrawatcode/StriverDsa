

class Solution
{
public:
    int treeHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        if (!isBalanced(root->left))
            return false;
        if (!isBalanced(root->right))
            return false;
        int lH = 1 + treeHeight(root->left);
        int rH = 1 + treeHeight(root->right);
        if (abs(lH - rH) <= 1)
            return true;
        return false;
    }

public:
    int calHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(calHeight(root->left), calHeight(root->right));
    }


}
;