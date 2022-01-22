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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        
        int carry = 0;
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        
        while(l1 || l2 || carry) {
            
            int x = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            if(x > 9) {
                carry = x/10;
                x %= 10;
            }
            else carry = 0;
            
            temp->next = new ListNode(x);
            temp =temp->next;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            
        }
        
        return result->next;
    }
};