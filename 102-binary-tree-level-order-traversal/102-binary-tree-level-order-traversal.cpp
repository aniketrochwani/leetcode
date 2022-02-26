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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> ans;
        
        while(qu.size()){
            int k = qu.size();
            vector<int> temp;
            for(int i=0; i<k; i++){
                TreeNode* f = qu.front();
                qu.pop();
                temp.push_back(f->val);
                if(f->left) qu.push(f->left);
                if(f->right) qu.push(f->right);
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};