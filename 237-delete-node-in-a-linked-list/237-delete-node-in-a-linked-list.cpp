/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode *next = node->next;
    
        while(next) {
            node->val = next->val;
            if(next->next) node = node->next;
            next = next->next;
        }

        node->next = NULL;
        
        // // OR:
        // ListNode* next = node->next;
        // *node = *next; // Assigning given node the value of its next node and then delete its next node.
        // delete next;
    }
};