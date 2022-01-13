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
    void append(ListNode** head_ptr, int data){
        ListNode* node = new ListNode(data);
        
        if(*head_ptr == NULL){
            *head_ptr = node;
            return;
        }
        
        ListNode* temp = *head_ptr;
        while(temp->next != NULL){
            temp = temp->next;
        }
        
        temp->next = node;
        return;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1, *q = l2;
        int sum = 0, carry=0;
        ListNode* final;
        while(p != NULL and q != NULL){
            sum = p->val + q->val + carry;
            if(sum>=10){
                carry = sum/10;
                sum = sum%10; 
            }else{
                carry =0;
            }
            append(&final,sum);
            p = p->next; q=q->next;
        }
        
        while(p != NULL){
            sum = p->val + carry;
            if(sum>=10){
                carry = sum/10;
                sum = sum%10; 
            }else{
                carry =0;
            }
            append(&final,sum);
            p = p->next;
        }
        
        while(q != NULL){
            sum = q->val + carry;
            if(sum>=10){
                carry = sum/10;
                sum = sum%10; 
            }else{
                carry =0;
            }
            append(&final,sum);
            q=q->next;
        }
        
        if(carry){
            append(&final,carry);
        }
        return final;
    }
};