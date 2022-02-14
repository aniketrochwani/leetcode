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
    int find(TreeNode* node){
        if(node == NULL) return 0;
        int lh = find(node->left);
        int rh = find(node->right);
        return max(lh, rh)+1;    
    }
    
    int maxDepth(TreeNode* root) {
        return find(root);
    }
};