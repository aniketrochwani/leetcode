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
    stack<TreeNode*> stl;
    stack<TreeNode*> str; 
    
    int next(){
        TreeNode* top = stl.top();
        stl.pop();
        if(top->right){
            TreeNode* t = top->right;
            while(t != NULL){
                stl.push(t);
                t = t->left;
            }
        }
        return top->val;    
    }
    
    int prev(){
        TreeNode* top = str.top();
        str.pop();
        if(top->left){
            TreeNode* t = top->left;
            while(t != NULL){
                str.push(t);
                t = t->right;
            }
        }
        return top->val;
    }
    
    bool findTarget(TreeNode* root, int k) {
        stl.push(root);
        str.push(root);
        
        TreeNode* t = root;
        while(t != NULL){
            stl.push(t);
            t = t->left;
        }
        
        t = root;
        while(t != NULL){
            str.push(t);
            t = t->right;
        }
        
        while(stl.top()->val < str.top()->val){
            if(stl.top()->val + str.top()->val < k){
                next();
            }else if (stl.top()->val + str.top()->val > k){
                prev();
            }else {
                return true;
            }
        }
        
        return false;
    }
};