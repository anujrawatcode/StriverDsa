class Solution
{
public:
    int calHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(calHeight(root->left), calHeight(root->right));
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lHeight = calHeight(root->left);
        int rHeight = calHeight(root->right);
        int currDiameter = lHeight + rHeight;

        int lDiameter = diameterOfBinaryTree(root->left);
        int rDiameter = diameterOfBinaryTree(root->right);

        return max(currDiameter, max(lDiameter, rDiameter));
    }
};