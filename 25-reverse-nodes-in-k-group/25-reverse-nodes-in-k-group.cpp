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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        
        // 1st check if there are k elements that can be reversed.
        int i = 0;
        while(i < k) {
            if(!temp) return head;
            
            temp = temp->next;
            i++;
        }
        
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(current && i>0) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            i--;
        }
        
        head->next = reverseKGroup(current, k);
        return prev;
    }
};