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
    ListNode* reverse(ListNode* head) {
        
        ListNode* current = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        
        while(current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode* result = new ListNode(0);
        ListNode* t = result;
        int carry = 0;
        
        while(l1 || l2 || carry) {
            
            int x = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            
            if(x > 9) {
                carry = x/10;
                x %= 10;
            }
            else carry = 0;
            
            t->next = new ListNode(x);
            t = t->next;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            
        }
        
        result = reverse(result->next);
        return result;
    }
};