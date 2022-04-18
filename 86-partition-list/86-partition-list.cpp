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
    ListNode* partition(ListNode* head, int x) {
        
        if(!head || !head->next) return head;
        
        ListNode* lessThanX = new ListNode(0);
        ListNode* t1 = lessThanX;
        ListNode* greaterThanX = new ListNode(0);
        ListNode* t2 = greaterThanX;
        
        while(head) {
            
            if(head->val >= x) {
                t2->next = head;
                t2 = t2->next;
            }
            else {
                t1->next = head;
                t1 = t1->next;
            }
            
            head = head->next;
        }
        
        t2->next = NULL;
        t1->next = greaterThanX->next;
        return lessThanX->next;
    }
};