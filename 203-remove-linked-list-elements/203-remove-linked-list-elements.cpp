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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1, head);
        int flag = 1;
        
        while(temp){
            if(temp->val == val){
                dummy->next = temp->next;
                temp = temp->next;
                continue;
            }
            else if(flag){
                head = temp;
                flag = 0;
            }
            dummy = dummy->next;
            temp = temp->next;
        }
        
        if(dummy->val == -1){
            head = NULL;
        }
        
        return head;
    }
};