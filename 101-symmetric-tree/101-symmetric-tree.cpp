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
    bool find(TreeNode* node1, TreeNode* node2){
        if(node1 == NULL and node2 == NULL) return true;
        
        if((node1 == NULL and node2 != NULL) or (node1 != NULL and node2 == NULL)) return false;
        
        if(node1->val != node2->val) return false;
        
        return find(node1->left, node2->right) and find(node1->right, node2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return find(root->left, root->right);
    }
};