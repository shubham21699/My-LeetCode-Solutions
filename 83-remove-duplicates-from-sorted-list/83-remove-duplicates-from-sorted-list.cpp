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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) return NULL;
        if(!head->next) return head;
        
        ListNode* temp = head;
        
        while(temp) {
            if(temp->next && temp->val == temp->next->val) {
                if(temp->next->next) temp->next = temp->next->next;
                else temp->next = NULL;
            }
            else temp = temp->next;
        }
        
        return head;
    }
};