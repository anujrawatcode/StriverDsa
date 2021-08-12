

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (p->val == root->val || q->val == root->val)
        return root;

    TreeNode *lnode = lowestCommonAncestor(root->left, p, q);
    TreeNode *rnode = lowestCommonAncestor(root->right, p, q);

    if (lnode != NULL && rnode != NULL)
        return root;
    if (lnode != NULL)
        return lnode;
    else
        return rnode;
}