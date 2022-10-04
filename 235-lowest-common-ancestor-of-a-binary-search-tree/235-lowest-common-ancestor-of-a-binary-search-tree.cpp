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
    bool findRootToNodePath(TreeNode* node, TreeNode* target, vector<TreeNode*> &path){
        if(node == NULL)  return false;
        
        if(node == target){
            path.push_back(node);
            return true;
        }
        
        path.push_back(node);
        bool checkLeft = findRootToNodePath(node->left, target, path);
        bool checkRight = findRootToNodePath(node->right, target, path);
        
        if(checkLeft or checkRight) return true;
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        
        findRootToNodePath(root, p, path1);
        findRootToNodePath(root, q, path2);
        
        int i=0;
        TreeNode* ans;
        while(i<path1.size() and i<path2.size()){
            if(path1[i] == path2[i]) ans = path1[i];
            else break;
            i++;
        }
        
        return ans;
    }
};