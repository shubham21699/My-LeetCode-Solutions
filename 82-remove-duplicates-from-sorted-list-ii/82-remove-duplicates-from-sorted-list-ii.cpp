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
        
        if(!head || !head->next) return head;
        
        ListNode* next = head->next;
        int duplicate_val = head->val;
        
        if(next->val != duplicate_val) {
            head->next = deleteDuplicates(next);
            return head;
        }
        // Else
        while(next && next->val == duplicate_val) next = next->next;
        return deleteDuplicates(next);
        
//         OR: Using HashMap
//         ListNode* temp = head;
//         unordered_map<int, int> mp;
        
//         while(temp) {
//             mp[temp->val]++;
//             temp = temp->next;
//         }
        
//         while(head && mp[head->val] > 1) {
//             head = head->next;
//         }
        
//         if(!head || !head->next) return head;
        
//         ListNode* prev = head;
//         temp = head->next;
        
//         while(temp) {
//             while(temp && mp[temp->val] > 1) temp = temp->next;
//             prev->next = temp;
//             prev = prev->next;
//             if(temp) temp = temp->next;
//         }
        
//         return head;
    }
};