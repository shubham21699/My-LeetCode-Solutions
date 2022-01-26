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
    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next) return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        do {
            
            fast = fast->next;
            if(!fast) break; 
            fast = fast->next;
            if(!fast) break;
            
            slow = slow->next;
            if(!slow) break;
            
        } while(fast != slow);
        
        if(!fast || !slow) return NULL;
        
        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
    }
};