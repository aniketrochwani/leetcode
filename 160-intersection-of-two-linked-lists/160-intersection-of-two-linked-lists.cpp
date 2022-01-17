/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int findSize(ListNode* node){
        int count = 0;
        while(node != NULL){
            node = node->next;
            count++;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int s1=findSize(headA);//3
        int s2=findSize(headB);//2
        ListNode* n1=headA;
        ListNode* n2=headB;
        int gap;
        
        if(s1>s2){
            gap = s1-s2;
            for(int i=0; i<gap; i++){
                n1=n1->next;
            }
        }else if(s1<s2){
            gap = s2-s1;
            for(int i=0; i<gap; i++){
                n2=n2->next;
            }
        }
        
        while(n1 != n2){
            n1 = n1->next;
            n2 = n2->next;
        }
        
        return n1;
    }
};