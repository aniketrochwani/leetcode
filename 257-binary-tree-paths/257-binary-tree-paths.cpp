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
    vector<string> ans;
    
    void find(TreeNode* node, string s){
        if(node == NULL) return;
        
        if(node->left == NULL and node->right == NULL){
            s+=to_string(node->val);
            ans.push_back(s);
            return;
        }
        
        find(node->left, s+to_string(node->val)+"->");
        find(node->right, s+to_string(node->val)+"->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s= "";
        find(root, s);
        return ans;
    }
};