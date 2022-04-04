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
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(!head || !head->next) return head;
        int len = 0;
        ListNode* temp = head;
        
        while(temp) {
            temp = temp->next;
            len++;
        }
        
        int i=1;
        int j = 1;
        temp = head;
        ListNode* t2 = head;
        while((i < k && temp) || (j <= len-k && t2)) {
            if(i < k) {
                temp = temp->next;
                i++;
            }
            if(j <= len-k) {
                t2 = t2->next;
                j++;
            }
        }
        
        int val = temp->val;
        temp->val = t2->val;
        t2->val = val;
        
        return head;
    }
};