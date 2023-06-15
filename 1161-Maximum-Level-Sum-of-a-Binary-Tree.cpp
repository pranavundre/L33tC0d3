/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN, res = 0, lvl = 0;

        while(!q.empty()){
            int size = q.size(), sum = 0;
            lvl++;
            while(size--){
                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(sum > maxSum){
                maxSum = sum;
                res = lvl;
            }
        }

        return res;
    }
};
