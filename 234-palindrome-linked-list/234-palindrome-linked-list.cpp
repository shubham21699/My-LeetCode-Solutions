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
    ListNode* clone(ListNode* root) {
        
        if(!root) return NULL;
        
        ListNode* temp = new ListNode(root->val);
        temp->next = clone(root->next);
        return temp;
    }
    
    ListNode* reverse(ListNode* head) {
        
        ListNode* next = NULL;
        ListNode* prev = NULL;
        
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next) return true;
        
        stack<ListNode* > s;
        ListNode* temp = head;
        
        while(temp) {
            s.push(temp);
            temp = temp->next;
        }
        
        while(!s.empty()) {
            if(head->val != s.top()->val) return false;
            head = head->next;
            s.pop();
        }
        
        return true;
        
//         OR: Too Slow and heavy memory usage 
//         ListNode* temp = head;
//         temp = clone(temp);
//         ListNode* revList = reverse(temp);
        
//         while(head && revList) {
//             if(head->val != revList->val) return false;
//             head = head->next;
//             revList = revList->next;
//         }
        
//         return true;
    }
};