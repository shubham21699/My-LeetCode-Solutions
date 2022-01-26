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
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* right = sortList(slow->next);
        slow->next = NULL;
        ListNode* left = sortList(head);
        
        // Create New List
        ListNode* result = new ListNode();
        ListNode* temp = result;
        
        while(left && right) {
            if(left->val < right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        
        if(left) temp->next = left;
        else temp->next = right;
        
        return result->next;
        
        
//         OR:
//         priority_queue<int, vector<int>, greater<int> > pq;
//         ListNode* temp = head;
        
//         while(temp) {
//             pq.push(temp->val);
//             temp = temp->next;
//         }
        
//         temp = head;
//         while(temp) {
//             temp->val = pq.top();
//             pq.pop();
//             temp = temp->next;
//         }
        
//         return head;
    }
};