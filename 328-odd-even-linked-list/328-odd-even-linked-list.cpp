class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head) return NULL;
        if(!head->next) return head;
        
        ListNode* t1 = head;
        ListNode* even = head->next;
        ListNode* t2 = even;
        
        while(t2 && t2->next) {
            t1->next = t1->next->next;
            t2->next = t2->next->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        
        t1->next = even;
        return head;
    }
};