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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p=l1, *q=l2;
        ListNode* final = NULL;
        
        while(p!=NULL and q!=NULL){
            if(p->val < q->val){
                append(&final,p->val);
                p=p->next;
            }else{
                append(&final,q->val);
                q=q->next;
            }
        }
        while(p!=NULL){
            append(&final,p->val);
            p=p->next;
        }
        while(q!=NULL){
            append(&final,q->val);
            q=q->next;
        }
        
        return final;
    }
};