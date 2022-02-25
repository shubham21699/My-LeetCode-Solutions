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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next || k==0) return head;
        if(!head->next->next) {
            k %= 2;
            if(k == 0) return head;
            int temp = head->val;
            head->val = head->next->val;
            head->next->val = temp;
            return head;
        }
        
        int len = 0;
        ListNode* temp = head;
        
        while(temp) {
            len++;
            temp = temp->next;
        }
        
        k = k%len;
        if(k == 0 || k == len) return head;
        
        temp = head;
        k = len-k-1;
        while(k--) {
            temp = temp->next;
        }
        
        ListNode* newHead = temp->next;
        temp->next = NULL;
        ListNode* t = newHead;
        
        while(t->next) {
            t = t->next;
        }
        
        t->next = head;
        return newHead;
    }
};