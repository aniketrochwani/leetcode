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
        ListNode* swapPairs(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        
        ListNode* A = head;
        ListNode* B = head->next;
        ListNode* C = head->next->next;
            
        head = head->next;
        
        while(C and C->next){
            B->next = A;
            A->next = C->next;
            A = C;
            B = C->next;
            C = C->next->next;
        }
        
        B->next = A;
        A->next = C;
        
        return head;
    }
};