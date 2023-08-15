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
    ListNode* reverse(ListNode* head) {
        
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        
        if(!head) return NULL;
        if(!head->next) {
            int val = 2 * head->val;
            if(val > 9) {
                head->next = new ListNode(val % 10);
                head->val = val / 10;
            }
            else head->val = val;
            return head;
        }
        
        head = reverse(head);
        
        ListNode* temp = head;
        int carry = 0;
        
        while(temp || carry) {
            
            int val = 2*temp->val + carry;
            if(val > 9) {
                int x = val;
                val = x % 10;
                carry = floor(x / 10.0);
            }
            else {
                carry = 0;
            }
            
            if(!temp->next && carry > 0) {
                temp->val = val;
                temp->next = new ListNode(carry);
                break;
            }
            else temp->val = val;
            
            temp = temp->next;
        }
        
        head = reverse(head);
        return head;
    }
};