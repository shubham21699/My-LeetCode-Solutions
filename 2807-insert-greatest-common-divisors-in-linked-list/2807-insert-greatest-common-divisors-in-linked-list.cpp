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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode* curr = head;
        ListNode* currNext = curr->next;
        
        while(currNext) {
            
            int gcdVal = gcd(curr->val, currNext->val);
            ListNode* newNode = new ListNode(gcdVal);
            
            newNode->next = currNext;
            curr->next = newNode;
            
            curr = curr->next->next;
            currNext = currNext->next;
        }
        
        return head;
    }
};