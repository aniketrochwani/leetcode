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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    
    void swap(TreeNode* n1, TreeNode* n2){
        int c = n2->val;
        n2->val = n1->val;
        n1->val = c;
        return;
    }
    
    void inorder(TreeNode* node){
        if(node == NULL) return;
        
        inorder(node->left);
    
        if(prev != NULL and (node->val < prev->val)){
            if(first == NULL){
                first = prev;
                middle = node;
            }
            else last = node;
        }
        
        prev = node;
        inorder(node->right);
    }
    
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        
        if(first and last) swap(first, last);
        else if(first and middle) swap(first, middle);
    }
};