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
    ListNode* swap(ListNode* head) {
        
        // If there are odd number of nodes and currently we are on last node, 
        // then return as no swapping is possible in this case.
        if(!head->next) return head;
        
        ListNode* nextPairHead = NULL;
        if(head->next->next) nextPairHead = head->next->next;
        
        ListNode* next = head->next;
        ListNode* prev = head;
        next->next = prev;
        prev->next = NULL;
        
        // If next pair is available that can be swapped, then recur to that pair.
        if(nextPairHead) prev->next = swap(nextPairHead);
        return next;
    }
    
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head) return NULL;
        if(!head->next) return head;
        
        return swap(head);
    }
};