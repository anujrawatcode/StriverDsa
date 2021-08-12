class Solution
{
public:
    bool isMirror(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL || root2 == NULL)
        {
            if (root1 == NULL && root2 == NULL)
                return true;
            return false;
        }
        if (root1->val != root2->val)
            return false;
        return isMirror(root1->left, root2->right) &&
               isMirror(root1->right, root2->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (isMirror(root, root))
            return true;
        return false;
    }
};