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
    int getDecimalValue(ListNode* head) {
        
        if(!head) return 0;
        if(!head->next) head->val;
        
        head = reverse(head);
        
        int ans = 0;
        int i = 0;
        while(head) {
            ans += (head->val * pow(2, i));
            i++;
            head = head->next;
        }
        
        return ans;
    }
};