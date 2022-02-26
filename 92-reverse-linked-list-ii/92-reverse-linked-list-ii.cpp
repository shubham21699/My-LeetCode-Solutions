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
    ListNode* reverse(ListNode* leftNode) {
        
        ListNode* current = leftNode;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        
        while(current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head || !head->next || right==1 || left==right) return head;
        
        if(left == 1) {
            ListNode* temp = head;
            int i = 1;
            while(temp && i != right) {
                temp = temp->next;
                i++;
            }
            
            ListNode* rightNode = temp->next;
            temp->next = NULL;
            head = reverse(head);
            
            ListNode* t = head;
            while(t->next) t = t->next;
            t->next = rightNode;
            
            return head;
        }
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        int i = 1;
        
        while(temp && i != left) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        
        ListNode* leftNode = temp;
        
        while(temp && i != right) {
            temp = temp->next;
            i++;
        }
        
        ListNode* rightNode = temp->next;
        ListNode* t = temp;
        temp->next = NULL;
        
        if(prev) prev->next = reverse(leftNode);
        t = head;
        while(t->next) t = t->next;
        t->next = rightNode;
        
        return head;
    }
};