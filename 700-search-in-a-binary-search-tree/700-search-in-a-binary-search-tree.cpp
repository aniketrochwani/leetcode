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
    TreeNode* ans;
    
    void find(TreeNode* node, int val){
        if(node == NULL) return;
        
        if(node->val > val) find(node->left, val);
        else if(node->val < val) find(node->right, val);
        else ans = node;
        return;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        find(root, val);
        return ans;
    }
};