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
    ListNode* reverse(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
         
        while(current) {
            
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            
        }
        
        return prev;
    }
    
public:
    void reorderList(ListNode* head) {
        
        if(!head || !head->next || !head->next->next) return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* rev = slow->next;
        slow->next = NULL;
        
        ListNode* temp1 = head;
        ListNode* temp2 = reverse(rev);
        ListNode* newNode = new ListNode(0);
        ListNode* temp = newNode;
        
        while(temp1 || temp2) {
            
            if(temp1) {
                temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;
            }
            
            if(temp2) {
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
            }
            
        }
        
        head = newNode->next;
    }
};