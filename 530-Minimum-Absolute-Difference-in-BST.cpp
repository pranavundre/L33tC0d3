class Solution {
public:
    int res = INT_MAX, pre = -1;
    int getMinimumDifference(TreeNode* root) {
        if (root->left != NULL) getMinimumDifference(root->left);
        if (pre >= 0) res = min(res, root->val - pre);
        pre = root->val;
        if (root->right != NULL) getMinimumDifference(root->right);
        return res;
    }
};
