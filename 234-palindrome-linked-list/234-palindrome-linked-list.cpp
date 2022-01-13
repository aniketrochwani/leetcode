/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* left;
    bool helper(ListNode* right){
        if(right == NULL){
            return true;
        }    
        
        bool ans= helper(right->next);
        
        if(left->val == right->val and ans){
            ans = true; 
        }else{
            ans = false;
        }
        
        left = left->next;
        return ans;
    }
    
    bool isPalindrome(ListNode* head) {
        left = head;
        return helper(head);
    }
};