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
    void addIntoTree(TreeNode* node, int val){
        if(node == NULL) return;
        
        if(node->val < val){
            if(node->right == NULL){
                node->right = new TreeNode(val);
            }else{
                addIntoTree(node->right, val);
            }
        }else{
            if(node->left == NULL){
                node->left = new TreeNode(val);
            }else{
                addIntoTree(node->left, val);
            }
        }
        
        return;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        
        for(int i=1; i<preorder.size(); i++){
            addIntoTree(root, preorder[i]);
        }
        
        return root;
    }
};