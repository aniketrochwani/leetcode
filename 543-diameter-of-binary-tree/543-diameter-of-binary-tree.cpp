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
    int find(TreeNode* node, int &d){
        if(node == NULL) return 0;
        int ld = find(node->left, d);
        int rd = find(node->right, d);
        d = max(d, ld+rd);
        return max(ld,rd)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        find(root, d);
        return d;
    }
};