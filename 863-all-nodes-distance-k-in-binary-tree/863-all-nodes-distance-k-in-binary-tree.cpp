/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> finall;
    
    void path(TreeNode* node, TreeNode* target, vector<TreeNode*> v){
        if(node == NULL) return;
        
        if(node == target){
            v.push_back(node);
            finall = v;
            return;
        }
    
        v.push_back(node);
        
        path(node->left, target,v);
        path(node->right, target,v);
    }
    
    void kLevelsDown(TreeNode* node, int k, TreeNode* blocker, vector<int> &ans){
        if(node == NULL or k<0 or blocker == node) return;
        
        if(k == 0){
            ans.push_back(node->val);
            return;
        }
        
        kLevelsDown(node->left, k-1, blocker, ans);
        kLevelsDown(node->right, k-1, blocker, ans);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> v;
        path(root, target, v);
        vector<int> ans;
        
        reverse(finall.begin(), finall.end());
        
        for(int i=0; i<finall.size(); i++){
            kLevelsDown(finall[i], k-i, i==0 ? NULL : finall[i-1], ans);
        }

        return ans;
    }
};