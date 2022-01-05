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
    
    int solve(TreeNode* node){
        if(node == NULL) return 0;
        int lTree = solve(node->left);
        int rTree = solve(node->right);
        
        if(lTree == 0) return rTree +1;
        else if(rTree == 0) return lTree+1;
        return min(lTree, rTree) +1;
    }
    
    int minDepth(TreeNode* root) {
        int count = solve(root);
        return count;
    }
};