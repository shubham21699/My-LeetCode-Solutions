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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
               
        if(!head) return NULL;
        if(!head->next && n==1) return NULL;
        
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        
        len = len-n;
        
        if(len == 0) return head->next;
        
        temp = head;
        
        while(temp && len>1) {
            temp = temp->next;
            len--;
        }
        
        if(temp->next->next) temp->next = temp->next->next;
        else temp->next = NULL;
        
        return head;
    }
};