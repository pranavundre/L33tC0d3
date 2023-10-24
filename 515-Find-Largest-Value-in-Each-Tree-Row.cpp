class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int s = q.size(), maxNode = INT_MIN;
            while(s--){
                TreeNode* temp = q.front();
                q.pop();
                maxNode = max(maxNode, temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(maxNode);
        }
        return res;
    }
};
